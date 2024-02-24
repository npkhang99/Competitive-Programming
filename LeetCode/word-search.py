# https://leetcode.com/problems/word-search/description/
from typing import List


class Solution:
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    def find(self, board: List[List[str]], visited: List[List[bool]], word: str, i: int, j: int, n: int, m: int, p: int) -> bool:
        if p == len(word):
            return True

        visited[i][j] = True
        for d in range(len(self.dx)):
            new_i, new_j = i + self.dx[d], j + self.dy[d]
            if 0 <= new_i < n and 0 <= new_j < m and not visited[new_i][new_j] and board[new_i][new_j] == word[p] and self.find(board, visited, word, new_i, new_j, n, m, p + 1):
                return True

        visited[i][j] = False
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])
        visited = [[False] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0] and self.find(board, visited, word, i, j, n, m, 1):
                    return True
        return False
