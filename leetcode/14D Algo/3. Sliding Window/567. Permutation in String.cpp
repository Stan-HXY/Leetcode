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
Given two strings s1 and s2, return true if s2 
contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations 
is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

// =========================== Slide Window =============================
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(); int size2 = s2.size();
        if(size1 > size2) return false;
        vector<int> s1m(26, 0);
        vector<int> s2m(26, 0);
        // ------------- the first window --------------
        int i = 0;
        for(i; i < size1; ++i){
            ++s1m[s1[i] - 'a'];
            ++s2m[s2[i] - 'a'];
        }
        // --------------------------------------------
        while(i < size2){       
            if(s1m == s2m){
                return true;
            }
            // ------- otherwise, slide the window --------
            ++s2m[s2[i] - 'a']; // right-end
            --s2m[s2[i - size1] - 'a']; // left-end
            ++i; // slide
        }
        return s1m == s2m;
    }
};

// class Solution {
// public:

//     bool isempty(unordered_map<char, int> M){
//         for(auto it : M){
//             if(it.second != 0){
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool checkInclusion(string s1, string s2) {
//         int size1 = s1.size(); int size2 = s2.size();
//         if(size2 == 1 && s2 == s1) return true;
//         if(size1 > size2) return false;
        
//         unordered_map<char, int> M;
//         int res = 0;
//         for(auto it : s1){
//             ++M[it];
//         }
//         //int j = 0;
//         for(int i = 0; i < size2; ++i){
//             if(M.find(s2[i]) == M.end()){
//                 continue;
//             }
//             else{
//                 unordered_map<char, int> Mt (M);
//                 int j = i;
//                 for(j; j - i < size1; ++j){
//                     if(Mt.find(s2[j]) != Mt.end()){
//                         --Mt[s2[j]];
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 if(isempty(Mt)){
//                     return true;
//                 }
//                 else{
//                     i = j + 1;
//                 }
//             }
//         }
//         return false;


//     }
// };