/*
 Random Point in Non-overlapping Rectangles

Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

    An integer point is a point that has integer coordinates. 
    A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
    ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
    length and width of each rectangle does not exceed 2000.
    1 <= rects.length <= 100
    pick return a point as an array of integer coordinates [p_x, p_y]
    pick is called at most 10000 times.

Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]

Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

*/
//Solution : time : O ( n ) for constructor , O ( log n ) for pick : space : O ( n )
/*
For uniform distribution the rectangle with more area should have higher probability of being selected, So select a rectangle first.
Then its point at random.
selection of rectangle must be a probability of wieght(#ofpoints in rectangle)
*/
class Solution {
    vector<long long int> a; // no of points in rect
    vector<vector<int> > recs;
    long long int area(vector<int> &r){
        return 0LL + (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }
public:
    Solution(vector<vector<int>>& rects) {
        recs = rects;
        for(vector<int> &r : rects){
            a.push_back(area(r) + ((a.size()>0)?a.back() : 0));
        }
    }
    
    vector<int> pick() {
        int n = recs.size();
        long long int s = rand()%a.back();
        int i = upper_bound(a.begin(),a.end(),s) - a.begin();
        vector<int> p(2,0);
        p[0] = recs[i][0] + (rand()%(recs[i][2]-recs[i][0]+1));
        p[1] = recs[i][1] + (rand()%(recs[i][3]-recs[i][1]+1));
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
