# https://leetcode.com/problems/top-k-frequent-elements/
from typing import List

OFFSET = 10**4


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1

        freq_list = []
        for i in range(len(counts)):
            if counts[i] > 0:
                freq_list.append((counts[i], i - OFFSET))

        return [freq for (num, freq) in sorted(freq_list, reverse=True)[:k]]
