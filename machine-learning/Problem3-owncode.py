#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 29 15:22:53 2021

Jeremy Zhang @Johns Hopkins university
"""
# This file is developped with my own code

import pandas as pd

import numpy as np

import scipy.spatial as spt

from collections import Counter

import matplotlib.pyplot as plt

# import dataframe from given .csv data
ESL_data=pd.read_csv(
    r'/home/adamszhang/Documents/Statistical Learning-HW/HW3/ESLmixture.csv')

# operations to plotting
blue=ESL_data.loc[ESL_data['y'] == 0]

oran=ESL_data.loc[ESL_data['y'] == 1]

blue_x = blue['x.1'].values.tolist()

blue_y = blue['x.2'].values.tolist()

oran_x = oran['x.1'].values.tolist()

oran_y = oran['x.2'].values.tolist()


# Inplement k-NN by my own code:
# Define a k-NN class
class k_nn:
    
    def __init__(self,k):
        
        self.k = k
                
    def prediction(self, testset_x, trainset_x, trainset_y):
        
        result = []
        
        test_range = len(testset_x)
        
        train_range = len(trainset_x)
                
        for i in range(test_range):
            
            distset = []; votes = []
            
            for j in range(train_range):
                
                EU_distance = spt.distance.euclidean(
                    trainset_x[j], testset_x[i])
                
                distset.append([EU_distance, j])
            
            distset.sort()
            
            distset = distset[0: self.k]
            
            for distset, j in distset:
                
                votes.append(trainset_y[j])
                
            temp_result = Counter(votes).most_common(1)[0][0]
            
            result.append(temp_result)
            
        return result


# Prepare the train and test data
x1 = ESL_data['x.1'].values.tolist()

x2 = ESL_data['x.2'].values.tolist()

temp = np.vstack((x1,x2))

traindata_x = temp.transpose()

train_lable = ESL_data['y'].values.tolist()

# Create Test Set, the gap between two points are 0.2

x1_size = 41

x2_size = 26

X1_test = np.linspace(-3, 5, x1_size)

X2_test = np.linspace(-2, 3, x2_size)

X_test= np.zeros((x1_size*x2_size,2))

K_list = [1, 15]

for item in K_list:
    
    fig = plt.figure()
    
    # visualize these two classes
    plt.scatter(blue_x, blue_y, marker='o', color = '#87ceeb')
    
    plt.scatter(oran_x, oran_y, marker='x', color = '#ff8000')
    
    for i in range(x1_size):
    
        for j in range(x2_size):
        
            X_test[i*x2_size+j][0] = X1_test[i]
        
            X_test[i*x2_size+j][1] = X2_test[j]  

    clf = k_nn(item)

    perdict = clf.prediction(X_test, traindata_x, train_lable)

    X1_blue_test = []

    X2_blue_test = []

    X1_oran_test = []

    X2_oran_test = []

    for i in range(len(perdict)):
    
        if perdict[i] == 0:
        
            X1_blue_test.append(X_test[i][0])
        
            X2_blue_test.append(X_test[i][1])
        
        else:
        
            X1_oran_test.append(X_test[i][0])
            
            X2_oran_test.append(X_test[i][1])  
            
    plt.scatter(X1_blue_test, X2_blue_test,
            marker='o', color = '#87ceeb',s=1)
           
    plt.scatter(X1_oran_test, X2_oran_test,
            marker='x', color = '#ff8000',s=1)            

    plt.title('Own code used, k = ' + str(item))
    
    plt.xlim(-3, 4)

    plt.ylim(-2, 3)
    




