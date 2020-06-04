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
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* r = root,*p;
        q.push(r);
        while(!q.empty()){
            r = q.front(); q.pop();
            if(r==NULL) continue;
            swap(r->right,r->left);
            if(r->right)
                q.push(r->right);
            if(r->left)
                q.push(r->left);
        }
        return root;
    }
};
