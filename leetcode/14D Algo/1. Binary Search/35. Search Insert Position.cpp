#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the 
index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while(l < r){
            int m = (r - l)/2 + l;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        if(target > nums[l]) return l + 1;
        else return l;
    }
};

