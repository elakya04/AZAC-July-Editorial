#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solution' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY links
#  2. INTEGER n
#

def solution(links,n) -> int:
    # Create adjacency list
    adj = [[] for _ in range(n)]
    for u, v in links:
        # Add v to u's list (outgoing edge)
        adj[u].append(v)
        # Add -u to v's list (incoming edge)
        adj[v].append(-u)
    
    visited = [False] * n
    count = 0
    
    def dfs(curr):
        nonlocal count
        # Mark current city as visited
        visited[curr] = True
        
        for neighbor in adj[curr]:
            if not visited[abs(neighbor)]:
                # If neighbor is positive, we need to reverse the edge
                if neighbor > 0:
                    count += 1
                # Recursive call for the neighboring city
                dfs(abs(neighbor))
    
    # Start DFS from the capital city (0)
    dfs(0)
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    links = []

    for _ in range(n - 1):
        links.append(list(map(int, input().rstrip().split())))

    ans = solution(links, n)

    fptr.write(str(ans) + '\n')

    fptr.close()
