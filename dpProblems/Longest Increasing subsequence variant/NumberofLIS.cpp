/*
673. Number of Longest Increasing Subsequence
Medium

Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int. 
*/

//Solution : O(n^2), space = O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        vector<int> dp(n+1,1),cnt(n+1,1);
        // dp[0]=1;
        int m=0,ans=0,ansInd;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            if(m<dp[i]){
                m=dp[i];
            }            
        }
        for(int i=0;i<n;i++){
            if(m==dp[i]) ans += cnt[i];
        }
        return ans;
    }
};
