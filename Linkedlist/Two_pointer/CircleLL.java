package linkedlist.Two_pointer;

import java.util.*;

class ListNode{
    int val;
    ListNode next;
    ListNode(int i){val = i; next = null;}
}


// solution ------ using hash
class solution {
    public ListNode detectCycle(ListNode head){
        if( head == null ){ return null; }
        HashMap<String, Integer> M = new HashMap<>();
        ListNode p = head;
        while(p != null){
            if(M.containsKey(p.toString())){
                return p;
            }
            else{
                M.put(p.toString(), 0);
            }
            p = p.next;
        }
        return null;
    }
}

