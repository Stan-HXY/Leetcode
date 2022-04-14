#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Input: target = 4, nums = [1,4,4]
Output: 1
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int base = 0;
        int l = 0, r = 0;
        for(r; r < nums.size(); ++r){
            base += nums[r];
            while(base >= target && l <= r){
                res = min(res, r - l + 1);
                base -= nums[l];
                ++l;
            }
        }

        return (res == INT_MAX)? 0 : res; 
    }
};