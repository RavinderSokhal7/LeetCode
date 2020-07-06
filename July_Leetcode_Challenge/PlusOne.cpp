/*
Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/
// Solution : time : O( n ) : space : O( 1 )
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry=1, r=0;
        if(digits[n-1]!=9){
            digits[n-1]++;
            return digits;
        }
        
        for(int i=n-1;i>=0;i--){
            r = digits[i] + carry;
            carry = r/10;
            digits[i] = r%10;
            if(carry == 0){
                break;
            }
        }
        
        if(carry!=0){
            digits.push_back(0);
            digits[0] = 1;
        }
        
        return digits;
    }
};
