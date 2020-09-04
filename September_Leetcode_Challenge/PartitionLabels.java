/*
Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

 

Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.

*/

class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> ans = new ArrayList<>();
        int n = S.length();
        if(n==0) return ans;
        if(n==1){
            ans.add(1); return ans;
        }
        int [][] g = new int[27][3];
        for(int i=0;i<27;i++){
            g[i][0] = g[i][1] = g[i][2] = -1;
        }
        for(int i=0;i<n;i++){
            char c = S.charAt(i);
            if(g[c-'a'][1]==-1){
                g[c-'a'][0] = g[c-'a'][1] = i;
                g[c-'a'][2] = c-'a';
            }
            else{
                g[c-'a'][1] = i;
            }
        }
        Arrays.sort(g, new Comparator<int[]> (){
            public int compare( int [] a, int [] b){
                return a[0]-b[0];
            }
        });
        int s=-1, f=-1;
        for(int i=0;i<27;i++){
            if(g[i][0]==-1) continue;
            if(s==-1){
                s=g[i][0];f=g[i][1];
            }
            else if(g[i][0] < f){
                f = Math.max(f,g[i][1]);
            }
            else{
                ans.add(f-s+1);
                s = g[i][0]; f = g[i][1];
            }
            if(i==26){
                ans.add(f-s+1);
            }
        }
        return ans;
    }
}
