#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    // Q: f(x) = x^4-8x^3-35x^2+450x-1001
    return pow(x, 4) - 8 * pow(x, 3) - 35 * pow(x, 2) + 450 * x - 1001;
}

double df(double x) {
    // Derivative f'(x) = 4x^3-24x^2-70x+450
    return 4 * pow(x, 3) - 24 * pow(x, 2) - 70 * x + 450;
}

// Newton-Raphson Method implementation

void newton_raphson(double x0,double x_true, double tol = 1e-6, int max_iter = 100) {
    double x1,ae = 100.0, te; // ae=approx error,te=true error.
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\t x0\t\t x1\t\t f(x1)\t\t Approx. Error (%)\t True Error (%)\n";

    while (iteration < max_iter) {
        x1 = x0 - f(x0) / df(x0);
        ae = fabs((x1 - x0) / x1) * 100;                 
        te = fabs((x_true - x1) / x_true) * 100;
        cout << iteration + 1 << "\t" << x0 << "\t" << x1 << "\t" << f(x1) << "\t" << ae << "\t\t" << te << endl;

        // Check for convergence
      
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "\nApproximate root: " << x1 << " after " << iteration << " iterations.\n";
    cout << "f(root) :" << f(x1) << endl;
    cout << "Total Iterations: " << iteration + 1 << endl;

}

int main() {
    double x0 = 6.0;
    double x_true = 5.6097889609;

    cout << "Given f(x) = x^4 - 8x^3 - 35x^2 + 450x - 1001\n";
    cout << "Initial guess x0 = " << x0 << endl << endl;

    newton_raphson(x0, x_true);

}
