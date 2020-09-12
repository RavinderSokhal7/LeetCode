/*
Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Note:

    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
    void dfs(int i, int k, int n, vector<int> t, vector<vector<int> > & ans){
        if(n<=0 || k==0) return;
        // if(i==9 && n!=9)
        if(n==i && k==1){
            t.push_back(i);
            ans.push_back(t);
            return;
        }
        if(i>n) return;
        if(i<9){
            t.push_back(i);
            dfs(i+1, k-1, n-i, t, ans);
            t.pop_back();
            dfs(i+1, k, n, t, ans);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        dfs(1, k, n, vector<int> (), ans);
        return ans;
    }
};
