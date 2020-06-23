/*
Count Complete Tree Nodes
Given a complete binary tree, count the number of nodes.
Note:
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/
//Solution: time : O(no of nodes) : but not using fact of complete tree
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return ( countNodes(root->left) + countNodes(root->right) + 1 );
    }
};

//Solution 2: using fact of complete tree for  pruning, time : W(no of nodes/2)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = 0, rh = 0;
        TreeNode* p = root;
        while(p->left){
            p = p->left;
            lh++;
        }
        p = root;
        while(p->right){
            p = p->right;
            rh++;
        }
        if(lh==rh){
            return pow(2,lh+1)-1;
        }
        return ( countNodes(root->left) + countNodes(root->right) + 1 );
    }
};
