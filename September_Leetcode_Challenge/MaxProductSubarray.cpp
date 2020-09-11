/*
 Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pos=1, neg=1, ans = INT_MIN;
        for(int p:nums){
            if(p>0){
                pos*=p;
                ans = fmax(ans, pos);
                if(neg<0){
                    neg*=p;
                    ans = fmax(ans, neg);
                }
                else{
                    neg = 1;
                }
            }
            else if(p<0){
                if(neg<0){
                    int tmp = pos;
                    pos = (neg*p);
                    neg = tmp*p;
                    ans = fmax(ans, pos);
                    ans = fmax(ans, neg);
                }
                else{
                    neg = fmin(neg*p, pos*p);
                    pos = 1;
                    ans = fmax(ans, neg);
                }
            }
            else{
                ans = fmax(ans, 0);
                neg = 1;
                pos = 1;
            }
        }
        return ans;
    }
};
