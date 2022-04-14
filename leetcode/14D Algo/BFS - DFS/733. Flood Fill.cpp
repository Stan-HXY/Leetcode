#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;
        int m = image.size();
        int n=  image[0].size();
        queue<vector<int>> Q;
        unordered_map<int, int> M; // Memo
        M[sr] = sc;
        vector<vector<int>> direction {{0,1}, {1,0}, {0,-1}, {-1,0}};
        Q.push({sr, sc});
        int old = image[sr][sc];
        image[sr][sc] = newColor;
        while(!Q.empty()){
            int R = Q.front()[0]; int C = Q.front()[1];
            Q.pop();
            for(auto it : direction){
                int Rt = R + it[0]; int Ct = C + it[1];
                if(M.find(Rt) != M.end() && M[Rt] == Ct) continue; // visited
                if(Rt >= 0 && Rt < m && Ct >= 0 && Ct < n){
                    if(image[Rt][Ct] == old){
                        image[Rt][Ct] = newColor;
                        Q.push({Rt, Ct});
                    }
                    M[Rt] = Ct;
                }
            }
        }
        return image;
    }
};