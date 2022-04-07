#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for(auto &it : nums1){
            hashmap[it]++;
        }
        vector<int> result;
        for(auto &it : nums2){
            if(hashmap[it]){ // if exist in num1
                if(find(result.begin(), result.end(), it) == result.end()){ // if first time appears
                    result.push_back(it);
                }
            }
        }
        return result;
    }
};