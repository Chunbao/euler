#!/usr/bin/env python

import operator

if __name__ == '__main__':
  with open('keylog.txt') as log:
    lines=map(str.strip, log.readlines())
  log.close()

  # unique numbers
  numbers=set()
  for i in lines:
    for j in i:
      numbers.add(j)

  # graph
  dictionary=dict()
  for num in numbers:
    dictionary[num]=set()

  for i in lines:
    for j in range(2):
      dictionary[i[j]].add(i[j+1])
    dictionary[i[0]].add(i[2])
  di=dict()
  for key in dictionary:
    di[key] = len(dictionary[key])
  di=sorted(di.items(), key=operator.itemgetter(1), reverse=True)
  for key in di:
    print key

