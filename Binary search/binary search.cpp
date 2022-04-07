#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;

/*

Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.    

*/


// ========================= recursion =================================
class Solution {
public:

    int helper(vector<int>& nums, int target, int l, int r){
        if(target == nums[l]) return l;
        if(target == nums[r]) return r;
        if(l == r){
            if(nums[l] != target) return -1;
            else return l;
        }
        int i = -1;
        int mid = (l+r)/2;
        if(target == nums[mid]) return mid;
        if(target < nums[mid]){
            i = helper(nums, target, l, mid);           
        }
        else if(target > nums[mid]){
            i = helper(nums, target, mid+1, r);
        }
        return i;
    }

    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
};


// ========================= iteration =================================
class Solution {
public:

    int search(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        
        while(l != r){
            if(nums[l] == target) return l;
            if(nums[r] == target) return r;
            int mid = (l+r)/2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]){
                r = mid;
            }
            else if(target > nums[mid]){
                l = mid + 1;
            }    
        }
        return -1;
    }

};