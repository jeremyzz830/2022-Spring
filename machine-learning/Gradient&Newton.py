#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 16 20:40:17 2021

Jiaming Zhang @Johns Hopkins University
"""
##Click run and the result will be shown in the console window

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#####################################################
#Plot the surface

fig1 = plt.figure()
ax1 = Axes3D(fig1)
X = np.arange(-2,2,0.01)
Y = np.arange(-2,2,0.01)
X,Y = np.meshgrid(X, Y)
Z=(100*(Y-X**2)**2+(1-X)**2)
ax1.plot_surface(X,Y,Z,rstride=1,cstride=1,cmap='rainbow')
plt.show()

fig2 = plt.figure()
c = plt.contour(X, Y, Z, [100,600,1200], colors='black')

#####################################################
#Apply to different method

range_of_x = 1.5
gap = 200
X1 = np.linspace(-range_of_x, range_of_x, gap)
X2 = np.linspace(-range_of_x, range_of_x, gap)

##Define necessary funtion, gradient, hessian and delta vector
def f(X1, X2):
    return 100 * (X2 - X1 * X1) ** 2 + (1 - X1) ** 2 

def Hessian(X1, X2):
    return np.matrix([[1200 * X1 ** 2 - 400 * X2 + 2, -400 * X1],[-400 * X1, 200]])

def Gradient(X1, X2):
    return np.matrix([[2 * X1 - 2 + 400 * X1 * (X1 ** 2 - X2)],[200 * (X2 -  X1 ** 2)]])

def Delta_with_Grad(X1, X2):
    g = Gradient(X1, X2)
    alpha = 0.002
    d = alpha * g
    return d

def Delta_with_Newton(X1, X2):
    alpha = 1.0
    delta = alpha * Hessian(X1, X2).I * Gradient(X1, X2)
    return delta

###########################################################
##Gradient Descent
#Initializing parameters
X1,X2 = np.meshgrid(X1,X2)
X = np.matrix([[0.0], [0.0]])
tol = 1e-6
x1_temp = [X[0, 0]]
x2_temp = [X[1, 0]]
plt.plot(X[0, 0], X[1, 0], marker='o')
fg_temp = []


for t in range(10000):
    delta = Delta_with_Grad(X[0, 0],X[1, 0])
    if abs(delta[0, 0]) < tol and abs(delta[1, 0]) < tol:
        break

    X = X - delta
    func_value=f(X[0,0],X[1,0])
    fg_temp.append(func_value)
    x1_temp.append(X[0,0])
    x2_temp.append(X[1,0])

plt.plot(X[0, 0], X[1, 0], marker='o')  
plt.plot(x1_temp, x2_temp, label='TRACE FOR GRADIENT DESCENT')   
note=str(len(x1_temp)-1)
plt.text(-1,-1.75,'Gradient Descent takes:'+note+'steps')
print('\nFor gradient descent: ')
print('It takes: '+note+' steps to converge.')
print('The minimum point is: x = ('+str(X[0,0])+', '+str(X[1,0])+')')
print('The minimum function value is: f(x) = ('+str(f(X[0,0],X[1,0]))+')')
##########################################################################
##Newton's
#Initializing parameters
X = np.matrix([[0.0], [0.0]])
x1_temp = [X[0, 0]]
x2_temp = [X[1, 0]]
fn_temp = []

for t in range(100):
    delta = Delta_with_Newton(X[0, 0],X[1, 0])
    if abs(delta[0, 0]) < tol and abs(delta[1, 0]) < tol:
        break

    X = X - delta
    func_value=f(X[0,0],X[1,0])
    fn_temp.append(func_value)
    x1_temp.append(X[0,0])
    x2_temp.append(X[1,0])
    plt.plot(X[0, 0], X[1, 0], marker='o')

plt.plot(x1_temp, x2_temp, label='TRACE FOR NEWTON METHOD')
note=str(len(x1_temp)-1)
plt.text(-0.55,-1.95,'Newton takes:'+note+'steps')
################################################################
#Draw required pictures
plt.xlabel('X1')
plt.ylabel('X2')
plt.title('Contour For $100*(x2-x1^2)^2+(1-x1)^2$')
plt.legend()
plt.clabel(c, inline=True, fontsize=10)
plt.show()

fig3=plt.figure()
stepg=np.arange(0,len(fg_temp),1)
plt.plot(stepg, fg_temp)
plt.xlabel('STEP NUMBER')
plt.ylabel('FUNCTION VALUE')
plt.title('GRADIENT DDESCENT')
plt.grid(True)

fig4=plt.figure()
stepn=np.arange(0,len(fn_temp),1)
plt.plot(stepn, fn_temp)
plt.xlabel('STEP NUMBER')
plt.ylabel('FUNCTION VALUE')
plt.title('NEWTON')
plt.grid(True)

print('\nFor Newton Method: ')
print('It takes: '+note+' steps to converge.')
print('The minimum point is: x = ('+str(X[0,0])+', '+str(X[1,0])+')')
print('The minimum function value is: f(x) = ('+str(f(X[0,0],X[1,0]))+')')