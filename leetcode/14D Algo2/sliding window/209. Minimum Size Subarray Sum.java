
class Solution {


    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE;
        int base = 0;
        int l = 0;
        for(int r = 0; r < nums.length; ++r){
            base += nums[r];
            while(base >= target && l <= r){
                res = Math.min(res, r - l + 1);
                base -= nums[l++];
            }
        }
        return res;
    }
}