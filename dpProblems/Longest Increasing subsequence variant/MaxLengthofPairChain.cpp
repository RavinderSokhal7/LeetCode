/*
646. Maximum Length of Pair Chain
Medium

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:

    The number of given pairs will be in the range [1, 1000].

*/
//Solution 1: O(n^2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(),ans=0;
        if(n==0||n==1) return n;
        sort(pairs.begin(),pairs.end());
        // for(auto&p:pairs){
        //     cout << p[0] << " " << p[1] << endl;
        // }
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j]+1;
                }
            }
            ans = fmax(ans,dp[i]);
        }
        return ans;
    }
};

//Solution 2: O(n log n)
/* Similar to maximum no of events that can be attended.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n==0||n==1) return n;
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        vector<pair<int,int>> ans;
        ans.push_back(make_pair(pairs[0][0],pairs[0][1]));
        pair<int,int> p;
        for(int i=1;i<n;i++){
            p = ans.back();
            if(p.second<pairs[i][0]){
                ans.push_back(make_pair(pairs[i][0],pairs[i][1]));
            }
        }
        
        return ans.size(); // For no of events.. ans holds the timings of each event that should be attended
    }
};



