/*
Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

*/
//Solution : TopoLogical sort : 
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(n);
        for(auto e:prerequisites){
        	graph[e[1]].push_back(e[0]);
        }
        vector<int> indegree(n), ans;
        for(auto e:prerequisites ){
        	indegree[e[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
    		if(indegree[i]==0){
    			q.push(i);indegree[i] = -1;
    		}
    	}
        while(!q.empty()){
        	int p = q.front();q.pop();
        	for(auto x:graph[p]){
        		indegree[x]--;
        		if(indegree[x]==0) q.push(x);
        	}
        	ans.push_back(p);
        }
        if(ans.size() < n) return vector<int> ();
        return ans;
    }
};
