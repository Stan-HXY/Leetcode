#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {        
        int m = matrix.size(); int n = matrix[0].size();
        int end = m*n - 1; int start = 0;
        while(start <= end){
            int mid = (start + end)/2;
            // col number is index % n, row number is index / n
            if(matrix[mid/n][mid % n] == target){
                return true;
            }
            else if(matrix[mid/n][mid % n] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }   
        }           
        return false;       
    }
};