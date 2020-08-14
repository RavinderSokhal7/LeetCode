/*
Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"
Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        HashMap<Character, Integer> m = new HashMap<>();
        for(char c : s.toCharArray()){
            int x = 1;
            if(m.containsKey(c)) x += m.get(c);
            m.put(c,x);
        }
        int maxOdd = 0;
        int total = 0;
        for(Map.Entry<Character, Integer> entry : m.entrySet()){
            int val = entry.getValue();
            if(val%2==0){
                total+=val;
            }
            else{
                total += (val/2)*2;
                maxOdd = Math.max(maxOdd, val);
            }
        }
        if(maxOdd>0){
            total++;
        }
        return total;
    }
}
