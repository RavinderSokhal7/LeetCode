/*
Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 7 x 3 grid. How many possible unique paths are there?
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
*/
//Solution : DP, O(n*m): Another solution can be the mathematical formula, using PnC
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
//Solution 2: time: O(n) : space : O(n) : using math formula
class Solution {
public:
    int uniquePaths(int m, int n) {
        // ans  = (n+m)!/(n!*m!)
        m--;n--;
        int mx = fmax(n,m), mn = fmin(n,m),d=1;
        long int ans = 1;
        for(int i=mx+1; i<=mx+mn; i++){
            ans*=i;
            if(d<=mn && ans%d==0){
                ans/=d;d++;
            }
        }
        if(d<=mn){
            ans/=d;
        }
        return ans;
    }
};
