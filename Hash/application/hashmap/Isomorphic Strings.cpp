#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic(同型) if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same character, 
but a character may map to itself.

----------- example: ------------
Input: s = "egg", t = "add"
Output: true

Input: s = "paper", t = "title"
Output: true

Input: s = "foo", t = "bar"
Output: false

------- test case -------
qwertyuiop[]asdfghjkl;'\\zxcvbnm,./
',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz

*/





// =============  
class Solution1 {
public:
    /*
    s = [paper], t = [titile]
    */

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_map_t;   // S's characters map with T's characters
        unordered_map<char, int> t_map_count; // T's characters map the counts

        for(int i = 0; i < s.size(); ++i){
            if( s_map_t.find(s[i]) != s_map_t.end() ){// ------- if character in S repeated...  ----------------------------------- //
                if( s_map_t[s[i]] != t[i] ){ //       ... then if T character mapping by S is not corresponding to T[i] ...
                    return false; //                      they are not isomorphic( S is repeating, T doesn't )
                } // -------------------------------------------------------------------------------------------------------------- //
            }

            //                                           ------------- if S's character is not repeating ... ------------------- //
            else if( t_map_count.find(t[i]) != t_map_count.end() ){ // ... and T's character is repeating ..
                return false; //                        they are not isomorphic( S doesn't repeating, but T is repeating )
            } // --------------------------------------------------------------------------------------------------------------- //
            else{
                s_map_t[s[i]] = t[i];
                t_map_count[t[i]] += 1;
            }
        }
        return true;
    }
};


// =========== supper fast, need to know  ???? ============================
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
      int sind[129] = {0}, tind[129] = {0};                 //hash tables for characters from our strings
      
      for(int i = 0; i < s.size(); i++){
        if( sind[s[i]] != tind[t[i]] ) return false;     //if previous characters have different position
        sind[s[i]] = tind[t[i]] = i+1;                    //put last position of characters
      }
      
      return true;
    }
};

/* ==================== ++i  or  i++ =========================
  ++i will increment the value of i, and then return the incremented value.

 i = 1;
 j = ++i;
 (i is 2, j is 2)

  i++ will increment the value of i, but return the original value that i held before being incremented.

 i = 1;
 j = i++;
 (i is 2, j is 1)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> s_order;
        unordered_map<char, vector<int>> t_order;
        for(int i = 0; i < s.length(); ++i){
            s_order[s[i]].push_back(i);
            t_order[t[i]].push_back(i);
        }
        auto its = s_order.begin();
        auto itt = t_order.begin();
        while(its != s_order.end()){
            vector<int>& vs = its->second;
            vector<int>& vt = itt->second;
            if(vs.size() != vt.size()) return false;
            for(int i = 0; i < vs.size(); ++i){
                if(vs[i] != vt[i]){
                    return false;
                }
            }
            ++its;
            ++itt;
        }
        return true;
    }
};