#include<utility>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;



/*
Given an integer array nums and an integer k, return 
the k most frequent elements. You may return the answer in any order.

----- example -----
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

思路：
*/

class Solution2 {
public:
   vector<int> topKFrequent(vector<int>& nums, int k){
        if( k == nums.size()) return nums; // if k = length of nums, then all numbers consider valid
        
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); ++i){
            ++M[nums[i]];
        }
        vector<int> res;
        priority_queue<pair<int, int>> heap; // heap will compare pairs< a, b > by "a"
        for ( auto it : M ){
            heap.emplace(it.second, it.first); // 
        }
        while(k--){
            res.emplace_back(heap.top().second);
            heap.pop();
        }
        return res;
   } 


};




class Solution { // failed
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); ++i){
            ++M[nums[i]];
        }
        vector<int> res;
        for (auto it:M){
            if(it.second >= k){
                res.push_back(it.first);
            }
        }
        return res;
    }
};