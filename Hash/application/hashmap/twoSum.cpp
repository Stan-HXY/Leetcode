#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        vector<int> result;
        for( int i = 0; i < nums.size(); ++i ){
            int complement = target - nums[i];
            if ( M.find(complement) != M.end() ){
                result.push_back(i);
                result.push_back(M[complement]);
                break;
            }
            M[nums[i]] = i;
        }
        return result;
    }


};