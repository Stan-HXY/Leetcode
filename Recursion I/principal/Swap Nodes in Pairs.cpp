#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Input: head = [1,2,3,4]
Output: [2,1,4,3]
*/

// ================= Best solution, didn't figure out ======================
class Solution_faster {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        
        return temp;
    }
};


// ==================== my solution =====================
class Solution {
public:

    void helper(ListNode* head){
        if(!head->next || !head->next->next) return;
        ListNode* ptemp = head->next;
        ListNode* ptemp2 = ptemp->next;
        head->next = ptemp2;
        ptemp->next = ptemp2->next;
        ptemp2->next = ptemp;
        helper(head->next->next);
        return;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* dum = new ListNode();
        dum->next = head;
        helper(dum);
        head = dum->next;
        delete dum;
        return head;
    }
};