#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solution' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. LONG_INTEGER_ARRAY A
#  2. LONG_INTEGER_ARRAY B
#

def solution(A, B):
    # Write your code here
    n = len(A)  # Get the size of the arrays
    incr, decr, ops = 0, 0, 0  # Initialize variables to track increments, decrements, and operations
    
    # Iterate through each element of the arrays
    for i in range(n):
        diff = B[i] - A[i]  # Calculate the difference between corresponding elements of B and A
        
        if diff > 0:  # If the difference is positive (B[i] > A[i])
            if incr < diff:
                ops += diff - incr  # Increment operations if the required increment is more than the current
            incr = diff  # Update the increment value
            decr = 0  # Reset decrement value
        elif diff < 0:  # If the difference is negative (B[i] < A[i])
            if diff < decr:
                ops += decr - diff  # Increment operations if the required decrement is more than the current
            decr = diff  # Update the decrement value
            incr = 0  # Reset increment value
        else:
            incr = decr = 0  # Reset both increment and decrement if A[i] == B[i]
    
    return ops  # Return the total number of operations

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    A = list(map(int, input().rstrip().split()))

    B = list(map(int, input().rstrip().split()))

    ans = solution(A, B)

    fptr.write(str(ans) + '\n')

    fptr.close()
