#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
#include<algorithm>
using namespace std;

/*
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two 
endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, s
uch that the container contains the most water.

Return the maximum amount of water a container can store.


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by 
array [1,8,6,2,5,4,8,3,7]. In this case, the max area of 
water (blue section) the container can contain is 49.
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            int curr_square = (r - l) * min(height[l], height[r]);
            res = max(res, curr_square);
            /* --- if left is lower than right, we should move left inward, because
            left height limited the square, so trade shorter longitude for higher chance of height   */
            if(height[l] <= height[r]){
                ++l;
            }
            else{
                --r;
            }
        }
        return res;
    }
};