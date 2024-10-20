import numpy as np
import matplotlib.pyplot as plt

def langrange_interpolation(x_values , y_values , y):
    
    n = len(x_values)
    ipv = 0
    
    for i in range(n):
        term = x_values[i]
        
        for j in range(n):
            if i != j :
                term = term * (y - y_values[j]) / (y_values[i] - y_values[j])
        
        ipv += term
    return ipv

x_values = [1.2, 2.1, 2.8, 4.1, 4.9, 6.2]
y_values = [4.2, 6.8, 9.8, 13.4, 15.5, 19.6]
y = 12
result = langrange_interpolation(x_values,y_values,y)
print(result)

y_plot = np.linspace(min(y_values), max(y_values),100)
x_plot = [langrange_interpolation(x_values,y_values,i) for i in y_plot]

plt.figure(figsize=(10, 6))
plt.plot(x_values,y_values,'ro',label = "known")
plt.plot(x_plot,y_plot,'b-',label = "langrange")
plt.plot(result,y,'go' , label = 'ipv')
plt.title("ipv")
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.grid()
plt.show()
