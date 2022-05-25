import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/*
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
*/

class Solution {


    public Node connect(Node root){
        if(root == null) return root;
        Queue<Node> Q = new LinkedList<>();
        Q.add(root);
        while(!Q.isEmpty()){
            int len = Q.size();
            for (int i = 0; i < len; i++) {
                Node t = Q.poll();
                if(i < len - 1){
                    t.next = Q.peek();
                }
                if(t.left != null){
                    Q.add(t.left);
                }
                if(t.right != null){
                    Q.add(t.right);
                }
            }
        }
        return root;
    }













    public Node connect_1(Node root) {
        if(root == null) return root;
        Queue<Node> Q = new LinkedList<>();
        Q.add(root);

        while(!Q.isEmpty()){
            int len = Q.size();
            
            for(int i = 0; i < len; ++i){
                Node p = Q.poll();
                if(i != len - 1){ // in case Node is end of current level
                    p.next = Q.peek();
                }
                if(p.left != null) Q.add(p.left);
                if(p.right != null) Q.add(p.right);
            }

        }
        return root;
    }

}