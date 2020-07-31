/*
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
Constraints:

    1 <= n <= 45

*/
//Solution : time : O( n ) : space : O ( n ) : DP
class Solution {
    public int climbStairs(int n) {
        if(n==0||n==1) return 1;
        int [] ans = new int[n+1]; // better to use long but as per constraint int will suffice, no overflow
        ans[0] = ans[1] = 1;
        ans[2] = 2;
        int i = 3;
        while(i<n+1){
            ans[i] = ans[i-1]+ans[i-2];
            i++;
        }
        return ans[n];
    }
}

// Solution 2 : time : O ( n ) : space : O ( 1 )
class Solution {
    public int climbStairs(int n) {
        if(n==0||n==1) return 1;
        int ans=2, pre1 = 2, pre2 = 1;
        int i = 3;
        while(i<n+1){
            ans = pre1 + pre2;
            pre2 = pre1;
            pre1 = ans;
            i++;
        }
        return ans;
    }
}
//Solution 3 : time : O ( log n ) : space : O ( 1 ) :: Bilet's method  :: Matrix Multiplicatoin
class Solution {
    
    private void multiply(int [][] ans, int [][] q){
        int a = 0,b=0,c=0,d=0;
        a = ans[0][0]*q[0][0] + ans[0][1]*q[1][0];
        b = ans[0][0]*q[0][1] + ans[0][1]*q[1][1];
        c = ans[1][0]*q[0][0] + ans[1][1]*q[1][0];
        d = ans[1][0]*q[0][1] + ans[1][1]*q[1][1];
        ans[0][0] = a;
        ans[0][1] = b;
        ans[1][0] = c;
        ans[1][1] = d;
    }
    
    private void powM(int[][] ans, int n){
        if(n==0 || n==1) return;
        int [][]q = {{1,1}, {1,0}};
        while(n>0){
            if((n&1)==1){
                multiply(ans,q);
            }
            multiply(q,q);
            n/=2;
        }
    }
    
    public int climbStairs(int n) {
        if(n==0||n==1) return 1;
        if(n==2) return 2;
        int [][] ans = {{1,1} , {1,1}};
        powM(ans,n-1);
        return ans[0][0];
    }
}
// solution 4 : using Fibonacci formula
