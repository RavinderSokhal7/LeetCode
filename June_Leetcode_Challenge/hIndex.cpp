/*
H-Index II
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
Example:
Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note:
If there are several possible values for h, the maximum one is taken as the h-index.
Follow up:
    This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
    Could you solve it in logarithmic time complexity?
*/
//Solution 1: time : O(nlog n)
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n==0) return 0;
        for(int i=n;i>=1;i--){
            auto it = lower_bound(c.begin(),c.end(),i);
            if(it!=c.end()){
                int x = it-c.begin()+1;
                if(n-x+1>=i) return i;
            }
        }
        return 0;
    }
};

//Solution 2: time :O(log n)
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n==0) return 0;
        int l=0,h=n-1;
        while(l<=h){
            int m = (l+h)/2;//(l>>1) + (h>>1);// ALWAYS better to use -
          /*
          * l+(h-l)/2 => for lower mid (when no of elements are even so two mids, lower and higher)
          * l+(h-l+1)/2 => for higher mid
          * must consider checking for cases where infinite loop may occur due to while condition
          */
            if(c[m] == n-m) return n-m;
            else if(c[m] < n-m) l = m+1;
            else h = m-1;
        }
        return n-l;
    }
};


