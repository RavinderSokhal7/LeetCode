/*
 Single Number II
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Example 1:
Input: [2,2,3,2]
Output: 3
Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
*/
//Solution : time O(n) : space O(1): Bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once=0,twice=0;
        for(int x : nums){
            once  = (once^x)  & ~twice;
            twice = (twice^x) & ~once;
        }
        return once;
    }
};
/*
once has the numbers that appear exactly once, xor'd format (%1)
twice has numbers that appear exactly twice, xor'd format (%2)
if number appears thrice (%3) it turns zero, or precisely set bit encountered thrice is turned to zero;
*/
