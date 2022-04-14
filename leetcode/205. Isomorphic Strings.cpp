#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> M;
        unordered_set<char> S;
        for(int i = 0; i < s.size(); ++i){
            if( M.find(s[i]) != M.end() && t[i] != M[s[i]] ) { // if s repeated, but t is not
                return false;
            }
            else if(M.find(s[i]) == M.end() && S.count(t[i]) > 0){ // if t repeated, but s is not
                return false;
            }
            M[s[i]] = t[i];
            S.emplace(t[i]);
            
        }
        return true;
    }

// ============== optimized ==========================
    bool isIsomorphic_2(string s, string t) {
        unordered_map<char, char> S; // dict for s->t
        unordered_map<char, char> T; // dict for t->s
        for(int i = 0; i < s.size(); ++i){
            if( S.count(s[i]) || T.count(t[i]) ) { // if either is repeating, but not the other one
                if(S[s[i]] != t[i] && T[t[i]] != s[i]){
                    return false;
                }
            }
            S[s[i]] = t[i];

            T[t[i]] = s[i];
        }
        return true;
    }
};
