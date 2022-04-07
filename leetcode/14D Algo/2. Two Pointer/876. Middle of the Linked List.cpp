#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;


/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ====================== Fast Slow Pointers =======================
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode* p1; ListNode* p2;
        p1 = p2 = head;

        while(p2 != nullptr && p2->next != nullptr){
            p1 = p1->next; // p1 take 1 step each time
            p2 = p2->next->next; // p2 take 2 steps each time
        }
        return p1;
    }
};