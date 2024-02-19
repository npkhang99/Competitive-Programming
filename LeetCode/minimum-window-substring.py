# https://leetcode.com/problems/minimum-window-substring/description/
import string

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_count = {c:0 for c in string.ascii_letters}
        for c in t:
            t_count[c] += 1

        # find the first solution (don't care if optimal or not)
        right = 0
        ans = ""
        s_count = {c:0 for c in string.ascii_letters}
        while right < len(s):
            s_count[s[right]] += 1
            is_ok = True
            for (c, count) in t_count.items():
                if s_count[c] < count:
                    is_ok = False
                    break
            if is_ok:
                ans = s[:right + 1]
                break
            right += 1

        # if we don't found anything then return empty
        if ans == "":
            return ans

        # find the optimal solution
        left = 0
        is_ok = True # up until now, the s[left:right+1] is a valid substring
        while right < len(s):
            # if s[left:right+1] is not valid then add the s[right + 1] into the substring
            if not is_ok:
                s_count[s[right]] += 1
                if s_count[s[right]] == t_count[s[right]]:
                    is_ok = True

            # while s[left:right+1] is valid then increase left
            while is_ok:
                if len(ans) > right - left + 1:
                    ans = s[left:right + 1]
                s_count[s[left]] -= 1
                if s_count[s[left]] < t_count[s[left]]:
                    is_ok = False
                left += 1
            
            right += 1

        return ans
