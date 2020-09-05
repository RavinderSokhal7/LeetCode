/*
All Elements in Two Binary Search Trees
Given two binary search trees root1 and root2.
Return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

Constraints:

    Each tree has at most 5000 nodes.
    Each node's value is between [-10^5, 10^5].
*/

// Solution : time : O ( N + M ) , Space : O ( htofone + htoftwo )

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

class BSTit{
    public Stack<TreeNode> s;
    public TreeNode cur;
    BSTit(TreeNode root){
        cur = root;
        s = new Stack<>();
        while(cur!=null){
            s.push(cur);
            cur = cur.left;
        }
    }
    
    public boolean hasNext(){
        if(cur!=null || !s.isEmpty()) return true;
        return false;
    }
    
    public TreeNode nextNode(){
        if(s.isEmpty()) return null;
        TreeNode ret = s.pop();
        cur = ret.right;
        while(cur!=null){
            s.push(cur); cur = cur.left;
        }
        return ret;
    }
}

class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> ans = new ArrayList<>();
        if(root1==null && root2==null) return ans;
        // iterator for two trees
        // TreeNode p = root1, q = root2;
        BSTit p = new BSTit(root1);
        BSTit q = new BSTit(root2);
        TreeNode f = p.nextNode(), s = q.nextNode();
        while(f!=null && s !=null){
            if(f.val < s.val){
                ans.add(f.val);
                f = p.nextNode();
            }
            else{
                ans.add(s.val);
                s = q.nextNode();
            }
        }
        while(f!=null){
            ans.add(f.val);
            f = p.nextNode();
        }
        while(s!=null){
            ans.add(s.val);
            s = q.nextNode();
        }
        return ans;
    }
}










