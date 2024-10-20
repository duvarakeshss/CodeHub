import numpy as np
import sympy as sp

x , y = sp.symbols('x y')

function = 'x+y'
function = sp.sympify(function)

def f(fun,x0,y0):
    return fun.subs({x:x0 , y:y0}).evalf()

def rk4(fun , c_x , c_y , h , x_predict):
    x0, y0 = c_x , c_y
    
    # Calculate the Runge-Kutta terms
    k1 = h * f(function, x0, y0)
    k2 = h * f(function, x0 + h / 2, y0 + k1 / 2)
    k_prime = h * f(function, x0 + h, y0 + k1)
    k3 = h * f(function, x0 + h, y0 + k_prime)

    # Calculate the result using the third-order formula
    result = y0 + (1 / 6) * (k1 + 4 * k2 + k3)
    return result

print(rk4(function, 0 , 1 , 0.2 , 0.2))
        
