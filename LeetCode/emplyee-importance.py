# https://leetcode.com/problems/roman-to-integer/
class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        value = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        for i in range(len(s)):
            ans += value[s[i]]
            if i > 0 and value[s[i - 1]] < value[s[i]]:
                ans -= 2*value[s[i - 1]]

        return ans
