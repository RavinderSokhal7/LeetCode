//1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

//Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i]
//is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left
// of the rectangular cake to the jth vertical cut.

//Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and
//verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.
/*
Constraints:

    2 <= h, w <= 10^9
    1 <= horizontalCuts.length < min(h, 10^5)
    1 <= verticalCuts.length < min(w, 10^5)
    1 <= horizontalCuts[i] < h
    1 <= verticalCuts[i] < w
    It is guaranteed that all elements in horizontalCuts are distinct.
    It is guaranteed that all elements in verticalCuts are distinct.
*/


class Solution {
    int mod = 1000000007;
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        long long int ans;
        long long int hd=0,wd=0,hn = hor.size(),wn = ver.size();
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        for(int i=0;i<hn;i++){
            if(i==0){
                hd = fmax(hd,hor[i]);
            }
            if(i==hn-1){
                if(i-1>=0)
                hd = fmax(hd,hor[i]-hor[i-1]);
                hd = fmax(hd,h-hor[i]);
            }
            if(i!=0 && i!=hn-1){
                hd = fmax(hd,hor[i]-hor[i-1]);
            }
        }
        for(int i=0;i<wn;i++){
            if(i==0){
                wd = fmax(wd,ver[i]);
                // if(i==wn-1) wd = fmax(wd,w-ver[i]);
            }
            if(i==wn-1){
                if(i-1>=0)
                    wd = fmax(wd,ver[i]-ver[i-1]);
                wd = fmax(wd,w-ver[i]);
            }
            if(i!=0 && i!=wn-1){
                wd = fmax(wd,ver[i]-ver[i-1]);
            }
        }
        // cout << hd << " " << wd << endl;
        ans = (hd%mod)*(wd%mod) %mod;
        return ans;
    }
};
