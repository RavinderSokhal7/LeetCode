/*
Maximum Width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
 
*/
//Solution 1 : time O( 2^n ) i.e, #nodes if it was a full tree  : Space : O( 2^(n-1) )
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        deque<TreeNode*> dq;
        dq.push_back(root);
        TreeNode* p;
        while(!dq.empty()){
            while(!dq.front()){
                dq.pop_front();
            }
            if(dq.empty()) break;
            while(!dq.back()){
                dq.pop_back();
            }
            if(dq.empty()) break;
            ans = fmax(ans,dq.size());
            deque<TreeNode*> dq2;
            while(!dq.empty()){
                if(dq.front()==NULL){
                    dq2.push_back(NULL);
                    dq2.push_back(NULL);
                }
                else{
                    dq2.push_back(dq.front()->left);
                    dq2.push_back(dq.front()->right);
                }
                dq.pop_front();
            }
            swap(dq2,dq);
        }
        return ans;
    }
};

// Solution 2 : Better : time : O( #nodes ) : space : O( max #nodes at one level )
//Idea is similar to making a tree with array with root at index 1:
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        TreeNode* p = root;
        queue<pair<unsigned long long int, TreeNode*>> q;
        q.push({1,p});
        unsigned long long int left=0,right=0;
        while(!q.empty()){
            left = q.front().first;
            p = q.front().second;
            right = left;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                p = q.front().second;
                right = q.front().first;
                q.pop();
                if(p->left){
                    q.push({2*right, p->left});
                }
                if(p->right){
                    q.push({2*right+1, p->right});
                }
            }
            ans = fmax(ans, right-left+1);
        }
        return ans;
    }
};
