/*
Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
//Solution 1: time O(n*sqrt(n)) : similar to coin change
class Solution {
    int helper(int j, int i, vector<vector<int>>& dp, vector<long int> & ps){
        if(i<0 && j==0) return 0;
        if(i<0) return INT_MAX;
        if(dp[i][j]) return dp[i][j];
        if(ps[i]<=j)
            dp[i][j] = fmin( 1+helper(j-ps[i],i,dp,ps), helper(j,i-1,dp,ps));
        else
            dp[i][j] = helper(j,i-1,dp,ps);
        return dp[i][j];
    }
public:
    int numSquares(int n) {
        vector<long int> ps;
        long int p=1;
        for(int i=1;p<=n;i++){
            p = i*i;
            if(p<=n)
                ps.push_back(p);
        }
        int sz = ps.size();
        vector<vector<int>> dp(sz, vector<int> (n+1,0));
        return helper(n,sz-1,dp,ps);
    }
};
