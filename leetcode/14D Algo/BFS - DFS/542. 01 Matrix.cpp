#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/

// ================= BFS =======================
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){ // record all cell that equals 0
                    Q.push(pair<int, int>(i, j));
                }
                else{
                    mat[i][j] = INT_MAX;
                }
            }
        }
        vector<vector<int>> direction {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!Q.empty()){
            int R = Q.front().first; 
            int C = Q.front().second;
            Q.pop();
            for(auto it : direction){
                int Rt = R + it[0];
                int Ct = C + it[1];
                if(Rt >= 0 && Rt < m && Ct >= 0 && Ct < n && mat[Rt][Ct] == INT_MAX){
                    mat[Rt][Ct] = mat[R][C] + 1;
                    Q.push(pair<int, int>(Rt, Ct));
                }
            }
        }
        return mat;
    }
};