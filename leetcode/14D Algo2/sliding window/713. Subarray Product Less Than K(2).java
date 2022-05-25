import java.util.*;

/*
Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where the 
product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8

The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        // valid string 长度每增加1， continous组合多出 r - l + 1
        int prod = 1;
        int res = 0;
        int l = 0, r = 0;
        while(r < nums.length){
            prod *= nums[r];
            while(l <= r && prod >= k){
                prod /= nums[l];
                ++l;
            }
            res += (r - l) + 1;
            ++r;
        }
        return res;
    }
}

