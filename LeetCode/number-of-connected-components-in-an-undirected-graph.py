# https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
from typing import List
from queue import Queue


class Solution:
    def bfs(self, s: int, adj_list: List[List[int]], visited: List[bool]) -> None:
        q = Queue()
        q.put(s)
        visited[s] = True
        while not q.empty():
            u = q.get()
            for v in adj_list[u]:
                if not visited[v]:
                    q.put(v)
                    visited[v] = True

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_list: List[List[int]] = [[] for _ in range(n)]
        for (u, v) in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        component_cnt = 0
        visited = [False] * n
        for i in range(n):
            if not visited[i]:
                component_cnt += 1
                self.bfs(i, adj_list, visited)

        return component_cnt
