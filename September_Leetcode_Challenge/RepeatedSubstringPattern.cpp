/*
Repeated Substring Pattern
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:

Input: "aba"
Output: False

Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)


*/
class Solution {
    bool check(string s, int i){
        string a = s.substr(i+1);
        string b = s.substr(0,i+1);
        return s==(a+b);
    }
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(n%(i+1)==0 && check(s, i)) return true;
        }
        return false;
    }
};
