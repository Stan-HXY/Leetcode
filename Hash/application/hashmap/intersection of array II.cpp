#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) intersect(nums2, nums1);
        unordered_map<int, int> M;
        vector<int> V;
        for(int i = 0; i < nums1.size(); ++i){
            ++M[nums1[i]];
        }
        for(int i = 0; i < nums2.size(); ++i){
            if( M[nums2[i]] > 0 ){
                --M[nums2[i]];  // appear once, deduct once 
                V.push_back(nums2[i]);
            }
        }
        return V;
    }
};