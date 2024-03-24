# https://leetcode.com/problems/rotate-image/
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Positions: (i, j) -> (j, n - 1 - i) -> (n - 1 - j, i) -> (i, j)
        """
        n = len(matrix)
        for i in range(n // 2):
            for j in range(i, n - 1 - i):
                value = matrix[i][j]

                new_i, new_j = j, n - 1 - i
                value, matrix[new_i][new_j] = matrix[new_i][new_j], value

                new_i, new_j = n - 1 - i, n - 1 - j
                value, matrix[new_i][new_j] = matrix[new_i][new_j], value

                new_i, new_j = n - 1 - j, i
                value, matrix[new_i][new_j] = matrix[new_i][new_j], value

                new_i, new_j = i, j
                matrix[new_i][new_j] = value
