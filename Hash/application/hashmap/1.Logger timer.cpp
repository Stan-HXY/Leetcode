#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;



/*
Design a logger system that receives a stream of messages along with their timestamps. 
Each unique message should only be printed at most every 10 seconds (i.e. a message 
printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.

bool shouldPrintMessage(int timestamp, string message) 
Returns true if the message should be printed in the given timestamp, otherwise returns false.

----- example -----
[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]
null, true, true, false, false, false, true
*/


// 思路: if string are same, check if index within 10
class Logger {
public:

    unordered_map<string, int> logger;
    Logger(){}
   
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logger.count(message) > 0){
            if(timestamp - logger[message] < 10) return false;
        }
        logger[message] = timestamp;

        return true;
    }
};








/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */