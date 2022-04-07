#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*

*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> M;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(M.find(node) != M.end()) return M[node];
        Node* curr = new Node(node->val);
        M.emplace(node, curr);
        for(Node* pn : node->neighbors){
            curr->neighbors.emplace_back(cloneGraph(pn));
        }
        return curr;
    }
};