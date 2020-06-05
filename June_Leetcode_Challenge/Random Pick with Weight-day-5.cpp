/*

Random Pick with Weight

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

    1 <= w.length <= 10000
    1 <= w[i] <= 10^5
    pickIndex will be called at most 10000 times.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/



//Solution O(n)

class Solution {
    vector<int> sumInd;
public:
    Solution(vector<int>& w) {
        if(w.size()!=0)
            sumInd.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            sumInd.push_back(w[i]+sumInd[i-1]);
        }
    }
    
    int pickIndex() {
        return ( upper_bound(sumInd.begin(),sumInd.end(),rand()%sumInd.back()) - sumInd.begin() );
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/*
// Solution O(n^2) TLE

class Solution {
    vector<int> bagInd;
public:
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i];j++){
                bagInd.push_back(i);
            }
        }
    }
    
    int pickIndex() {
        next_permutation(bagInd.begin(),bagInd.end());
        int i = rand()%bagInd.size();
        return bagInd[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */




