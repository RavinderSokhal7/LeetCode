/*
Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true

Example 2:

Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?
*/
// Solution : time : O ( 1 )
class Solution {
    public boolean isPowerOfFour(int n) {
        int mask = 0x55555555;
        if(((n&(n-1)) == 0)&&(n&mask)>0) return true;
        return false;
    }
}
