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

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res (mat.size(), vector<int>(mat[0].size(), INT_MAX));
        vector<vector<int>> direction {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<int>> Q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    Q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        while(!Q.empty()){
            int r = Q.front()[0]; int c = Q.front()[1];
            Q.pop();
            for(auto it : direction){
                int rt = r + it[0]; int ct = c + it[1];
                if(rt >= 0 && rt < m && ct >= 0 && ct < n){
                    if(res[rt][ct] > res[r][c] + 1){ // if bigger, then either [not 0] or [not shortest path], which need update (avoid duplicate and shortest path)
                        res[rt][ct] = res[r][c] + 1;
                        Q.push({rt, ct});
                    }
                }
            }

        }
        return res;
    }
};




// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {     
//         vector<vector<int>> res (mat.size(), vector<int>(mat[0].size(), 0));
//         vector<vector<int>> direction {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int m = mat.size();
//         int n = mat[0].size();
//         unordered_set<vector<int>> record (0);
//         for(int i = 0; i < mat.size(); ++i){
//             for(int j = 0; j < n; ++j){
//                 if()

//                 if(mat[i][j] == 0){
//                     continue;
//                 }
//                 else if(mat[i][j] == 1){
//                     queue<vector<int>> Q;
//                     Q.push({i, j});
//                     int k = 1;
//                     bool equal = false;
//                     while(!Q.empty()){
//                         int r = Q.front()[0]; int c = Q.front()[1];
//                         Q.pop();
//                         for(auto it : direction){
//                             int rt = r + it[0]; int ct = c + it[1];
//                             if(rt < m && ct < n ){
//                                 if(mat[rt][ct] == 0){
//                                     equal = true;
//                                     break;
//                                 }
//                                 else{
//                                     Q.push({rt, ct});
//                                 }
//                             }
//                         }
//                         if(equal) break;
//                         ++k;
//                     }

//                 }
//             }
//         }


//     }
// };