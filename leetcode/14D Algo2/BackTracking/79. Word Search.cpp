#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;

/*
Given an m x n grid of characters board and a string word, 
return true if word exists in the grid.

The word can be constructed from letters of sequentially 
adjacent cells, where adjacent cells are horizontally or 
vertically neighboring. The same letter cell may not be used more than once.
*/


class Solution3{
public:

    bool exist(vector<vector<char>>& board, string word){
        if(word == "") return false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }


    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n){
        if(n == word.size()){
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]){
            return false; // out of boundary || wrong character
        }
        board[i][j] = '0'; // visited
        bool res = DFS(board, word, i+1, j, n+1) || // down
                   DFS(board, word, i, j+1, n+1) || // right
                   DFS(board, word, i-1, j, n+1) || // up
                   DFS(board, word, i, j-1, n+1);   // left
        board[i][j] = word[n];
        
        return res;
    }


};




class Solution2{
public:
    string res;
    unordered_set<vector<int>> visited;
    vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1, 0}};

    bool exist(vector<vector<char>>& board, string word){
        vector<vector<int>> starts;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    starts.push_back({i, j});
                }
            }
        }
    }

    void backtrack(int step, vector<int> curr, vector<vector<char>>& board, string word){
        if(step == word.size()){
            return;
        }
        for(auto i : direction){
            int r = curr[0] + i[0];
            int c = curr[1] + i[1];
            if(visited.find({r, c}) != visited.end()){
                continue;
            }
            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == word[step]){

            }
        }
        return;
    }

};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ht = board.size();
        int wid = board[0].size();
        int len = word.size();
        queue<vector<int>> Q;
        vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1, 0}};
        string res(len, ' ');
        // ===== find begin ====
        for(int i = 0; i < ht; ++i){
            for(int j = 0; j < wid; ++j){
                if(board[i][j] == word[0]){
                    Q.push({i, j});
                    res[0] = board[i][j];
                    board[i][j] = '0';
                }
            }
        }
        int step = 1;
        // ===== bfs =====
        while(!Q.empty() && step != word.size()){
            bool hit = false;
            int R = Q.front()[0]; int C = Q.front()[1];
            Q.pop();
            for(auto it : direction){
                int Rt = R + it[0];
                int Ct = C + it[1];
                if(Rt >= 0 && Rt < ht && Ct >= 0 && Ct < wid && word[step] == board[Rt][Ct]){
                    res[step] = word[step];
                    hit = true;
                    Q.push({Rt, Ct});
                    board[Rt][Ct] = '0';
                }
            }
            if(hit == true) ++step;
        }
        return res == word;
    }
};