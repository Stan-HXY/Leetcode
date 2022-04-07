#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;


/*
Given an integer array nums and an integer k, return true if 
there are two distinct indices i and j in the array such that 
nums[i] == nums[j] and abs(i - j) <= k.

----- example -----
Input: nums = [1,2,3,1], k = 3
Output: true

*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); ++i){
            if( M.find(nums[i]) != M.end() ){
                if (abs(M[nums[i]] - i) <= k){
                    return true;
                }
            }
            M[nums[i]] = i;
        }
        return false;
    }
};