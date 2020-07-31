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
