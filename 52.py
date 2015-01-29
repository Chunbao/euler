#!/usr/bin/env python

def same(a, b):
  return sorted([x for x in str(a)]) == sorted([x for x in str(b)])

def main():
  v=long(1)
  while True:
    if (same(v, 2*v) and same(v, 3*v)  and same(v, 4*v)  and same(v, 5*v) and same(v, 6*v)):
      print "Wanted: "
      print v
      print "2 3 4 5 6 times as: "
      print v*2
      print v*3
      print v*4
      print v*5
      print v*6
      break
    v=v+1

if __name__ == '__main__':
  main()
