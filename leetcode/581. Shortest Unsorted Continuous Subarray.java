import java.util.*;

/*
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order 
to make the whole array sorted in ascending order.
*/

class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int l = 0, r = nums.length - 1;
        int lmax = nums[l];
        int rmin = nums[r];
        int start = -1, end = nums.length;
        while(r >= 0){
            //--- end of left
            if(nums[l] < lmax){
                end = l;
            }
            else{
                lmax = nums[l];
            }
            // --- start of right
            if(nums[r] > rmin){
                start = r;
            }
            else{
                rmin = nums[r];
            }
            ++l; --r;
        }
        return (start == -1)? 0 : end - start + 1;
    }
}