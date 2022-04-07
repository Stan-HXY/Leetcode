#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

/*
Given a stream of integers and a window size, calculate the 
moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) 
Initializes the object with the size of the window size.

double next(int val) 
Returns the moving average of the last size values of the stream.

*/


class MovingAverage {
public:
    int capacity;
    int sum;
    list<int> Queue;

    MovingAverage(int size) {
       capacity = size;
       sum = 0;
       Queue.resize(0);
    }
    
    double next(int val) {
        sum += val;
        Queue.emplace_back(val);
        if(Queue.size() <= capacity){
            return sum/Queue.size();
        }
        else{
            sum -= Queue.front();
            Queue.pop_front();
            return sum/capacity;
        }
    }
};