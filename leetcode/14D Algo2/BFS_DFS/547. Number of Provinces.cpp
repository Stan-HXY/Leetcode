#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected 
directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities 
and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:
     int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        int res = 0;
        vector<bool> visited(len, false); // number of node is 'len'
        for(int i = 0; i < len; ++i){
            if(visited[i] == false){        
                dfs(isConnected, i, visited);
                ++res;
            }
        } 
        return res;   
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i] = true; // we are visiting this i node

        // traverse node i's neighbors
        for(int j = 0; j < isConnected.size(); ++j){
            if(isConnected[i][j] == 1 && visited[j] == false){ // if haven't been visited, and connect to node i
                dfs(isConnected, j, visited); // then keep search
            }
        }
        return;
    }



};