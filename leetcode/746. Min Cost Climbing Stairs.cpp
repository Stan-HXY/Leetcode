#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
Return the minimum cost to reach the top of the floor.

You can either start from the step with index 0, or the step with index 1.

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
*/


// ======================= Dynamic programming ==============================
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        if(cost.size() < 2) return min(cost[0], cost[1]);
        int n = cost.size();
        cost.emplace_back(0); 
        vector<int> stepCost(n+1);  // stepCost 记录了走到【每步】所需得最小cost
        stepCost[0] = cost[0]; stepCost[1] = cost[1];
        for(int i = 2; i < n + 1; ++i){
            //最小cost为当前cost[i] + 到 i 之前最小的一种走法
            stepCost[i] = cost[i] + min(stepCost[i-1], stepCost[i-2]);
        }
        return stepCost[n];
    }

// ================== optimized version =======================
    int minCostClimbingStairs_2(vector<int>& cost){

        int n = cost.size();
        vector<int> stepCost(n);  // stepCost 记录了走到【每步】所需得最小cost

        stepCost[0] = cost[0]; stepCost[1] = cost[1];

        for(int i = 2; i < n; ++i){
            //最小cost为当前cost[i] + 到 i 之前最小的一种走法
            stepCost[i] = cost[i] + min(stepCost[i-1], stepCost[i-2]);
        }
        return ( stepCost[n-1] < stepCost[n-2] )? stepCost[n-1] : stepCost[n-2];
    }

};






// ============== failed on [0, 2, 2, 1] =========================
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        cost.emplace_back(0);
        int sum = 0;
        while(n - 2 >= 0){
            // sum += min(cost[n-1], cost[n-2]);
            n =  (cost[n-1] < cost[n-2])? n-1 : n-2;
            sum += cost[n];
        }
        return sum;
    }
};