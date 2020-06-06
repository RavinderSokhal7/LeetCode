/*
Queue Reconstruction by Height

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.
 

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

//Solution 1: O(n^2)
class Solution {
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> help(n),ans;
        for(int i=0;i<n;i++){
            help[i] = people[i];
            help[i].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            int m=0,h=INT_MAX,k=INT_MAX;
            for(int j=i;j<n;j++){
                if(help[j][1]<k || (help[j][1]==k && help[j][0]<h)){
                    m=j;
                    h=help[j][0];
                    k=help[j][1];
                }
            }
            swap(help[i],help[m]);
            ans.push_back(people[help[i][2]]);
            for(int j=i+1;j<n;j++){
                if(help[j][0]<=help[i][0]) help[j][1]--;
            }
        }
        
        return ans;
    }
};

// Solution 2: O(n log n)



