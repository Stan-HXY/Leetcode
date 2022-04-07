#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
#include<queue>
using namespace std;


/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCompare{
public:
    bool operator()(ListNode* p1, ListNode* p2) const {
        return p1->val < p2->val;
    }
};






// ================ recursion (FASTER) ===============================
class Solution1 {
public:
     /*
      _
     /         
    |   listA[0] < listB[0]:  listA[0] + merge( listA[1], listB[0])
   <    
    |   listA[0] > listB[0]:  listB[0] + merge( listA[0], listB[1])
     \_
      

    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2); // if l1 < l2, next recursion compare l1 ? l2->next, vice versa
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


// ================ iteration ===============================
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* dum {new ListNode(0)};
        ListNode* pt = dum;
        while(list1 && list2){
            if(list1->val < list2->val){
                pt->next = list1;
                list1 = list1->next;
            }
            else{
                pt->next = list2;
                list2 = list2->next;
            }
            pt = pt->next;
        }
        pt->next = (list1 == nullptr)? list2 : list1; // if one list is end, link the whole other list to the end

        ListNode* head = dum->next; delete dum;
        return head;
    }
};


// ================ loop with priority_queue (SLOW) ===============================
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> Q;
        ListNode* p1 = list1; ListNode* p2 = list2;
        
        while(p1){
            Q.push(p1);
            p1 = p1->next;
        }
        while(p2){
            Q.push(p2);
            p2 = p2->next;
        }
        ListNode* head = nullptr;
        while(!Q.empty()){
            Q.top()->next = head;
            head = Q.top();
            Q.pop();
        }
        return head; 
    }
};