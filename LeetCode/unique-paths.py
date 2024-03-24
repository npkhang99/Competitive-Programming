# https://leetcode.com/problems/unique-paths/description/
class Solution:
    def count_path(self, n: int, m: int) -> int:
        if n < 0 or m < 0:
            return 0

        if n == 0 and m == 0:
            return 1

        if self.memoization[n][m] != -1:
            return self.memoization[n][m]

        self.memoization[n][m] = self.count_path(n - 1, m) + self.count_path(n, m - 1)
        return self.memoization[n][m]

    def uniquePaths(self, n: int, m: int) -> int:
        self.memoization = [[-1] * m for _ in range(n)]
        return self.count_path(n - 1, m - 1)
