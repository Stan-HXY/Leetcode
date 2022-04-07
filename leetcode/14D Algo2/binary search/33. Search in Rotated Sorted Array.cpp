#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
here is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown 
pivot index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the 
index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            cout << "l:" << l << " mid:" << mid << " r:" << r << endl;
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target){
                if(nums[r] == target) return r;
                if(nums[r] < target){
                    if(nums[r] < nums[mid]){
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }        
                }
                else{
                    l = mid + 1;
                }
            }
            else{// nums[mid] > target
                if(nums[l] == target) return l;
                if(nums[l] > target){
                    if(nums[l] > nums[mid]){
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
};