#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Number of equations
    const int n = 3;

    // Augmented matrix 
    double A[n][n+1] = {
        {25, 5, 1, 106.8},
        {64, 8, 1, 177.2},
        {144, 12, 1, 279.2}
    };

    // Forward elimination
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    // Back-substitution
    double x[n];
    for (int i = n-1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i+1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Display coefficients
    cout << fixed << setprecision(4);
    cout << "Polynomial coefficients:\n";
    cout << "a1 = " << x[0] << "\n";
    cout << "a2 = " << x[1] << "\n";
    cout << "a3 = " << x[2] << "\n";

    // Find velocity at t = 6 sec
  
    double t = 6;
    double v = x[0]*t*t + x[1]*t + x[2];
  
    cout << "Velocity at t = " << t << " sec: " << v << " m/s\n";
}
