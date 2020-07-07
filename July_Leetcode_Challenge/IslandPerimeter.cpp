/*
Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/
//Solution : time O( n^2 )
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int ans = 0,n=grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(i==0) ans++;
                    if(i==n-1) ans++;
                    if(j==0) ans++;
                    if( j==m-1) ans++;
                    if(i-1>=0 && grid[i-1][j]==0) ans++;
                    if(i+1<n && grid[i+1][j]==0) ans++;
                    if(j-1>=0 && grid[i][j-1]==0) ans++;
                    if(j+1<m && grid[i][j+1]==0) ans++;
                }
            }
        }
        return ans;
    }
};
