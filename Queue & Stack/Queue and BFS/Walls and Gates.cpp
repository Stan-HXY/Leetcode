#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

/*
You are given an m x n grid rooms initialized with these three possible values.

-1: A wall or an obstacle.
0: A gate.
INF: Infinity means an empty room. 
We use the value 2^31 - 1 = 2147483647 to represent INF as you may 
assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. 
If it is impossible to reach a gate, it should be filled with INF.
*/


/*
如果从rooms的第00开始走，会非常难，因为00本身可行性太多，且你需要记录从此点走的每一步直到gate，还需要判断最小值；
解法：

1. 先遍历rooms，找出gate的坐标，存入queue
2. access每个gate的上下左右，如果不是gate也没有值也没有wall，就+1，并存入queue
3. queue【gate1, gate2, gate1上，gate1下，gate1左，gate1右，gate2上，gate2下，gate2左，gate2右】
这样先遍历每个gate，将每个gate相邻的room先存入queue，下一回合从这些相邻为1的room开始

*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(); if(m == 0) return;
        int n = rooms[0].size();
        queue<vector<int>> Q;
        vector<vector<int>> direction{vector<int>{1,0}, {0,-1}, {-1, 0}, {0, 1}}; //right, down, left, up
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rooms[i][j] == 0){
                    Q.push({i, j}); // record every location of GATE
                }
            }
        }

        while(!Q.empty()){
            int G_row = Q.front()[0], G_column = Q.front()[1]; // original location
            Q.pop(); // delete first one !!!!
            for(auto& it : direction){
                int R = G_row + it[0]; 
                int C = G_column + it[1]; 
                // current cell location after 1 step

                if(R < 0 || C < 0 || R > m - 1 || C > n - 1 || rooms[R][C] != 2147483647){
                    continue;
                }
                rooms[R][C] = rooms[G_row][G_column] + 1;
                cout << R << " " << C << endl;
                Q.push({R, C}); // push new one into Queue
            }
        }
    }
};