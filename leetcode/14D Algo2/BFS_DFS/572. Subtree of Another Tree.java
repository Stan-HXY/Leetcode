
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null){
            return root == subRoot;
        }
        return check(root, subRoot) ||  // check start from current node
                isSubtree(root.left, subRoot) || 
                isSubtree(root.right, subRoot);
    }

    public boolean check(TreeNode p1, TreeNode p2){
        if(p1 == null && p2 == null) return true;
        if(p1 == null || p2 == null) return false;
        
        if(p1.val != p2.val) return false;
        return check(p1.left, p2.left) && check(p1.right, p2.right);
    }
}