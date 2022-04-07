#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    int findBound(vector<int>& nums, int tar, bool lower){
        int l = 0; int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] < tar){
                l = mid + 1;
            }
            if(nums[mid] > tar){
                r = mid - 1;
            }
            if(nums[mid] == tar){
                // search for lower bound =======
                if(lower){
                    if(mid == l || nums[mid - 1] != tar){
                        return mid;
                    }
                    r = mid - 1;
                }
                // search for upper bound =======
                if(lower == false){
                    if(mid == r || nums[mid + 1] != tar){
                        return mid;
                    }
                    l = mid + 1;
                }  
            }
        }
        return -1;
    }    

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findBound(nums, target, true);
        if(l == -1){
            return {-1, -1};
        }
        int r = findBound(nums, target, false);
        return {l, r};
    }
};