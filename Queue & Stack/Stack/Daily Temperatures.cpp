#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack> 
using namespace std;

/*
Given an array of integers temperatures represents the 
daily temperatures, return an array answer such that 
answer[i] is the number of days you have to wait after 
the ith day to get a warmer temperature. If there is no 
future day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if(size == 1){
            temperatures[0] = 0;
            return temperatures;        
        }
        vector<int> res(size, 0);
        stack<vector<int>> S;
        for(int i = 0; i < size; ++i){
            while(!S.empty() && S.top()[1] < temperatures[i]){
                res[S.top()[0]] = i - S.top()[0];
                S.pop();
            }
            S.push({i, temperatures[i]});
        }
        return res;
    }     
};




// -------------------------------- using stack ------------------------------
/*
store the hotter day, if colder, push in
Stack itself is Descending order
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>& tem = temperatures;
        vector<int> res(tem.size(), 0);
        stack<vector<int>> st;// ([0, 73], [1, 74], [2, 75] ... )
        for(int i = 0; i < tem.size(); ++i){
            while(!st.empty() && tem[i] > st.top()[1]){
                res[st.top()[0]] = i - st.top()[0];
                st.pop();
            }
            st.push({i, tem[i]});
        }
        return res;
    }
};



// ---------------------- Time limit exceeded ------------------------------
class Solution0 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>& tem = temperatures;
        vector<int> res(tem.size(), 0);
        for(int i = 0; i < tem.size(); ++i){
            for(int j = i + 1; j < tem.size(); ++j){
                if(tem[j] > tem[i]){
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};