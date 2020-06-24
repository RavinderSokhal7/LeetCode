/*
Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
//Solution : O(n^2)
class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1 || n==2) return n;
        vector<long int> dp(n+1,0);
        dp[0] = 1;dp[1] = 1;dp[2] = 2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};
/*
consider different roots for each BST with n nodes;
ex : n=4:
      1                    2                  3                       4
    /   \      +         /   \      +       /    \         +         /   \
ans[0] * ans[3]     ans[1] * ans[2]      ans[2] * ans[1]         ans[3] * ans[0]
*/
