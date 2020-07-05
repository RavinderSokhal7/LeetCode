/*
Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231.
Example:
Input: x = 1, y = 4

Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/
//Solution 1 : time : O(1), constant to iterate over 32 bits
class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming_distance = 0;
        for(int i=0;i<32;i++){
            int mask = (1<<i);
            if((x&mask) != (y&mask)) hamming_distance++;
        }
        return hamming_distance;
    }
};


// Solution 2: time : O(1), number of '1's in x^y, a better solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0, n = x^y;
        while(n){
            ans++;
            n = n&(n-1);
        }
        return ans;
    }
};
