/*
Numbers With Same Consecutive Differences
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.
You may return the answer in any order.

Example 1:
Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:
Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
Note:

    1 <= N <= 9
    0 <= K <= 9
*/
// time : O ( 9*2^n)
class Solution {
    private void f(int cur, int len, int n, int k, ArrayList<Integer> ans){
        if(len==n){
            ans.add(cur);
            return;
        }
        int lastDigit = cur%10;
        if(k==0){
            f(cur*10+lastDigit,len+1,n,k,ans);
            return;
        }
        if(lastDigit-k>=0 && lastDigit-k<=9)
            f(cur*10+lastDigit-k, len+1,n, k, ans);
        if(lastDigit+k>=0 && lastDigit+k<=9)
            f(cur*10+lastDigit+k, len+1,n, k, ans);
    }
    
    public int[] numsSameConsecDiff(int N, int k) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(int i=(N==1?0:1);i<=9;i++){
            f(i,1,N,k,ans);
        }
        int[] ret = new int[ans.size()];
        for(int i=0;i<ans.size();i++){
            ret[i] = ans.get(i);
        }
        // Arrays.sort(ret);
        return ret;
    }
}
