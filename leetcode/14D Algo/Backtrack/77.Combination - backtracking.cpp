#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;


/*
Given two integers n and k, return all possible combinations 
of k numbers out of the range [1, n].

You may return the answer in any order.

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/* ==================================
BackTracking:
In every backtracking problem,  there are two things to keep in mind :
1. Base Case: 
    Every problem of backtracking has some base case which tells 
    us at which point we have to stop with the recursion process. 
    In our case, when the size of our array current equals to k i.e. 
    current.size()=k, we stop with the recursion and add it to our final result ans.

2. Conditions: 
    There is just one thing to keep in mind here:
    After generating combinations corresponding to a particular number i , 
    proceed to the next element by popping the element from the temporary 
    array current, as we used that already.
=================================== */ 

class practice{
public:

    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res;
        vector<int> curr(0);
        BackTrack(1, n, k, res, curr);
        return res;
    }

    void BackTrack(int i, int n, int k, vector<vector<int>>& res, vector<int>& curr){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        for(i; i <= n; ++i){
            curr.push_back(i);
            BackTrack(i + 1, n, k, res, curr);
            curr.pop_back();
        }
        return;
    }



};
















class Solution {
public:
    vector<vector<int>> answer;

    void BackTracking(int id, int n, int k, vector<int> curr){
        // base case
        if(curr.size() == k){
            answer.push_back(curr);
            return;
        }
        // first number(起点) loop
        for(int i = id; i < n+1; ++i){
            curr.push_back(i);
            BackTracking(i+1, n, k, curr);
            curr.pop_back(); // result already pushed in ANSWER, so clear the curr for next loop
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        BackTracking(1, n, k, curr);
        return answer;
    }
};