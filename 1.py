#!/usr/bin/env python
import sys

N=1000

def main(argv):
  sum = 0
  for x in range(1,N):
    if (x%3 == 0 or x%5 == 0): sum+=x
  print sum

if __name__ == '__main__':
  sys.exit(main(sys.argv))
