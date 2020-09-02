/*
Contains Duplicate III  
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
// time : O (nlog k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long int> a;
        int n=nums.size();
        if(k==0 || n==1&&k>0) return false;
        long long int tt = t;
        for(int i=0;i<n;i++){
            if(i>k) a.erase(nums[i-k-1]);
            auto it = a.lower_bound(nums[i]-tt);
            if(it!=a.end()){
                long long int x = abs(nums[i]-(*it));
                if(x<=tt) return true;
            }
            a.insert(nums[i]);
        }
        return false;
    }
};
