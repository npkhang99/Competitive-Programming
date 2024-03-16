// https://leetcode.com/problems/house-robber/description/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        final ArrayList<List<Integer>> dp = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            dp.add(Arrays.asList(0, 0));
        }

        dp.get(0).set(1, nums[0]);
        dp.get(1).set(0, nums[0]);
        dp.get(1).set(1, nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp.get(i).set(0, Math.max(dp.get(i - 1).get(0), dp.get(i - 1).get(1)));
            dp.get(i).set(1, Math.max(dp.get(i - 2).get(0), dp.get(i - 2).get(1)) + nums[i]);
        }

        int ans = 0;
        for (List<Integer> list : dp) {
            ans = Math.max(ans, Math.max(list.get(0), list.get(1)));
        }
        return ans;
    }
}
