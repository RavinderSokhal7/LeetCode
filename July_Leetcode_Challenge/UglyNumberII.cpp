/*
Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.
*/
//Solution 1 : using queues : time : O(n) : space : O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        queue<int> a,b,c;// a for multiples of 2, bfor multiples of 3, c for multiples of 5
        a.push(1);b.push(1);c.push(1);
        int i=0,j=0,k=0,ans = 1;
        for(int x=1;x<n;x++){
            i = a.front()*2;
            j = b.front()*3;
            k = c.front()*5;
            ans = fmin(i, fmin(j,k));
            a.push(ans);b.push(ans);c.push(ans);
            if(ans == i){
                a.pop();
            }
            if(ans == j){
                b.pop();
            }
            if(ans == k){
                c.pop();
            }
        }
        return ans;
    }
};

//Solution 2 : time : O(n) : space optimized

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> ugly(1,1);
        int i=0,j=0,k=0,ans = 1;
        for(int x=1;x<n;x++){
            ans = fmin(ugly[i]*2, fmin(ugly[j]*3, ugly[k]*5));
            ugly.push_back(ans);
            if(ans == ugly[i]*2){
                i++;
            }
            if(ans == ugly[j]*3){
                j++;
            }
            if(ans == ugly[k]*5){
                k++;
            }
        }
        return ans;
    }
};
