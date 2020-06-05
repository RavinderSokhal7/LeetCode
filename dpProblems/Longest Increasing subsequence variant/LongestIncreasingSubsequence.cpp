/*

300. Longest Increasing Subsequence
Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:

    There may be more than one LIS combination, it is only necessary for you to return the length.
    Your algorithm should run in O(n2) complexity.

*/

// DP solution : time : O(n^2)
#define pb push_back

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        if(n==0) return 0;
        int ans = 1;
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = fmax(dp[i],dp[j]+1);
                }
            }
            ans = fmax(ans,dp[i]);
        }
        return ans;
    }
};

/*

Follow up: Could you improve it to O(n log n) time complexity?

*/
// time : O(n*log(n))
#define pb push_back

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        if(n==0) return 0;
        vector<int> lis;
        lis.pb(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis[lis.size()-1]) lis.pb(nums[i]);
            else{
                auto it = lower_bound(lis.begin(),lis.end(),nums[i]);   //log(n)
                *it = nums[i];
            }
        }
        return lis.size();
    }
};






