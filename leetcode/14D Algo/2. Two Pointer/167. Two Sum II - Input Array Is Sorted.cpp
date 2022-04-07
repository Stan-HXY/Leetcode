#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Sorted Array - Two sum
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].c
*/

// ==================== Two Pointers ===================
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> res; int size = numbers.size();
        int l = 0; int r = numbers.size() - 1;
        while(l <= r){
            if(numbers[l] + numbers[r] == target){
                res.emplace_back(l); res.emplace_back(r);
                break;
            }
            else if(numbers[l] + numbers[r] < target){
                ++l;
            }
            else{
                --r;
            }
        }
        return res;
    }

};

// ========================= hash table ===============================
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> M;
        vector<int> res;
        for(int i = 0; i < numbers.size(); ++ i){
            if(M.find(target - numbers[i]) != M.end()){
                res.push_back(M[target - numbers[i]] + 1); res.push_back(i + 1);
                break;
            }
            else{
                M[numbers[i]] = i;
            }
        }
        return res;
    }
};