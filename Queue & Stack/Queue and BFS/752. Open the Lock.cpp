#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
You have a lock in front of you with 4 circular wheels. Each wheel has 
10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels 
can rotate freely and wrap around: for example we can turn '9' to be '0', 
or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of 
these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.
*/


class Solution {
public:

    string neighbor(string S, int digit, int direction){
        if(direction < 0){
            S[digit] = (S[digit] == '0')? '9' : S[digit] - 1;
            return S;
        }
        else{
            S[digit] = (S[digit] == '9')? '0' : S[digit] + 1;
            return S;
        }
    }


    int openLock(vector<string>& deadends, string target) {
        queue<string> Q;
        unordered_set<string> visited(0); // memorization
        unordered_set<string> deads (deadends.begin(), deadends.end());
        if(target == "0000") return 0;
        if(deads.find("0000") != deads.end()) return -1;

        Q.push("0000"); visited.emplace("0000");
        int step = 0;
        while(!Q.empty()){
            int size = Q.size();
            ++step;
            for(int i = 0; i < size; ++i){ // current node
                string curLock = Q.front();
                Q.pop();
                for(int j = 0; j < 4; ++j){ // node's neighbors
                    string neighbor1 = neighbor(curLock, j, 1);
                    if(neighbor1 == target) return step;
                    else if(deads.find(neighbor1) == deads.end() && visited.find(neighbor1) == visited.end()){
                        // if not deadends, and hasn't been visited before:
                        visited.emplace(neighbor1);
                        Q.push(neighbor1);
                    }
                
                    string neighbor2 = neighbor(curLock, j, -1);
                    if(neighbor2 == target) return step;
                    else if(deads.find(neighbor2) == deads.end() && visited.find(neighbor2) == visited.end()){
                        // if not deadends, and hasn't been visited before:
                        visited.emplace(neighbor2);
                        Q.push(neighbor2);
                    }
                }
            }
        }
        return -1;
    }
};