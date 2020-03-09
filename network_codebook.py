import numpy as np
from numpy import genfromtxt
import matplotlib.pyplot as plt

## Get the information from the standard weights file
weights = genfromtxt('network.dat', delimiter='\n')
weight_mean = np.average(weights)
weight_std = np.std(weights)
weight_size = weights.size

## Generate new weight file with all zeros
new_weights = np.zeros(weight_size)
np.savetxt('network_zero.dat', new_weights, fmt="%f")

## Generate new weight file will all values as the mean of the original weight network
for i in range(weight_size):
	new_weights[i] = weight_mean
np.savetxt('network_mean.dat', new_weights, fmt="%f")

## Generate new weight file with a one-bit codebook
## Values will be either +/- the standard deviation from the mean
## If the value is less than the mean, it will be (mean - sigma)
## If the value is greater than the mean, it will be (mean + sigma)
for i in range(weight_size):
	if weights[i] >= weight_mean:
		new_weights[i] = weight_mean + weight_std
	else:
		new_weights[i] = weight_mean - weight_std
np.savetxt('network_one-bit.dat', new_weights, fmt="%f")

## Plot a histogram of the original weight data
plt.hist(weights, bins=100)
plt.show()