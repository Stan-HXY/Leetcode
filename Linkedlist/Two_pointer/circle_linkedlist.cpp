/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<map>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pfast, *pslow;
        pfast = pslow = head;
        while(pfast && pfast->next){
            pslow = pslow->next;
            pfast = pfast->next->next;
            if(pfast == pslow){return true;}
        }
        return false;    
    }


//// use Two-pointer --------------------------
    // ListNode* detectCycle(ListNode *head) {
    //     map<int, bool> M {};
    //     ListNode* pfast, *pslow;
    //     pfast = pslow = head;
    //     while(pfast && pfast->next){
    //         pslow = pslow->next;
    //         pfast = pfast->next->next;
    //         if(pfast == pslow){  // if is a circle-linkedlist
    //             pslow = head; // reset pslow back to head, while pfast still in circle
    //             while (pslow != pfast){
    //                 pslow = pslow->next;
    //                 pfast = pfast->next;
    //             }
    //             return pslow;        
    //         }
    //     }
    //     return nullptr;    
    // }

// use hasp map ----------------------------
    ListNode* detectCycle(ListNode *head) {
        map<ListNode*, int> M {};
        ListNode* pfast, *pslow;
        pfast = pslow = head;
        while(pslow && pslow->next){
            if(M.find(pslow) != M.end()){
                return pslow;
            }
            M[pslow] = pslow->val;
            pslow = pslow->next;
        }
        return nullptr;    
    }





};