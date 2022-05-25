import java.util.*;

/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Input: target = 4, nums = [1,4,4]
Output: 1
*/

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE;
        int sum = 0;
        int l = 0, r = 0;
        for(r = 0; r < nums.length; ++r){
            sum += nums[r];
            while(l <= r && sum >= target){
                res = Math.min(res, r - l + 1);
                sum -= nums[l];
                ++l;
            }
        }
        return (res == Integer.MAX_VALUE)? 0 : res;
    }
}