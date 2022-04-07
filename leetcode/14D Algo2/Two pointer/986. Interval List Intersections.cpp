#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
You are given two lists of closed intervals, firstList and secondList, 
where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are 
either empty or represented as a closed interval. For example, the intersection 
of [1, 3] and [2, 4] is [2, 3].   

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res(0);
        int i = 0; int j = 0;
        while(i < firstList.size() && j < secondList.size()){
            int low = max(firstList[i][0], secondList[j][0]); // max of 2 low is the start of interval
            int high = min(firstList[i][1], secondList[j][1]); // min of 2 high is the end of interval
            if(low > high){ // they don't joint
                if(low == secondList[j][0]){
                    ++i;
                }
                else ++j;
            }
            else{
                res.push_back({low, high});
                if(high == firstList[i][1]){
                    ++i;
                }
                else{
                    ++j;
                }
            }
        }
        return res;
    }
};