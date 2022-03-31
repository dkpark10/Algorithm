from collections import Counter

def solution(n, edge):
  graph = [[] for i in range(n + 1)]
  dst = [0] * (n + 1)
  visited = [False] * (n + 1)

  for v1, v2 in edge:
    graph[v1].append(v2)
    graph[v2].append(v1)

  q = []
  q.append([1,0])
  dst[1] = 0
  visited[1] = True

  while q:
    cur, cost = q[0]
    q.pop(0)

    for nextv in graph[cur]:
      if visited[nextv] == True:
        continue

      q.append([nextv, cost + 1])
      dst[nextv] = cost + 1
      visited[nextv] = True

  ans = 0
  maxdst = max(dst)
  for i in dst:
    if maxdst == i:
      ans += 1

  return ans
