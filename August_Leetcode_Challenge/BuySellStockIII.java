/*
*/
// Solution 1 : dp : O ( n )
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n==0) return 0;
        int [][][] dp = new int[n][3][2]; // T[ith day][Kth transaction][buy==0 / sell==1] I try to buy on ith => buy, I try to sell on ith => sell
        
        int buy = 0, sell = 1, k=2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = -1000000000;
                dp[i][j][1] = -1000000000;
            }
        }

        // set starting value
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        // fill the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // transition equation
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // you can't hold stock without any transaction
                if (j > 0) {
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = Math.max(res, dp[n - 1][j][0]);
        }

        return res;
    }
}

// Solution 2 : left right array : O ( n ) : space  : O( 2n) 
class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int n = pr.size(),mx=0,mn=INT_MAX,single=0;
        if(n==0 || n==1) return 0;
        vector<int> r(n),l(n);
        r[n-1] = 0;
        mx = fmax(mx,pr[n-1]);
        for(int i=n-2;i>=0;i--){
            mx = fmax(mx,pr[i]);
            r[i] = fmax(r[i+1],mx-pr[i]);
            single = fmax(r[i],single);
        }
        mx=0;mn=INT_MAX;
        l[0]=0;
        mn = fmin(mn,pr[0]);
        for(int i=1;i<n;i++){
            mn = fmin(mn,pr[i]);
            l[i] = fmax(l[i-1],pr[i]-mn);
            single = fmax(l[i],single);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans = fmax(ans, l[i]+r[i+1]);
        }
        
        return fmax(ans,single);
    }
};
