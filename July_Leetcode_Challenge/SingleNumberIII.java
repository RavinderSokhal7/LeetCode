/*
Single Number III
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:
    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
// Solution : time : O ( n ) : space : o ( 1 )
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] ans = new int[] {0,0};
        int n = nums.length;
        int x=0;
        for(int p:nums){
            x^=p;
        }
        // x contains both single numbers xor'd together
        int mask_bit = 0;// first bit in x which is set
        for(int i=0;i<32;i++){
            if((x&(1<<i)) > 0){
                mask_bit = i;
                break;
            }
        }
        //so one number has that bit set and other doesn't, so two groups
        for(int p:nums){
            if((p&(1<<mask_bit)) > 0){
                ans[0]^=p;
            }
            else{
                ans[1]^=p;
            }
        }
        return ans;
    }
}
