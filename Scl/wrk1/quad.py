import numpy as np
import matplotlib.pyplot as plt

def quadratic(x_values,y_values,x):
    n = len(x_values)
    if n != 3:
        raise ValueError("exactly 3 points requred")
    
    x0 , x1 , x2 = x_values
    y0 , y1 , y2 = y_values
    
    L0 = ((x - x1) * (x - x2)) / ((x0 - x1) * (x0 - x2))
    L1 = ((x - x0) * (x - x2)) / ((x1 - x0) * (x1 - x2))
    L2 = ((x - x0) * (x - x1)) / ((x2 - x0) * (x2 - x1))
    
    return (y0*L0 + y1*L1 + y2*L2)

x_values = [0, 2, 3]
y_values = [659, 705, 729]


x = 2.75
result = quadratic(x_values, y_values, x)
print(result)

coeff = np.polyfit(x_values,y_values,2)
print(f"{coeff[0]:.2f}x^2 + {coeff[1]:.2f}x + {coeff[2]:.2f}")

x_plot = np.linspace(min(x_values) , max(x_values) , 100)
y_plot = np.polyval(coeff , x_plot)

plt.scatter(x_values , y_values , color = 'red' , label = "given points")
plt.plot(x_plot , y_plot , color = "blue" , label = "interpolated")
plt.scatter([x],[result] , color = "green")
plt.title("Quadratic Interpolation")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.legend()
plt.grid(True)
plt.show()
