import numpy as np
import sympy as sp

x , y = sp.symbols('x y')

function = 'x+y'
function = sp.sympify(function)

def f(fun,x0,y0):
    return fun.subs({x:x0 , y:y0}).evalf()

def rk4(fun , c_x , c_y , h , x_predict):
    x0 = c_x
    y0 = c_y
    
    while x0 < x_predict:
        
        k1 = h * f(fun , x0 , y0)
        k2 = h * f(fun , x0 + h/2 , y0 + k1/2)
        k3 = h * f(fun , x0 + h/2 , y0+k2/2)
        k4 = h * f(fun , x0 + h , y0 + k3)
        
        y0 = y0 + (1/6) * (k1 + 2*k2 + 2*k3 + k4)
        
        x0 += h
    return y0

print(rk4(function, 0 , 1 , 0.2 , 0.2))
        
