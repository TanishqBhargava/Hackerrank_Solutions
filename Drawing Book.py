#!/bin/python

import sys
n = int(raw_input().strip())
p = int(raw_input().strip())

print min(p/2,n/2-p/2)
