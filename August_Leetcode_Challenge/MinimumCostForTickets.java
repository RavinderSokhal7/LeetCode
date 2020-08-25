/*
Minimum Cost For Tickets
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.
Train tickets are sold in 3 different ways:
    a 1-day pass is sold for costs[0] dollars;
    a 7-day pass is sold for costs[1] dollars;
    a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.
Note:

    1 <= days.length <= 365
    1 <= days[i] <= 365
    days is in strictly increasing order.
    costs.length == 3
    1 <= costs[i] <= 1000
*/

//Solution : O ( n^2 ) : Space : O ( n )
class Solution {
    private int helper(int cur, int[] days, int[] costs, int [] dp){
        int n = days.length;
        if(cur==n){
            return 0;
        }
        if(dp[cur]!=-1) return dp[cur];
        int op1=0, op2=costs[1], op3=costs[2];
        op1 = costs[0] + helper(cur+1,days,costs,dp);
        int sev=-1, mon=-1;
        for(int i=cur+1;i<n;i++){
            if(sev==-1 && days[i] - days[cur] + 1 > 7){
                sev = i;
            }
            if(mon==-1 && days[i]-days[cur]+1>30){
                if(sev==-1){
                    sev = i;
                }
                mon = i;
                break;
            }
        }
        if(sev!=-1)
            op2 += helper(sev,days, costs, dp);
        if(mon!=-1)
            op3 += helper(mon,days, costs, dp);
        return ( dp[cur] = Math.min(op1, Math.min(op2,op3)));
    }
    
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        if(n==0) return 0;
        int [] dp = new int[n+1];
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        return helper(0,days,costs,dp);
    }
}
