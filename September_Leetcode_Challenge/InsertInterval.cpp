/*
Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int f = newInterval[0], r = newInterval[1];
        // cout << f << " " << r << endl;
        bool ins = true;
        for(auto e : intervals){
            if(ins){
                if(r<e[0]){
                    ins = false;
                    vector<int> t(2, f);
                    t[1] = r;
                    ans.push_back(t);
                }
                else if(f>=e[0] && r<=e[1]){
                    // cout << "here";
                    // f = fmin(f,e[0]);
                    // r = fmax(r,e[1]);
                    ins = false;
                }
                else if(f<=e[1] && f>=e[0]){a
                    f = fmin(f,e[0]);
                    r = fmax(r,e[1]);
                    continue;
                }
                else if(r>=e[0] && r<=e[1]){
                    f = fmin(f,e[0]);
                    r = fmax(r,e[1]);
                    continue;
                }
                else if(f<e[0] && r>e[1]) continue;
            }
            ans.push_back(vector<int> (e ));
            // cout << "$";
        }
        if(ins){
            vector<int> t(2, f);
            t[1] = r;
            ans.push_back(t);
        }
        return ans;
    }
};