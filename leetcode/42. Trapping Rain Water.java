/*
https://leetcode.com/problems/trapping-rain-water/


        #
    #   ## #
  # ## ######


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6



*/









class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if(n < 3) return 0;
        int res = 0;
        int l = 0, r = n - 1;
        int maxL = 0, maxR = 0;
        int i = maxL;
        while(l <= r){
            maxL = Math.max(maxL, height[l]);
            maxR = Math.max(maxR, height[r]);
            int curr_ht = Math.min(maxL, maxR);
            int curr_res = curr_ht - height[i];
            if(curr_res > 0){
                res += curr_res;
            }
            if(maxL <= maxR){
                i = ++l;
            }
            else{
                i = ++r;
            }
        }
        return res;
    }
}