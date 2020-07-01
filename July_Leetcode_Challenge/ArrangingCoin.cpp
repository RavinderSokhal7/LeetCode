/*
Arranging Coins
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.
Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.
Example 2:
n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
*/
//Solution 1: time : O(n)
class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0||n==1) return n;
        long int ans=1,sum=1;
        while(sum<=n){
            ans++;
            sum+=ans;
        }
        return ans-1;
    }
};
// Solution 2: time : O(sqrt(n))
class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0||n==1) return n;
        long long int fourAC = 4*1ll*2*n;
        return (sqrt(fourAC+1)-1)/2;
    }
};
//Solution 3: time : O(log n)
class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0||n==1) return n;
        long long int low = 0, high = n, mid = 0, ans = 1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*(mid+1)/2 <= n){
                low = mid+1; ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
