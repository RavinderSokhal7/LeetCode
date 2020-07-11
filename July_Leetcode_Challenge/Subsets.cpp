/*
Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
//Solution : time : O ( 2^n )
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
       
        int n=v.size();
        int tp =pow(2,n);
        vector<vector<int>>v1;
        vector<int>temp;
        vector<int>temp2;
        for(int i=0;i<tp;i++)
        {       
            int x=i;
            while(x)
            {
                temp.push_back(x%2);
                x=x/2;
            }
            int z = (temp.size());
            for(int j=0;j<n-z;j++)
            {
                temp.push_back(0);
            }
            for(int k=0;k<n;k++)
            {
                if(temp[k]==1)
                {
                    temp2.push_back(v[k]);
                }
            }
            v1.push_back(temp2);
            temp.clear();
            temp2.clear();
        }
        return v1;
    }
};
