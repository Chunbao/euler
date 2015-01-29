#!/usr/bin/env python

_=float('inf')
N=6

def findIndex(distance, visited):
  mini=_
  min_index = _
  for v in range(N):
    if (visited[v] == False and distance[v] < mini):
      mini=distance[v]
      min_index = v
  if min_index == _: raise Exception("Unclosed graph!")
  return min_index

def dijkstra(graph,n):
  visited = [False] * N
  distance=[_] * N

  distance[n]=0
  for v in range(N):
    i = findIndex(distance, visited) #todo consider inf
    visited[i] = True
    for k in range(N):
      if (visited[k] == False
          and distance[i] != _
          and graph[i][k] != _
          and (distance[k] > distance[i] + graph[i][k] )):
        distance[k] = distance[i] + graph[i][k]
  print distance
  return distance


if __name__=='__main__':
  graph=[
            [0,6,3,_,_,_],
            [6,0,2,5,_,_],
            [3,2,0,3,4,_],
            [_,5,3,0,2,3],
            [_,_,4,2,0,5],
            [_,_,_,3,5,0],
            ]
  [dijkstra(graph, k) for k in range(N)]
