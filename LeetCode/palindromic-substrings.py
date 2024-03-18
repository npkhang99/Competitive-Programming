# https://leetcode.com/problems/palindromic-substrings/description/
class Solution:
    def countSubstrings(self, s: str) -> int:
        if len(s) == 1:
            return 1

        dp = [[False] * len(s) for _ in range(len(s) + 1)]
        for i in range(len(s)):
            dp[0][i] = dp[1][i] = True

        for length in range(2, len(s) + 1):
            for end_pos in range(length - 1, len(s)):
                dp[length][end_pos] = dp[length - 2][end_pos - 1] and s[end_pos - length + 1] == s[end_pos]

        ans = 0
        for row in dp[1:]:
            ans += row.count(True)

        return ans
