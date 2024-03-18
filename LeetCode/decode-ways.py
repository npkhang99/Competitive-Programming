# https://leetcode.com/problems/decode-ways/description/
class Solution:
    __memoization = None

    def dp(self, s: str, p: int, code: str) -> int:
        if len(code) == 0 or code[0] == "0" or (len(code) == 2 and code > "26"):
            return 0

        if p < 0:
            return 1

        if self.__memoization[p] != -1:
            return self.__memoization[p]

        self.__memoization[p] = self.dp(s, p - 1, s[p]) + self.dp(s, p - 2, s[p - 1 : p + 1])
        return self.__memoization[p]


    def numDecodings(self, s: str) -> int:
        if s == "0":
            return 0

        if len(s) == 1:
            return 1

        self.__memoization = [-1] * len(s)
        return self.dp(s, len(s) - 2, s[-1]) + self.dp(s, len(s) - 3, s[-2:])
