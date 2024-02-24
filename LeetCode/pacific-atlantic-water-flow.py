# https://leetcode.com/problems/pacific-atlantic-water-flow/description/
from typing import List
from queue import Queue


class Solution:
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    def explore(self, heights: List[List[int]], visited: List[List[bool]], i: int, j: int, n: int, m: int) -> None:
        if visited[i][j]:
            return

        q = Queue()
        q.put((i, j))
        visited[i][j] = True
        while not q.empty():
            (i, j) = q.get()
            for d in range(len(self.dx)):
                new_i, new_j = i + self.dx[d], j + self.dy[d]
                if 0 <= new_i < n and 0 <= new_j < m and not visited[new_i][new_j] and heights[i][j] <= heights[new_i][new_j]:
                    visited[new_i][new_j] = True
                    q.put((new_i, new_j))

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        pacific_reachable = [[False] * m for _ in range(n)]
        atlantic_reachable = [[False] * m for _ in range(n)]

        for i in range(n):
            self.explore(heights, pacific_reachable, i, 0, n, m)
            self.explore(heights, atlantic_reachable, i, m - 1, n, m)

        for j in range(m):
            self.explore(heights, pacific_reachable, 0, j, n, m)
            self.explore(heights, atlantic_reachable, n - 1, j, n, m)

        both_reachable: List[List[int]] = []
        for i in range(n):
            for j in range(m):
                if pacific_reachable[i][j] and atlantic_reachable[i][j]:
                    both_reachable.append([i, j])

        return both_reachable
