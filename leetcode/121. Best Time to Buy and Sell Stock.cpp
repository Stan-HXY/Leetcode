#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
You are given an array prices where prices[i] 
is the price of a given stock on the ith day.

You want to maximize your profit by choosing a 
single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from 
this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int res = 0;      
        int i = 1; int j = 0;

        for(i; i < n; ++i){
            if(prices[i] <= prices[j]){
                j = i;
            }
            else{
                res = max(res, prices[i] - prices[j]);
            }
        }
        return res;
    }
};