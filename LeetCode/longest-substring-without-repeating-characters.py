# https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        l = 0
        r = 0
        appeared = set()
        while r < len(s):
            while s[r] in appeared:
                appeared.remove(s[l])
                l += 1
            appeared.add(s[r])
            r += 1
            ans = max(ans, r - l)

        return ans
