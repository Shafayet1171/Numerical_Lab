function matrix=Matrix_01()

  //Taking Input

  A=input("Enter Matrix A: ");
  B=input("Enter Matrix B: ");

  // finiding maximum value of matric A

  max_A=max((A(:)));
  fprintf("Max of A Matrix : %d\n",max_A);

  //Check matrix multiplication !!
  
  if size(A,2)==size(B,1)

  //Matrix Multiplication

    result=A*B;
    fprintf("Multiplication of A & B : \n",result);
    disp(result);
  else
  
    fprintf("A & B are not multiplicable.\n");
  end
  endfunction
