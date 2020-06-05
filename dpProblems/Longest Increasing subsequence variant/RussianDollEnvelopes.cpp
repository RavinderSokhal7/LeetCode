/*
354. Russian Doll Envelopes
Hard

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

//Solution 1: Time : O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(),ans=1;
        if(n==0) return 0;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        
        vector<int> dp(n+1,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if( envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>ans) ans = dp[i];
        }
        
        return ans;
    }
};

//Solution 2: Time: O(n log n)

#define pb push_back
#define mp make_pair
#define env envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0])
                return a[1]>b[1]; //********imp**********
            return a[0]<b[0];
        });
        // for(auto&e:env){
        //     cout << e[0] << " " << e[1] << endl;
        // }
        vector<int> ans;
        
        ans.pb(env[0][1]);
        
        for(int i=1;i<n;i++){
            auto it = lower_bound(ans.begin(),ans.end(),env[i][1]);
            if(it == ans.end()){
                ans.pb(env[i][1]);
            }
            else{
                *it = env[i][1];
            }
        }
        
        return ans.size();
    }
};







