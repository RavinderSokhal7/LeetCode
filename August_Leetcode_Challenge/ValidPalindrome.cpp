/*
Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

 

Constraints:

    s consists only of printable ASCII characters.
*/
// Solution
class Solution {
    bool isPal(string p){
        if(p.size() == 0) return true;
        int f=0,r = p.size()-1;
        while(f<r){
            if(p[f]!=p[r]) return false;
            f++;r--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string p = "";
        for(char c:s){
            if(isalnum(c)){
                p+=tolower(c);
            }
        }
        if(isPal(p)) return true;
        return false;
    }
};
