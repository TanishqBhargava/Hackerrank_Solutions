#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    for _ in range(int(input())):
        n=(int(input()))
        if n==1:
            print('Kitty')
        elif n%2==0:
            print("Kitty")
        else:
            print('Katty')
