/*
Reverse Words in a String
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up:
For C programmers, try to solve it in-place in O(1) extra space.
*/
//Time complexity is O ( n ), because in the worst case traversing and reversing will cause 2*n iteration.
//( Correct me if the time complexity is wrong )
// Solution : time : O( n ) : space : O ( 1 )
char * reverseWords(char * s){
    int n = strlen(s);
    if(n==0) return s;
    int i=0;
    while(i<n){
        while(i<n && s[i]==' ') i++;
        int l=i,h=i;
        while(i<n && s[i]!=' ') i++;
        h = i-1;
        // reverse(s.begin()+l, s.begin()+h);
        while(l<h){
            char t = s[l];
            s[l] = s[h];
            s[h] = t;
            l++;h--;
        }
    }
    int l = 0,h = n-1;
    // reverse whole string
    while(l<h){
        char t = s[l];
        s[l] = s[h];
        s[h] = t;
        l++;h--;
    }
    int p=0;i=0;
    // move all extra spaces to back of string
    while(i<n){
        while(i<n && s[i]==' ') i++;
        while(i<n && s[i]!=' ') s[p++] = s[i++];
        if(i<n){
            s[p++] = s[i++];
        }
    }
    // any extra char that was added in front and is left at the back is converted to space
    while(p<n){
        s[p++] = ' ';
    }
    // put NULL character at correct end of string, trimming trailing spaces
    i = n-1;
    if(s[i]==' '){
        while(i>=0 && s[i]==' ') i--;
        s[i+1] = '\0';
    }
    return s;
}
