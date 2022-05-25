import java.util.*;

/*
Input: nums = [4,5,6,7,0,1,2]
Output: 0

Input: nums = [3,4,5,1,2]
Output: 1
*/


class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
            if(mid < nums.length - 1 && nums[mid + 1] < nums[mid]) return nums[mid + 1];
            else if(nums[mid] >= nums[r]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[0];
    }
}