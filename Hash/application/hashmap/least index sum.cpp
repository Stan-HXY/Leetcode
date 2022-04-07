#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
#include<String>
using namespace std;


/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have 
a list of favorite restaurants represented by strings.
You need to help them find out their common interest with the least list index sum. 
If there is a choice tie between answers, output all of them with no order requirement. 
You could assume there always exists an answer.

------------ example -------------
list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
list2 = ["KFC","Shogun","Burger King"]

Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).



*/






class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) return findRestaurant(list2, list1); // use one-recursion to traverse the shorter list

        map<int, vector<string>> sum_map;
        unordered_map<string, int> map_A;
        for(int i = 0; i < list1.size(); ++i){
            map_A[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); ++i){
            if( map_A.find(list2[i]) != map_A.end() ){
                sum_map[ i + map_A[list2[i]] ].push_back(list2[i]);
            }
        }
        return sum_map.begin()->second;        
    }
};