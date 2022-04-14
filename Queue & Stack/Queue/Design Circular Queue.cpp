#include<iostream>
#include<vector>
using namespace std;

/*
===================================================================
When design a circular queue, the most import formula is :

--------------------------------------------
Tail = (head + (currentSize - 1)) % Capacity
--------------------------------------------
so if length exceed the Capacity, it will automatically 
go to the front of Array

-----------------------------
head = (head + 1) % Capacity
-----------------------------
When enQueue, if head exceed the capacity, the head will 
automatically move to front

*/


class MyCircularQueue {
public:
    vector<int> queue;
    int head;
    int tail;
    int capacity; // the total size of queue
    int len; // current number of elements in queue


    MyCircularQueue(int k) {
        queue.resize(k, 0);
        head = tail = 0;
        capacity = k;
        len = 0; // initially, no element
    }
    
    void printQ(){
        cout << "head: " << head << "  ";
        cout << "tail: " << tail << "  ";
        for (auto it : queue){
            cout << it << " ";
        }
        cout << endl;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        ++len; // update length
        tail = (head + len - 1) % capacity;
        queue[tail] = value;

        cout << "enQueue: " << endl;
        return true; 
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head + 1) % capacity; 
        // move head 1 step, just leave dequeued elements waited for change
        --len;

        cout << "deQueue: " << endl;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return queue[head];
    }
    
    int Rear() {
       if(isEmpty()) return -1;
        return queue[tail]; 
    }
    
    bool isEmpty() {
        if(len == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(len == capacity) return true;
        return false;
    }
    
};
