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
#  1. LONG_INTEGER n
#  2. LONG_INTEGER_ARRAY play
#

def solution(n, play):
    # Write your code here
    s,e,res=0,0,1
    list1=list()
    while(s<n and e<n):
        while(e<n and play[e] not in list1):
            list1.append(play[e])
            res=max(res,e-s+1)
            e+=1
        while(e<n and play[e] in list1):
            list1.pop(0)
            s+=1
            
    p=list()
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    play = list(map(int, input().rstrip().split()))

    playlist = solution(n, play)

    fptr.write(str(playlist) + '\n')

    fptr.close()
