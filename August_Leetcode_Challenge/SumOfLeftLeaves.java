/*
Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// time : O ( n ) : space : O ( Height of tree ), recursion stack
class Solution {
    
    private boolean isLeaf(TreeNode p){
        if(p==null) return false;
        if(p.left==null && p.right==null) return true;
        return false;
    }
    
    public int sumOfLeftLeaves(TreeNode root) {
        if(root==null) return 0;
        int l=0, r=0;
        if(root.left!=null){
            TreeNode left = root.left;
            if(isLeaf(left)){
                l=left.val;
            }
            else{
                l = sumOfLeftLeaves(left);
            }
        }
        r = sumOfLeftLeaves(root.right);
        return l+r;
    }
}
