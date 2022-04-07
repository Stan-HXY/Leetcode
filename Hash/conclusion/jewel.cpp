#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;



/*
You're given strings jewels representing the types of stones that are jewels, 
and stones representing the stones you have. Each character in stones is a 
type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

--- example ----
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

*/


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count;
        unordered_set<char> dictionary;
        for(int i = 0; i < jewels.size(); ++i){
            dictionary.insert(jewels[i]);
        }
        for(int i = 0; i < stones.size(); ++i){
            if( dictionary.count(stones[i]) > 0 ){
                ++count;
            }
        }
        return count;
    }
};