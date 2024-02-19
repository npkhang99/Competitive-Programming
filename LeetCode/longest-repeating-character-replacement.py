# https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        l = 0
        count = {}
        most_occurrence = 0
        for r in range(len(s)):
            if s[r] not in count:
                count[s[r]] = 0
            count[s[r]] += 1
            most_occurrence = max(most_occurrence, count[s[r]])
            while r - l + 1 - most_occurrence > k:
                count[s[l]] -= 1
                l += 1
                most_occurrence = max(count.values())
            ans = max(ans, r - l + 1)
        return ans
