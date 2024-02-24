# https://leetcode.com/problems/combination-sum/description/
from typing import List


class Solution:
    def findCombinations(self, candidates: List[int], left: int, p: int, current: List[int], ans: List[List[int]]) -> None:
        if p == len(candidates) or left < 0:
            return

        if left == 0:
            ans.append(list(current))
            return

        for i in range(p, len(candidates)):
            current.append(candidates[i])
            self.findCombinations(candidates, left - candidates[i], i, current, ans)
            current.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans: List[List[int]] = []
        self.findCombinations(candidates, target, 0, [], ans)
        return ans
