/*
Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0

Note:

    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?
*/
// Solution : time :  0 ( log n ) : O ( n )
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n==0) return -1;
        if(n==1) return nums[0];
        int ans = Integer.MAX_VALUE;
        int l=0, h=n-1;
        while(l<=h){
            while(l<h && l<n-1 && nums[l] == nums[l+1]) l++;
            while(h>l && h>0 && nums[h-1] == nums[h]) h--;
            int m = l + (h-l)/2;
            ans = Math.min(ans,nums[m]);
            if(nums[h]>nums[m]){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
}
