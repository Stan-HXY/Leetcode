import java.util.*;

/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length; int n = matrix[0].length;
        int start = 0; int end = m*n - 1;
        while(start <= end){
            int mid = (start + end)/2;
            if(mid < 0 || mid > m*n - 1) return false;
            int mvalue = matrix[mid/n][mid%n];
            if(mvalue == target) return true;
            if(mvalue > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
}