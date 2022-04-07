#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
You are given an m x n grid 
where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must 
elapse until no cell has a fresh orange. If this is impossible, return -1

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> direction {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<vector<int>> Q;
        int fresh = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    Q.push({i, j});
                }
                if(grid[i][j] == 1){
                    ++fresh;
                }
            }
        }

        int res = 0;
        while(!Q.empty() && fresh != 0){
            int num = Q.size();
            for(int i = 0; i < num; ++i){
                int r = Q.front()[0]; int c = Q.front()[1];
                Q.pop();
                for(auto it : direction){
                    int rt = r + it[0]; int ct = c + it[1];
                    if(rt < m && rt >= 0 && ct < m && ct >= 0 && grid[rt][ct] == 1){
                        grid[rt][ct] = 2;
                        --fresh;
                        Q.push({rt, ct});
                    }
                }
            }
            ++res;
        }
        return (fresh == 0)? res : -1;
    }
};