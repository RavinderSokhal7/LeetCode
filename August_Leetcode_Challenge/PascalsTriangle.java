/*
Pascal's Triangle II
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 3
Output: [1,3,3,1]
Follow up:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
    public List<Integer> getRow(int k) {
        //nCr = (nC(r-1)) * (n-r+1)/r
        List<Integer> ans = new ArrayList<Integer>();
        ans.add(1);
        for(int i=1;i<=k;i++){
            int nCr = ans.get(i-1);
            ans.add((int)((1L*nCr*(k-i+1))/i));
        }
        return ans;
    }
}
