/*
740. Delete and Earn
Medium

Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:

    The length of nums is at most 20000.
    Each element nums[i] is an integer in the range [1, 10000].
*/
// Solution : O(n^2) time, O(n) space
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(auto&p:nums){
            m[p]++;
        }
        int d=m.size();
        if(d==1) return m[nums[0]]*nums[0];
        
        vector<int> dp(d+1,0),v;
        for(auto&p:m){
            v.push_back(p.first);
        }
        sort(v.begin(),v.end());
        int ans=0;
        dp[0] = v[0]*m[v[0]];
        for(int i=0;i<d;i++){
            for(int j=0;j<i;j++){
                if( v[j]!=v[i]-1 && v[j]!=v[i]+1 && dp[i] < dp[j]+(v[i]*m[v[i]]) ){
                    dp[i] = dp[j]+(v[i]*m[v[i]]);
                }
            }
            if(dp[i]==0){
                dp[i] = v[i]*m[v[i]];
            }
            ans = fmax(ans,dp[i]);
        }
        
        return ans;
    }
};

// Solution 2: Time: O(n), space: O(n)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int maxN=INT_MIN;
        for(int i=0;i<n;i++){
            maxN = fmax(maxN,nums[i]);
        }
        vector<int> sums(maxN+1,0), dp(maxN+1,0);
        for(int i=0;i<n;i++){
            sums[nums[i]] += nums[i];
        }
        int maxSoFar = 0,ans=INT_MIN;
        for(int i=1;i<=maxN;i++){
            dp[i] = sums[i] + maxSoFar;
            maxSoFar = fmax(maxSoFar,dp[i-1]);
            ans = fmax(ans,dp[i]);
        }
        return ans;
    }
};



