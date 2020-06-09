/*
1048. Longest String Chain
Medium

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.
Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
Note:

    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of English lowercase letters.
*/
//Solution
class Solution {
    bool isSub(string s, string t){
        int n=t.size(),m=s.size();
        int i=0,k=0;
        while(i<n && k<m){
            if(t[i++]==s[k]) k++;
        }
        return k==m;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n==1) return n; 
        vector<int> dp (n+1,1);
        sort(words.begin(),words.end(),[](string &a,string& b){
            return a.size()<b.size();
        });
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[j].size()+1 == words[i].size() && dp[j]+1 > dp[i] && isSub(words[j],words[i])){
                    dp[i] = dp[j]+1;
                }
            }
            ans = fmax(ans, dp[i]);
        }
        return ans;
    }
};
