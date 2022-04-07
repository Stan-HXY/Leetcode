#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;


/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

---- example ----

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
*/


/*
思路： nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
then: nums1[i] + nums2[j] = - ( nums3[k] + nums4[l] )
*/


class Solution {
public:

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> M;
        int count = 0;
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                ++M[nums1[i] + nums2[j]];  // record how many qualified "nums1[i] + nums2[j]"
            }
        }
        for(int i = 0; i < nums3.size(); ++i){
            for(int j = 0; j < nums4.size(); ++j){
                if(M.find(0 - (nums3[i] + nums4[j])) != M.end()){
                    count += M[-(nums3[i] + nums4[j])];  // take all qualified complement into count
                }
            }
        }
        return count;    
    }
};