# https://leetcode.com/problems/word-break/description/
from typing import List, Set


class Solution:
    def is_possible(self, s: str, word_set: Set[str], p: int, max_word_length: int) -> bool:
        if p == len(s):
            return True

        if self.memoization[p] != -1:
            return False if self.memoization[p] == 0 else True

        possible = False
        for i in range(p + 1, len(s) + 1):
            if i - p > max_word_length:
                break

            if s[p : i] not in word_set:
                continue

            possible = self.is_possible(s, word_set, i, max_word_length)
            if possible:
                break

        self.memoization[p] = possible
        return possible

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.memoization = [-1] * (len(s) + 1)
        word_set = set(wordDict)

        max_word_legth = 0
        for word in word_set:
            max_word_legth = max(max_word_legth, len(word))

        return self.is_possible(s, word_set, 0, max_word_legth)
