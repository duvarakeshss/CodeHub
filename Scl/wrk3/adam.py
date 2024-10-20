import numpy as np
import sympy as sp

x , y = sp.symbols('x y')

def f(fun , x0 , y0):
  return fun.subs({x:x0,y:y0}).evalf()

def adam_solver(fun , initial_val , h , x_predict):
  n = len(initial_val)
  y_val = [f(fun , initial_val[i][0] , initial_val[i][1])for i in range(n)]


  yp = initial_val[3][1] + h/24 *(
      55 * y_val[3] -
      59 * y_val[2] +
      37 * y_val[1] -
      9 * y_val[0]
  )

  yc = initial_val[3][1] + h/24 * (
       9 * f(fun , x_predict , yp) +
      19 * y_val[3] - 
       5 * y_val[2] +
       y_val[1]
  )

  return yc

function = 'x ** 2 * (1 + y)'
init_values = [
        [1, 1],
        [1.1, 1.2333],
        [1.2, 1.548],
        [1.3, 1.979]
]
    
# Step size
h = 0.1
x_predict = 1.4
function = sp.sympify(function)
    
result = adam_solver(function, init_values, h, x_predict)
    
# Output the result
print(f'The Result: Y = {result} at X = {x_predict}')
