// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/
public class Solution
{
    public int LargestCombination(int[] candidates)
    {
        var ans = 1;
        for (var i = 0; i < 31; i++)
        {
            var count = 0;
            foreach (var candidate in candidates)
            {
                count += candidate >> i & 1;
            }

            ans = Math.Max(ans, count);
        }

        return ans;
    }
}
