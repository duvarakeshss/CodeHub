import sympy as sp

x , y = sp.symbols('x y')

def f(fun , x0 , y0):
  return fun.subs({x:x0 , y:y0}).evalf()

def milne_solver(fun , initial_values , h , x_predict):
  n = len(init_values)
  y_val = [f(fun , initial_values[i][0] , initial_values[i][1])for i in range(n)]

  yp = initial_values[0][1] + (4*h/3) * (
      2 * y_val[1] -
      y_val[2] +
      2 * y_val[3]
  )

  yc = init_values[2][1] + h/3 *(
      f(fun , x_predict , yp) +
      y_val[2] +
      4 * y_val[3]
  )
  return yc

if __name__ == '__main__':
    function = 'x ** 3 + y'
    init_values = [
        [0, 2],
        [0.2, 2.073],
        [0.4, 2.452],
        [0.6, 3.023]
    ]
    
    h = 0.2  # Step size
    x_predict = 0.8  # The x value to predict y at
    function = sp.sympify(function)
    # Perform Milne's Predictor-Corrector calculation
    result = milne_solver(function, init_values, h, x_predict)
    
    # Output the result
    print(f'The Result: Y = {result} at X = {x_predict}')