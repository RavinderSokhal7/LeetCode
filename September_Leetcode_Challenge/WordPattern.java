/*
Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

*/
// Time : O ( n ), Space : O ( N )
class Solution {
    public boolean wordPattern(String pattern, String str) {
        int np = pattern.length(), ns = str.length();
        String [] v = str.split(" ");
        int nv = v.length;
        if(np!=nv) return false;
        HashMap<Character, String> m1 = new HashMap<>(); // char=> index of str in v
        HashMap<String, Character> m2 = new HashMap<>();
        for(int i=0;i<np;i++){
            char c = pattern.charAt(i);
            String s = v[i];
            if(m1.containsKey(c)){
                if(!m2.containsKey(s) || !s.equals(m1.get(c))){
                    return false;
                }
            }
            else{
                if(m2.containsKey(s)) return false;
                m1.put(c,s);
                m2.put(s,c);
            }
        }
        return true;
    }
}
