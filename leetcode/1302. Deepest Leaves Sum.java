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

    // ===================== recursion =====================
    int bottom = 0; // estimate level
    int res = 0;

    public int deepestLeavesSum(TreeNode root) {
        return deepSum(root, 1);
    }

    public int deepSum(TreeNode root, int level){
        if(root == null) return 0;
        // -------- means we already reach bottom level --------
        if(root.left == null && root.right == null && level == bottom){
            res += root.val;
        }
        // -------- means real level > estimate level, update estimate level --------
        else if(root.left == null && root.right == null && level > bottom){
            bottom = level;
            res = root.val; // memorize node of new depth
        }
        // -------- means real level < estimate level, not the result we want --------
        else if(root.left == null && root.right == null && level < bottom){
            return 0;
        }

        deepSum(root.left, level + 1);
        deepSum(root.right, level + 1);
        return res;
    }



    // ===================== Queue level order traverse =====================
    public int deepestLeavesSum_1(TreeNode root) {
        Queue<TreeNode> Q = new LinkedList<>();
        int res = 0;
        Q.add(root);
        while(!Q.isEmpty()){
            int levelSum = 0;
            int s = Q.size();
            for (int i = 0; i < s; i++) {
                TreeNode p = Q.poll();
                levelSum += p.val;
                if(p.left != null) Q.add(p.left);
                if(p.right != null) Q.add(p.right);
            }
            res = levelSum;
        }
        return res;
    }
}