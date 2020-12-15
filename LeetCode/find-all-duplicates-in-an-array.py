class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)

        f = [0] * (n + 1)
        for i in range(n):
            f[nums[i]] += 1

        for i in range(n + 1):
            if f[i] > 1:
                ans.append(i)

        return ans
