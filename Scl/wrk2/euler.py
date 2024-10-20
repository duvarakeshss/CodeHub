import numpy as np
import sympy as sp

def tolerate(val , digit):
    return np.round(val,digit)

def euler(fun , c_x , c_y ,final_x , h , tol = 0.01):
    x , y = sp.symbols('x y')
    fun = sp.sympify(fun)
    
    digit = int(np.log10(1/tol))
    
    while c_x < final_x :
        value = fun.subs(x,c_x).subs(y,c_y).evalf()
        new_y = c_y + h * value
        
        c_x = tolerate(c_x + h , digit)
        c_y = new_y
    return c_y

function = 'x - y + cos(x+y)'
x_predict = 1.7
result = euler(function, 0.1 ,1, x_predict,0.1)
print(f'Result : y = {result} at x = {x_predict}')