
import java.util.*;

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

    

    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if(original == null) return null;

        if(original == target) return cloned;
        TreeNode r1 = getTargetCopy(original.left, cloned.left, target);
        TreeNode r2 = getTargetCopy(original.right, cloned.right, target);
        return (r1 == null)? r2 : r1;
    }
}