/*
Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
// Solution : time : O(n) : space O(n) ( can be easily optimised to O( 1 ) )
/*
T[day][buy] = max( T[i-2][sell]-p[i], T[i-1][buy] );
T[day][sell] = max( T[i-1][buy] + p[i], T[i-1][sell] );
*/

class Solution {
    public int maxProfit(int[] p) {
        int n = p.length;
        if(n==0 || n==1) return 0;
        int [] buy = new int[n];
        int [] sell = new int[n];
        
        buy[0] = -p[0];
        sell[0] = 0;
        for(int i=1;i<n;i++){
            int x=0;
            if(i>1) x = sell[i-2];
            buy[i] = Math.max(buy[i-1], x - p[i]);
            sell[i] = Math.max(sell[i-1], buy[i-1] + p[i]);
        }
        return Math.max(buy[n-1],sell[n-1]);
    }
}
