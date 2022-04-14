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
You are given two non-empty linked lists representing 
two non-negative integers. The digits are stored in 
reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading 
zero, except the number 0 itself.

Input: l1 = [2,4,3];
       l2 = [5,6,4,1]
Output: [7,0,8], 342 + 465 = 807
*/


class Solution2 {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2; if(!l2) return l1;
        ListNode* p1 = l1; ListNode* p2 = l2;
        ListNode* dum{new ListNode()}; ListNode* p = dum;
        int carry{0}; 
        while(p1!=nullptr || p2!=nullptr){
            int a = (p1 == nullptr)? 0 : p1->val; // if reach end, return 0
            int b = (p2 == nullptr)? 0 : p2->val; // if reach end, return 0  
            int sum = (carry + a + b)%10;
            carry = (carry + a + b)/10; // the digit needed to be added at next
            p->next = new ListNode(sum);
            p = p->next;
            if(p1 != nullptr) p1 = p1->next;
            if(p2 != nullptr) p2 = p2->next;
        }
        if(carry > 0)  p->next = new ListNode(carry); // if sum of end of two integer's digit's >10, more digit
        return dum->next;
    }

};



class Solution1 {
public:

    int count(ListNode* p, int i, int a){
        if(!p) return 0; 
        a += i*(p->val) + count(p->next, i*10, a);
        return a;
    }
    // int max is 2147483647

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int res = count(l1, 1, 0) + count(l2, 1, 0);
        if(res == 0){
            ListNode* p {new ListNode(0)};
            return p;
        }
        ListNode* head{nullptr}; ListNode* prev{nullptr};
        while(res >= 1){
            ListNode* pn {new ListNode(res % 10)};
            if(head == nullptr) head = pn;
            else prev->next = pn;
            prev = pn;
            res /= 10;
        }
        return head;
    }
};



class Solution {
public:
    // =============== Recursion: convert a linkedlist into integer (left to right) ====================
    int i = 1;
    int count(ListNode* p, int a){
        if(!p) return 0;       
        a += count(p->next, a) + i*(p->val);
        i = i * 10;        
        return a;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = count(l1, 0); int i = 1;
        int b = count(l2, 0);
        int ab = a + b; 
        ListNode* head {nullptr};
        // ================= convert a integer into linkedlist ==============================
        while(ab >= 1){
            ListNode* p{ new ListNode(ab % 10)};
            p->next = head;
            head = p;
            ab /= 10;
        }
        return head;
    }
};