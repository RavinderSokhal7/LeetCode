/*
Reconstruct Itinerary
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
Note:

    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
    One must use all the tickets once and only once.

Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/
//Solution 1: time : O(no. of edges ^ 2)
class Solution {
    bool exists = false;
    void dfs(vector<vector<string>>& tickets, vector<string> &ans,unordered_map<string,vector<int>>& g, vector<bool> & usedT, int cur_e, int e){
        if(e>=tickets.size()){
            exists = true;
            ans.push_back(tickets[cur_e][1]);
            return;
        }
        usedT[cur_e] = true;
        ans.push_back(tickets[cur_e][1]);
        string from = tickets[cur_e][1];
        for(auto p:g[from]){
            if(!usedT[p]){
                dfs(tickets,ans,g,usedT,p,e+1);
                if(exists) return;
                ans.pop_back();
            }
        }
        usedT[cur_e] = false;
        return;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int e = tickets.size(); // Edges
        vector<string> ans;
        if(e == 0) return ans;
        vector<bool> usedT(e,false); // edge is used == true;
        unordered_map<string,vector<int>> g; // graph;
        sort(tickets.begin(),tickets.end());
        for(int i=0;i<e;i++){
            g[tickets[i][0]].push_back(i);
        }
        ans.push_back("JFK");
        exists = false;
        
        for(auto p:g["JFK"]){
            if(!usedT[p]){
                dfs(tickets,ans,g,usedT,p,1); // DFS traversal with backtracking style
                if(exists) break;
                ans.pop_back();
            }
        }
        
        return ans;
    }
};
