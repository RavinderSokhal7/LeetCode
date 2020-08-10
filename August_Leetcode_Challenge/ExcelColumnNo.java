/*
Excel Column No
*/
// Solution O ( n ) 
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size(),ans=0,k=0;
        for(int i=0;i<n;i++){
            ans = (ans)*26 + (s[i]-'A'+1);
        }
        return ans;
    }
};
