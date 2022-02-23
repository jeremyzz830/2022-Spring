#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 29 15:22:53 2021

Jeremy Zhang @Johns Hopkins university
"""
# This file is developped with my own code
import numpy as np

import matplotlib.pyplot as plt

# for 4.(a) part: to generate the 1-D input x, noise e and output y
x = 3 * np.random.rand(200)

e = np.random.randn(200)

y = 4 + 3 * x + e

X = np.c_[np.ones_like(x), x]

#define functions to conduct calculation
class linearreg(object):
    
    def __init__(self):
        
        self.Calc_beta = lambda X, y: np.matmul(np.linalg.inv(np.matmul(X.T, X)), np.matmul(X.T,y))
        
        self.beta = None
    
    def fit(self, X, y):
        
        self.beta = self.Calc_beta(X,y)
    
    def predict(self, X):
        
        assert self.beta.shape[0] == X.shape[1]
        
        return np.matmul(X, self.beta[:,None])
    
    def get_beta(self):
        
        return self.beta
    
LR = linearreg()

LR.fit(X , y)

xx = [0,1,2,3]

yy = LR.predict(np.c_[np.ones_like(xx), xx])

fig = plt.figure()

plt.scatter(x, y,  marker='+',c='r', label='training sample')

plt.plot(xx, yy, c='b', label='Own Regression')

plt.legend()

plt.title('Own code get beta:\n'+ str(LR.get_beta()))



