/*
50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
// Solution : iterative : time : O ( log n )
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0 || x==1 || n==1) return x;
        if(n<0){
            // x = 1/x;
            // n = n*(-1);
            if(n==INT_MIN){
                n+=2;
            }
            return myPow(1/x, -n);
        }
        double ans = 1;
        while(n){
            if(n&1) ans *= x;
            x*=x;
            n>>=1;
        }
        return ans;
    }
};
//Solution 2 : recursive
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || n==0) return 1;
        if(x==-1){
            if(n&1) return -1;
            else return 1;
        }
        if(n==1) return x;
        if(n==-1) return 1/x;
        double a = myPow(x,n/2);
        if(n>0)
            return a*a*((n&1)?x:1) ;
        else
            return a*a*((n&1)?(1/x):1) ;
    }
};
