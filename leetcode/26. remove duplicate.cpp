#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


/*
Ascending sorted array
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/


class Solution {
public:
    // ========================== two pointer ====================================
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); ++j){ // if j is duplicate, just ignore to the next
            if(nums[i] != nums[j]){ 
                ++i;
                nums[i] = nums[j]; // if not duplicate, assign this value to i's next, and move i to next
            }
        }
        return i + 1;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> S;
        int k = 0;
        auto it = nums.begin();
        while(it != nums.end()){
            if (S.find(nums[k]) != S.end()){
                S.erase(nums[k]);
                rotate(it, it+1, nums.end());
                *it = 0;
            }
            else{
                S.emplace(nums[k]);
                ++k;
            }
        }
        return S.size();
    }
};