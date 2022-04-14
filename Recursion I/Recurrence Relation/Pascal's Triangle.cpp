#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;


/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/


class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pt;    
        for(int i = 1; i < rowIndex + 2; ++i){
            vector<int> rowv(i,1);            
            pt.push_back(rowv);           
            for(int j = 1; j < i - 1; ++j){
                pt[i-1][j] = pt[i-2][j-1] + pt[i-2][j];
            }
            cout << endl;
        }
        return pt[rowIndex];    
    }

};