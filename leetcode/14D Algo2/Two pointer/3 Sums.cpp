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
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res(0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; ++i){ // make sure: nums[i] <= 0
            if(i == 0 || nums[i - 1] != nums[i]){ // skip the duplicate for i
                int i2 = i + 1;
                int end = nums.size() - 1;
                while(i2 < end){
                    int sum = nums[i] + nums[i2] + nums[end];
                    if(sum > 0){
                        --end;
                    }
                    else if(sum < 0){
                        ++i2;
                    }
                    else{ // match
                        res.push_back({nums[i], nums[i2], nums[end]});
                        --end;
                        while(i2 < end){ // skip duplicate i2
                            ++i2;
                            if(nums[i2 - 1] != nums[i2]){
                                break;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};