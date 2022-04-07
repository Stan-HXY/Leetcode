#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            int count = Q.size();
                  
            for(int i = 0; i < count; ++i){
                Node* p = Q.front(); // extract 1 node
                Q.pop();
                
                // if not the last node in this level
                if(i != count - 1){ 
                    p->next = Q.front();
                }
                
                if(p->left) Q.push(p->left); // push left child
                if(p->right) Q.push(p->right); // push right child
            }
        }
        return root;
    }
};
