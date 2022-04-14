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
You are given an m x n binary matrix grid. An island is a group 
of 1's (representing land) connected 4-directionally (horizontal
or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(); int n = grid[0].size();
        queue<vector<int>> Q;
        vector<vector<int>> direction {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    Q.push({i, j});
                    int square = 1;
                    while(!Q.empty()){
                        int R = Q.front()[0]; int C = Q.front()[1];
                        Q.pop();
                        for(auto it : direction){
                            int Rt = R + it[0]; int Ct = C + it[1];
                            if(Rt >= 0 && Rt < m && Ct >= 0 && Ct < n && grid[Rt][Ct] == 1){
                                grid[Rt][Ct] = 0;
                                Q.push({Rt, Ct});
                                ++square;
                            }
                        }
                    }
                    res = max(res, square);
                }
            }
        }
        return res;
    }
};