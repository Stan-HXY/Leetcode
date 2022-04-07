#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

// =============== one loop =========================
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for(auto &it : nums){
            if(!hashmap[it]){
                hashmap[it] = 1;
            }
            else{ // if already exist (we added before), then erase(don't need number that has duplication)
                hashmap.erase(it);
            }    
        }
        // hashmap will only have the unique element
        // (because once it has duplicate, it will be delete)
        return hashmap.begin()->first;
    }
};