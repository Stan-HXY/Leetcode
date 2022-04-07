#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <stack>
using namespace std;


/*
Design a stack that supports push, pop, top, and retrieving 
the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
*/

// --------------- better implementation ---------------------
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            int tmin = st.top().second;
            st.push({val,min(tmin,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


// --------------- Mine (slower) ---------------------
class MinStack_1 {
private:
    multiset<int> MinMax;
    list<int> data;

public:

    MinStack_1() {
       data.resize(0);
    }
    
    void push(int val) {
        data.emplace_back(val);
        MinMax.emplace(val);
        cout << "push: " << data.back() << endl;
    }
    
    void pop() {
        if(data.empty()) return;
        MinMax.erase(MinMax.find(data.back()));
        data.pop_back();
        cout << "pop; " << endl;
    }
    
    int top() {
        if(data.empty()) return 0;
        cout << "top: " << data.back() << endl;
        return data.back();
    }
    
    int getMin() {
        if(data.empty()) return 0;
        cout << "Min: " << *(MinMax.begin()) << endl;
        return *(MinMax.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */