#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given a 【directed acyclic graph】 (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.
* DAG: 有向无环图

The graph is given as follows: graph[i] is a list of all nodes you can 
visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Input: graph = [[1,2],[3],[3],[]]

    0 -> 1
    |    |
    v    v
    2 -> 3

Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

*/

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> res {0};

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        backTrack(0, graph.size() - 1, graph);
        return answer;
    }

    void backTrack(int curr, int dst, vector<vector<int>>& graph){
        if(curr == dst){
            answer.push_back(res);
            return;
        }
        if(graph[curr].empty()){
            return;
        }
        for(auto n : graph[curr]){
            res.push_back(n);
            backTrack(n, dst, graph);
            res.pop_back();
        }
        return;
    }
};