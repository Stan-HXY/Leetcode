#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Given an integer n, return the least number of 
perfect square numbers that sum to n.

A perfect square is an integer that is the square 
of an integer; in other words, it is the product 
of some integer with itself. For example, 1, 4, 9, 
and 16 are perfect squares while 3 and 11 are not.

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

每个数减从1x1，2x2，的数的least square sum数量，取min，如果正好被square减为0，那说明自己就是平方，
所以dp[0] = 0
*/

class Solution {
public:
    int numSquares(int n) {
        if(n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for(int i = 1; i < n + 1; ++i){
            int upper = sqrt(i); // the limit of square number within i
            for(int k = 1; k <= upper; ++k){
                if(dp[i] == 0){
                    dp[i] = dp[i - k * k] + 1;
                }
                else{
                    dp[i] = min(dp[i], dp[i - k * k] + 1);
                }
            }
            cout << "dp[" << i << "]: " << dp[i] << endl;
        }
        return dp[n];
    }
};