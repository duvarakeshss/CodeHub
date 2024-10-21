import numpy as np
import sympy as sp

x, y = sp.symbols('x y')
function = 'y - x**2'
function = sp.simplify(function)

def f(fun , x_val , y_val):
    return fun.subs({x:x_val,y:y_val}).evalf()

def modified_euler(fun , c_x , c_y , h , x_predict , tol = 0.001):
    x0 = x_predict - h
    y0 = c_y if x_predict == h else modified_euler(fun , c_x , c_y , h , x0)
    
    y1 = y0 + h * f(fun , x0 ,y0)
    
    while True:
        y_new = y0 + h/2 * (f(fun , x0 , y0) + f(fun , x0 + h , y1))
        if abs(y1 - y_new) < tol:
            break
        y1 = y_new
    return y_new



initial_x = 0
initial_y = 1
x_predict = 0.2
h = 0.2

print(modified_euler(function , initial_x , initial_y , h , x_predict))
    