function False_position=False_position()
% Define function

  function y=f(x)
    y=x.^2+x-1;
  end

 % Initial interval and tolerance

  a=0;
  b=1;
  r=[];
  i=0;
  tol=1e-6;
  while (b-a)/2>tol
    % formula of False-Position
    c=(a.*f(b)-b.*f(a))/(f(b)-f(a));
    r=[r; c];
    if f(c)==0
      break;
    % Updating interval
    elseif f(a)*f(c)>0
      a=c;
    else
      b=c;
    end
    i=i+1;
  end

  % Display the results
  
  fprintf("The Number of iteration required is: %d\n",i);
  fprintf("The root is :\n");
  disp(r(end));

% Ploting function and iteration roots

  x=linspace(-5,5,100);
  y=f(x);
  
  figure;
  plot(x,y);
  hold on;
  plot(r,f(r),'rx');
  hold off;
  xlabel('X');
  ylabel('F(X)');
  title('False_Position methid');
  legend('f(x)=x^2+x-1','Root');
  grid on;
    
endfunction
