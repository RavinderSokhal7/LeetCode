//Two City Scheduling

//There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

//Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

class Solution {
    // int dp[101][60][60];
    // int help(vector<vector<int>>& costs, int i, int n1, int n2){
    //     if(i<0 || n1<0 || n2<0 ||(n1==0 && n2 ==0)) return 0;
    //     if(dp[i][n1][n2] != 0) return dp[i][n1][n2];
    //     if(n1 == 0){
    //         return dp[i][n1][n2] = costs[i][1] + help(costs,i-1,n1,n2-1);
    //     }
    //     if(n2 == 0){
    //         return dp[i][n1][n2] = costs[i][0] + help(costs,i-1,n1-1,n2);
    //     }
    //     return dp[i][n1][n2] = ( fmin( costs[i][1] + help(costs,i-1,n1,n2-1), costs[i][0] + help(costs,i-1,n1-1,n2) ) );
    // }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2, N = costs.size();
        vector<pair<int,int>> v;
        for(int i=0;i<N;i++){
            v.push_back(make_pair(costs[i][0]-costs[i][1],i));
        }
        sort(v.begin(),v.end());
        int ans =0;
        for(int i=0;i<n;i++){
            ans += costs[v[i].second][0] + costs[v[i+n].second][1];
        }
        return ans;
    }
};
