/*
Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
// Solution : time : O ( n ) : space : O ( n )
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

class Solution {
    private int cur = 0;
    private HashMap<Integer, Integer> m;
    private TreeNode bt(int[] in, int [] post, int b, int e){
        if(cur==-1 || b == e) return null;
        TreeNode p = new TreeNode(post[cur]);
        int ind = m.get(p.val);
        cur--;
        p.right = bt(in, post, ind+1, e);
        p.left = bt(in, post, b, ind);
        return p;
    }
    
    public TreeNode buildTree(int[] in, int[] post) {
        m = new HashMap<>();
        int n = in.length;
        for(int i=0;i<n;i++){
            m.put(in[i], i);
        }
        cur = n-1;
        return bt(in,post,0,n);
    }
}
