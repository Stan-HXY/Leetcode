#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.emplace_back(0);
        vector<int> step(n+1);
        step[0] = cost[0]; step[1] = cost[1];
        for(int i = 2; i < n+1; ++i){
            step[i] = cost[i] + min(step[i-1], step[i-2]);
        }
        return step[n];
    }
};