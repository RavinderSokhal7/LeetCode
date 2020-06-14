/*
 Cheapest Flights Within K Stops

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Constraints:

    The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
    The size of flights will be in range [0, n * (n - 1) / 2].
    The format of each flight will be (src, dst, price).
    The price of each flight will be in the range [1, 10000].
    k is in the range of [0, n - 1].
    There will not be any duplicated flights or self cycles.
*/
//Solution:
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<flights.size();i++){
            g[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }
        queue <pair<int,int>> q;
        q.push({src,0});
        q.push({-1,-1});
        int steps=-1,minCost=INT_MAX;
        while(!q.empty()){
            pair<int,int> pa = q.front();q.pop();
            int p = pa.first;int curCost = pa.second;
            if(p==-1){
                steps++;
                if(steps>k) break;
                if(!q.empty())
                    q.push({-1,-1});
                continue;
            }
            if(p==dst && steps<=k){
                minCost = fmin(minCost,curCost);
                continue;
            }
            for(auto s:g[p]){
                if(steps<=k && curCost+s.second < minCost)
                    q.push({s.first,curCost+s.second});
            }
        }
        if(minCost==INT_MAX) return -1;
        return minCost;
    }
};
