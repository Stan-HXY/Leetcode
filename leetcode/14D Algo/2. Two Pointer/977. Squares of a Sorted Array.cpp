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
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size() - 1;
        int l = 0; int r = size;
        vector<int> res(size + 1, 0);
        int i = size;
        while(l <= r){
            if(abs(nums[l]) > abs(nums[r])){
                res[i] = nums[l] * nums[l];
                l += 1;
            }
            else{
                res[i] = nums[r]*nums[r];
                r -= 1;
            }
            --i;
        }
        return res;
    }
};