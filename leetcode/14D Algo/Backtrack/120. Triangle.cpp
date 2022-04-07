#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given a  array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move 
to either index i or index i + 1 on the next row.

Input:  = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The  looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& ) {
        int size = .size();
        if(size == 1) return [0][0];
        vector<vector<int>> dp;
        dp.push_back([0]);
        int res = dp[0][0];

        for(int i = 1; i < size; ++i){
            dp.push_back(vector<int>([i].size()));
            for(int j = 0; j < [i].size(); ++j){
                if(j == 0){
                    dp[i][j] = [i][j] + dp[i - 1][j];
                    res = dp[i][j];
                }
                else if(j == [i].size() - 1){
                    dp[i][j] = [i][j] + dp[i - 1][j - 1];
                    res = min(res, dp[j][j]);
                }
                else{
                    dp[i][j] = [i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                    res = min(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};