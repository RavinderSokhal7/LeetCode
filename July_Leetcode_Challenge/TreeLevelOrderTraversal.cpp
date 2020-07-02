/*
Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*/

//Solution : time O(#nodes in tree)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* r){
        if(!r) return 0;
        return fmax(height(r->left), height(r->right)) + 1;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>> ();
        int h = height(root);
        vector<vector<int>> ans(h);
        queue<TreeNode*> q;
        TreeNode* p = root;
        q.push(p);q.push(NULL);
        int index = h-1;
        while(!q.empty()){
            p = q.front();q.pop();
            if(!p){
                if(q.empty()) break;
                q.push(p);
                index--;
                continue;
            }
            ans[index].push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return ans;
    }
};
