#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one 
of the symbols '+' and '-' before each integer in nums and 
then concatenate all the integers.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/



// ------------- recursion ----------------
class Solution_1 {
public:

    int ways(int n, int i, int& target, vector<int>& nums){
        if(i == nums.size() && n == target) return 1;
        if(i == nums.size()) return 0;
        int temp = nums[i];
        return ways(n + temp, i + 1, target, nums) + ways(n - temp, i + 1, target, nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return ways(0, 0, target, nums);
    }
};