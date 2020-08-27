#!/bin/python3

import sys

# Input array size
n = int(input().strip())

# Input array
A = [int(A_temp) for A_temp in input().strip().split(' ')]

# Create empty dictionary to keep track of element value and its last know position in the array
d={}

# Initialize minimum difference variable as one more than the maximum value(n-1) we can achieve
min_diff = n 

# Going through each element in the array
for i in range(n):

# Try/Except statement to find record of the last known index for the element in the dictionary(for index difference calc), if unable to find the record then create the record
    try:

# min_diff equals minimum value between (the element index i and the last known location of the same element) and (min_diff)
        min_diff = min(i-d[A[i]],min_diff) 

# Change the last known position of the element
        d[A[i]]=i

# Now if min_diff has value 1 then the code doesnt need to go further as its the minimum possible value for the answer
        if min_diff == 1:
            break
    
    except:
        d[A[i]]=i

# If min_diff is the same as initialized value meaning no element in input array is repeating then print -1 else the minimum difference value
if min_diff == n:  
    print(-1)
else:
    print(min_diff)
