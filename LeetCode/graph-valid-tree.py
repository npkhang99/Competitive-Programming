# https://leetcode.com/problems/graph-valid-tree/description/
from typing import List


class Solution:
    def dfs(self, u: int, adj_list: List[List[int]], visited: List[bool], parent: int) -> bool:
        visited[u] = 1
        for v in adj_list[u]:
            if v == parent:
                continue

            if visited[v] == 1:
                return False
            if visited[v] == 0 and not self.dfs(v, adj_list, visited, u):
                return False
        visited[u] = 2
        return True

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj_list: List[List[int]] = [[] for _ in range(n)]
        for (u, v) in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        visited = [0] * n
        return self.dfs(0, adj_list, visited, -1) and visited.count(2) == n
