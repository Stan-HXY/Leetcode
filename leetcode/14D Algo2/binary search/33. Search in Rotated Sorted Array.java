import java.util.*;


/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/


class Solution {


    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while(l <= r){
            int mid = (l + r)/2;
            int mvalue = nums[mid];
            if(mvalue == target) return mid;

            else if(mvalue < target){
                if(mvalue <= nums[l]){
                    if(nums[r] < target){
                        r = mid - 1;
                    }
                    else{ // nums[r] > target
                        l = mid + 1;
                    }
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(mvalue >= nums[r]){
                    if(nums[r] < target){
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                else{
                    r = mid - 1;
                }    
            }
        }
        return -1;
    }
}