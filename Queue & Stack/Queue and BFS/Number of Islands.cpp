#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a 
map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent 
lands horizontally or vertically. You may assume all four edges of the 
grid are all surrounded by water.

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]]

Output: 1

解法：遍历每个点
如果为‘0’就跳过；
如果为‘1’：
1. 那首先他一定是一个island的一部分，所以总数+1；
2. 将‘1’变为‘0’，表示已经走过此点，且外部循环的时候会直接跳过
3. 从此点出发进行BFS，如果为‘1’，就存入queue继续对新的点BFS（重复的点之前已经变为‘0’）
4. 直至再无‘1’，表示周围都已经是‘0’，
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        if(m == 0) return 0;
        int n = grid[0].size();
        int res = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++res;
                    grid[i][j] = '0'; // already visited, and won't be here again
                    queue<vector<int>> Q;
                    Q.push({i, j});
                    while(!Q.empty()){ // BFS from this point
                        int R = Q.front()[0]; int C = Q.front()[1];
                        Q.pop();
                        if(!R - 1 < 0 && grid[R - 1][C] == '1'){
                            grid[R - 1][C] = '0';
                            Q.push({R - 1, C});
                        }
                        if(!C - 1 < 0 && grid[R][C - 1] == '1'){
                            grid[R][C - 1] = '0';
                            Q.push({R, C - 1});
                        }
                        if(R + 1 < m && grid[R + 1][C] == '1'){
                            grid[R + 1][C] = '0';
                            Q.push({R + 1, C});
                        }
                        if(C + 1 < n && grid[R][C + 1] == '1'){
                            grid[R][C + 1] = '0';
                            Q.push({R, C + 1});
                        }
                    }
                }
            }
        }
        return res;
    }
};