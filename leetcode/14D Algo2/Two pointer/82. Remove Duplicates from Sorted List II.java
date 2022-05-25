import java.util.*;

public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/*
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dum = new ListNode(); dum.index = 0;
        dum.next = head;
        ListNode p0 = dum, p1 = head;
        while(p1 != null && p1.next != null){
            ListNode p2 = p1.next;
            //System.out.println(p0.index + " " + p1.index);
            if(p2 != null && p2.val != p1.val){
                p0 = p1;
                p1 = p2;   
                continue;
            }
            while(p2 != null && p2.val == p1.val){
                p2 = p2.next;
            }
            p1 = p2;
            p0.next = p1;
        }
        head = dum.next;
        dum.next = null;
        return head;
    }
}