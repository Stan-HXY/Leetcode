#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from 
the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel 
of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the 
same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
*/

class Solution {
public:

    vector<vector<int>> direction {{0,1}, {1,0}, {0, -1}, {-1, 0}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int Ocolor = image[sr][sc];
        
        queue<vector<int>> Q;
        Q.push({sr, sc});
        while(!Q.empty()){
            int R = Q.front()[0]; int C = Q.front()[1];
            Q.pop();
            for(auto it : direction){
                int Rt = R + it[0]; int Ct = C + it[1];
                if(Rt < image.size() && Ct < image[0].size() && image[Rt][Ct] == Ocolor){
                    Q.push({Rt, Ct});
                }
            }
            image[R][C] = newColor;
        }
        return image;
    }
};