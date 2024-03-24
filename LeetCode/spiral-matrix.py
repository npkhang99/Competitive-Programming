# https://leetcode.com/problems/spiral-matrix/description/
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        m = len(matrix[0])

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        i, j = 0, 0

        order = []
        layer = 0
        while len(order) < n * m:
            order.append(matrix[i][j])

            for _ in range(m - 1 - 2*layer):
                i, j = i + dx[0], j + dy[0]
                order.append(matrix[i][j])

            if len(order) == n * m:
                break

            for _ in range(n - 1 - 2*layer):
                i, j = i + dx[1], j + dy[1]
                order.append(matrix[i][j])

            if len(order) == n * m:
                break

            for _ in range(m - 1 - 2*layer):
                i, j = i + dx[2], j + dy[2]
                order.append(matrix[i][j])

            if len(order) == n * m:
                break

            for _ in range(n - 1 - 2*layer - 1):
                i, j = i + dx[3], j + dy[3]
                order.append(matrix[i][j])

            layer += 1
            i, j = layer, layer

        return order
