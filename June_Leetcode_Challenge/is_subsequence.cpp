/*
Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
Constraints:

    0 <= s.length <= 100
    0 <= t.length <= 10^4
    Both strings consists only of lowercase characters.
*/
//Solution 1: time : O(n^2) => find LCS of t & s and check if s.size() == LCS
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int x=0;
        for(int i=0;i<n;i++){
            if(s[0] == t[i])
                x=1;
            dp[i][0] = x;
        }
        x=0;
        for(int i=0;i<m;i++){
            if(s[i] == t[0])
                x=1;            
            dp[0][i] = x;
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s[j] == t[i]){
                    dp[i][j] = fmax(dp[i-1][j-1]+1,fmax(dp[i-1][j],dp[i][j-1]));
                }
                else{
                    dp[i][j] = fmax(dp[i-1][j-1],fmax(dp[i-1][j],dp[i][j-1]));
                }
                ans = fmax(dp[i][j],ans);
                if(ans==m) return true;
            }
        }
        return ans==m;
    }
};

//Solution 2: time : O(n)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        if(m>n) return false;
        int k=0,i=0;
        while(k<m && i<n){
            if(t[i]==s[k]) k++;
            i++;
        }
        return k==m;
    }
};
