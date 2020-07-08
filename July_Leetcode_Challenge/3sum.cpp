/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
//Solution best : time : O(n^2) : space(O(1)) only used space for answer
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length;
        if(n<3) return ans;
        Arrays.sort(nums);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            if(nums[i]>0) break;
            int f=i+1,r=n-1,sum=0;
            while(f<r){
                sum = nums[i] + nums[f] + nums[r];
                
                if(sum == 0){
                    ans.add(Arrays.asList(nums[i], nums[f], nums[r]));
                    while(f+1<r-1 && nums[f+1]==nums[f] && nums[r-1]==nums[r]){
                        f++;r--;
                    }
                }
                
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    f++;
                }
                else {
                    f++;r--;
                }
            }
        }
        return ans;
    }
}
