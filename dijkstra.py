#!/usr/bin/env python

_=float('inf')


def dijkstra(graph,n):


if __name__=='__main__':
  n=6
  graph=[
            [0,6,3,_,_,_],
            [6,0,2,5,_,_],
            [3,2,0,3,4,_],
            [_,5,3,0,2,3],
            [_,_,4,2,0,5],
            [_,_,_,3,5,0],
            ]
  dijkstra(graph,0)
