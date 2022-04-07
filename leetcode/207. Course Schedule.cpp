#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
here are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. You are given an array 
prerequisites where prerequisites[i] = [ai, bi] indicates 
that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take 
course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished 
course 1. So it is impossible.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int res;
        unordered_set<int> Taken(0);
        unordered_set<int> WaitList(0);
        unordered_map<int, int> Dict;
        for(auto& it : prerequisites){
            Dict[it[0]] = it[1];
        }
        for(int i = 0; i < numCourses; ++i){
            if(Dict.find(i) != Dict.end()){ // has prerequisite course
                if(Taken.count(Dict[i]) == 0){ // prerequisite hasn't taken
                    WaitList.emplace(Dict[i]);
                }
                else{ // prerequisite taken
                    //++res;
                    // WaitList.erase(Dict[i]);
                    Taken.emplace(i);
                }
            }
            else{
                Taken.emplace(i);
                if(WaitList.count(i) != 0){
                    ++res;
                    WaitList.erase(i);
                }
            }
        }
        return Taken.size() + res == numCourses;
    }
};