#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where 
the product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int l = 0, r = 0;
        int base = 1;
        for(r; r < nums.size(); ++r){
            base *= nums[r];
            while(!(base < k) && l <= r){
                base /= nums[l];
                ++l;
            }
            res += r - l + 1;
            /* each time introduce (r - l + 1) combinations, 
               if (l > r) which current sole element > k, then res += 0
            */
        }
        return res;
    }
};