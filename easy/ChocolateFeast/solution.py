i#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'chocolateFeast' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER c
#  3. INTEGER m
#

def chocolateFeast(n, c, m):
    total_chochos_eaten = int(n/c)
    wrappers_in_hand = total_chochos_eaten
    while wrappers_in_hand >= m:
        chochos_bought = int(wrappers_in_hand/m)
        wrappers_in_hand = int(wrappers_in_hand%m) + chochos_bought
        total_chochos_eaten = total_chochos_eaten + chochos_bought
        
    return total_chochos_eaten

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        c = int(first_multiple_input[1])

        m = int(first_multiple_input[2])

        result = chocolateFeast(n, c, m)

        fptr.write(str(result) + '\n')

    fptr.close()

