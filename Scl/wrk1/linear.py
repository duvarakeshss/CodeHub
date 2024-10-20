import numpy as np
import matplotlib.pyplot as plt

def langrange_interpolation(x_values , y_values , x):
    
    n = len(x_values)
    ipv = 0
    
    for i in range(n):
        term = y_values[i]
        
        for j in range(n):
            if i != j :
                term = term * (x - x_values[j]) / (x_values[i] - x_values[j])
        
        ipv += term
    return ipv

x_values = [1.2, 2.1, 2.8, 4.1, 4.9, 6.2]
y_values = [4.2, 6.8, 9.8, 13.4, 15.5, 19.6]
x = 3.55
result = langrange_interpolation(x_values,y_values,3.55)

x_plot = np.linspace(min(x_values), max(x_values),100)
y_plot = [langrange_interpolation(x_values,y_values,i) for i in x_plot]

plt.figure(figsize=(10, 6))
plt.plot(x_values,y_values,'ro',label = "known")
plt.plot(x_plot,y_plot,'b-',label = "langrange")
plt.plot(x,result,'go' , label = 'ipv')
plt.title("ipv")
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.grid()
plt.show()
