import java.util.*;

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/


class Solution {

    // =========== 2 times binary search ===========
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        int l = 0, r = nums.length - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(target == nums[mid]){
                if(mid - 1 >= 0 && nums[mid - 1] < target) {
                    res[0] = mid;
                    break;
                }
                else r = mid - 1;
            }
            else if(target > nums[mid]){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        l = 0; r = nums.length - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(target == nums[mid]){
                if(mid + 1 < nums.length && nums[mid + 1] > target) {
                    res[1] = mid;
                    break;
                }
                else l = mid;
            }
            else if(target > nums[mid]){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
}