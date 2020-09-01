/*
 Largest Time for Given Digits
Given an array of 4 digits, return the largest 24 hour time that can be made.
The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.
Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

Example 1:
Input: [1,2,3,4]
Output: "23:41"

Example 2:
Input: [5,5,5,5]
Output: ""
Note:

    A.length == 4
    0 <= A[i] <= 9
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int hr=-1, mn=-1;
        sort(A.begin(),A.end());
        do{
            int a,b;
            a = A[0]*10 + A[1];
            b = A[2]*10 + A[3];
            if(a>=0 && a<24 && b>=0 && b<60 && (hr*100+mn < a*100+b)){
                hr = a;mn = b;
            }
        }while(next_permutation(A.begin(),A.end()));
        if(hr<0 || hr>23 || mn<0 || mn>59) return "";
        string hour = "", min = "";
        if(hr<10){
            hour += '0';
        }
        if(mn<10) min += '0';
        hour+=to_string(hr);
        min+=to_string(mn);
        return hour+":"+min;
    }
};
