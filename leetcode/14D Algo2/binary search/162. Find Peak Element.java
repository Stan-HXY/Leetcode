import java.util.*;

/*
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

class Solution {

    public int findPeakElement(int[] nums) {
        if(nums.length == 1) return 0;
        int n = nums.length;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;

        int l = 1, r = n - 2;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid + 1] < nums[mid] && nums[mid] > nums[mid  - 1]){
                return mid;
            }
            else if(nums[mid - 1] > nums[mid]){
                r = mid - 1;
            }
            else if(nums[mid + 1] > nums[mid]){
                l = mid + 1;
            }
        }
        return -1;
    }
}