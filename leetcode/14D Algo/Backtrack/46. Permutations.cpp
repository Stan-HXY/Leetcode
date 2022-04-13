#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/


class practice{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res(0);
        Backtrack(nums, 0, res);
        return res;

    }

    void Backtrack(vector<int>& nums, int left, vector<vector<int>>& res){
        if(left == nums.size() - 1){
            res.push_back(nums);     
            return;
        }
        for(int i = left; i < nums.size(); ++i){
            swap(nums[left], nums[i]);
            Backtrack(nums, left + 1, res);
            swap(nums[left], nums[i]);
        } 
        return;
    }
};











// ===================== BackTracking & Swap ========================
class Solution {
public:
    void BackTrack(vector<int>& nums,int l,int r,vector<vector<int>>&ans){
        if(l==r){
            ans.push_back(nums);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            BackTrack(nums,l+1,r,ans);
            swap(nums[l],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        BackTrack(nums,0,nums.size()-1,ans);
        return ans;
    }
};


// ===================== BackTracking & Hash ========================
class Solution1 {
public:
    vector<vector<int>> ans;

    void backTrack(vector<int>& nums, vector<int> curr, int size, unordered_set<int> visited){
        if(curr.size() == size){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < size; ++i){
            if(visited.find(nums[i]) == visited.end()){
                visited.emplace(nums[i]);
                curr.push_back(nums[i]);
                backTrack(nums, curr, size, visited);
                curr.pop_back();
                visited.erase(nums[i]);
            }           
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<int> curr;
        unordered_set<int> visited;
        backTrack(nums, curr, size, visited);
        return ans;
    }
};