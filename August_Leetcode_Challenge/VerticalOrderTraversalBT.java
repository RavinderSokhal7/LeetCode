/*
987. Vertical Order Traversal of a Binary Tree
Medium

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
Example 1:

Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

*/
//Solution : Time : O ( n log n ) , traversing all nodes once, space : O ( n )
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

class PairComp implements Comparator<Pair>{
    public int compare(Pair a, Pair b){
        if(a.sec==b.sec) return a.fir.val-b.fir.val;
        return a.sec-b.sec;
    }
}

class Pair{
    int sec;
    TreeNode fir;
    Pair(TreeNode f, int s){
        sec = s;
        fir = f;
    }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        TreeNode p = root;
        if(root==null) return ans;
        HashMap<Integer,List<Integer> > m = new HashMap<>();
        Queue<Pair> q = new PriorityQueue<>(new PairComp());//new LinkedList<>();
        q.offer(new Pair(p, 0));
        int mn = 0, mx = 0;
        while(!q.isEmpty()){
            int sz = q.size();
            Queue<Pair> tmp = new PriorityQueue(sz, new PairComp());
            for(int i=0;i<sz;i++){
                Pair pa = q.poll();
                mn = Math.min(mn, pa.sec);
                mx = Math.max(mx, pa.sec);
                if(!m.containsKey(pa.sec)) m.put(pa.sec, new ArrayList<>());
                m.get(pa.sec).add(pa.fir.val);
                if(pa.fir.left!=null) tmp.offer(new Pair(pa.fir.left, pa.sec-1));
                if(pa.fir.right!=null) tmp.offer(new Pair(pa.fir.right, pa.sec+1));
            }
            q = tmp;
        }
        for(int i=mn;i<=mx;i++){
            ans.add(m.get(i));
        }
        return ans;
    }
}
