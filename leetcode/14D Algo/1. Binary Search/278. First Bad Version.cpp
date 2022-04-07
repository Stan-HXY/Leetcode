#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1; int r = n;
        while(l < r){
            int m = (r - l)/2 + l;
            if(isBadVersion(m) == true){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};