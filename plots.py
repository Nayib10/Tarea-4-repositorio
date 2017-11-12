#para graficar
import matplotlib.pyplot as plt
import numpy as np

n1=genfromtxt("ExtremosFijos.dat")
#Long cuerda 0.64
e=np.linspace(0,0.64,129)
plt.plot(e, n1)
plt.show()
