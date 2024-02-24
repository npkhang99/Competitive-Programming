# https://leetcode.com/problems/number-of-islands/description/
from typing import List
from queue import Queue


class Solution:
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    def bfs(self, grid: List[List[str]], visited: List[List[bool]], i: int, j: int, n: int, m: int) -> None:
        q = Queue()
        q.put((i, j))
        visited[i][j] = True
        while not q.empty():
            (i, j) = q.get()
            for d in range(len(self.dx)):
                new_i, new_j = i + self.dx[d], j + self.dy[d]
                if 0 <= new_i < n and 0 <= new_j < m and grid[new_i][new_j] == '1' and not visited[new_i][new_j]:
                    q.put((new_i, new_j))
                    visited[new_i][new_j] = True

    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.bfs(grid, visited, i, j, n, m)
                    ans += 1
        return ans
