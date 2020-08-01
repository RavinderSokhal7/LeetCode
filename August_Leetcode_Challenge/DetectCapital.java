/*
Detect Capital

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False

*/
// Solution : time : O(n)
class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.length()==0) return true;
        int n = word.length();
        int c=0,s=0;
        for(char ch:word.toCharArray()){
            if(ch>='a' && ch<='z'){
                s++;
            }
            else{
                c++;
            }
        }
        if(c==n || s==n) return true;
        if(c==1 && word.charAt(0)>='A' && word.charAt(0) <='Z') return true;
        return false;
    }
}
