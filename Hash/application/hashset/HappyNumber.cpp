#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

/*

Happy Number:
1. a positive number, keep taking sum of each digit number's square
if at end equal to 1 ---- happy number
if it end up in a circle ----- not a happy number 

A number will go either "end up 1" or "end up to a CIRCLE" 

*/



class Solution1 {
public:

    bool isHappy(int n) {
        unordered_set<int> hashset;
        while( n > 1 ){ // each 'sum-square' session
            int sum;
            // ---------------------------------- //
            while( n > 0 ){ 
                sum += (n % 10) * (n % 10); // first digit's square
                n /= 10; // select next digit
            }
            // ---------------------------------- // 
            if( hashset.count(sum) ){
                return false; // if exist, then it's a circle
            }
            n = sum;
            hashset.insert(sum);
        }
        return true;
    }
};