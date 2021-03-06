/*
 Implement Rand10() Using Rand7()
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
Do NOT use system's Math.random().
Example 1:
Input: 1
Output: [7]

Example 2:
Input: 2
Output: [8,4]

Example 3:
Input: 3
Output: [8,1,10]
Note:
    rand7 is predefined.
    Each testcase has one argument: n, the number of times that rand10 is called.
*/
//solution 1
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int u = 0;
        for(int i=0;i<70;i++){
            u+=rand7();
        }
        u%=10;
        u+=1;
        return u;
    }
}

// solution 2
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int first = rand7();
        while (first == 4) {
            first = rand7();
        }
        if (first < 4) {
            // 1-5
            int second = rand7();
            while (second == 6 || second == 7) {
                second = rand7();
            }
            return second;
        } else {
            // 6-10
            int second = rand7();
            while (second == 6 || second == 7) {
                second = rand7();
            }
            return second + 5;
        }
    }
}
