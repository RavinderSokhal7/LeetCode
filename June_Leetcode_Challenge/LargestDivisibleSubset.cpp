/*
Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/
//Solution: Dp LIS variant

#define pb push_back
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(),ansLen=1,ansInd=0;
        if(n==0 || n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> ans,dp(n+1,1),par(n+1,-1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1 ){
                    dp[i] = dp[j]+1;
                    par[i]=j;
                }
            }
            if(ansLen<dp[i]){
                ansLen = dp[i];
                ansInd = i;
            }
        }
        
        while(ansInd!=-1){
            ans.pb(nums[ansInd]);
            ansInd = par[ansInd];
        }
        
        return ans;
    }
};
