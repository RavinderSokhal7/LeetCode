/*
Add Binary

Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
Constraints:

    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.
*/
//Solution : time O ( size of string )
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int na=a.size(),nb=b.size();
        int r=0,c=0;
        // int a=0,b=0;
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        int i=0,j=0;
        while(i<na || j<nb){
            r=0;
            if(i <na){
                r += (a[i]-'0');
            }
            if(j<nb){
                r += (b[j]-'0');
            }
            r+=c;
            c = r/2;
            r = r%2;
            ans += (r + '0');
            i++;j++;
        }
        if(c){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
