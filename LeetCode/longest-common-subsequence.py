# https://leetcode.com/problems/longest-common-subsequence/description/
class Solution:
    def lcs(self, s: str, t: str, i: int, j: int) -> int:
        if i < 0 or j < 0:
            return 0

        if self.memoization[i][j] != -1:
            return self.memoization[i][j]

        if s[i] == t[j]:
            self.memoization[i][j] = 1 + self.lcs(s, t, i - 1, j - 1)
        else:
            self.memoization[i][j] = max(self.lcs(s, t, i - 1, j), self.lcs(s, t, i, j - 1))

        return self.memoization[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        self.memoization = [[-1] * len(text2) for _ in range(len(text1))]
        return self.lcs(text1, text2, len(text1) - 1, len(text2) - 1)
