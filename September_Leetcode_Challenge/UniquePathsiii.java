/*
 Unique Paths III

On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

 

Note:

    1 <= grid.length * grid[0].length <= 20

*/

class Solution {
    int z = 0;
    int ans = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    private void dfs(int i, int j, int [][] grid, int cur){
        int n = grid.length, m = grid[0].length;
        if(grid[i][j]==2){
            if(cur==z) ans++;
            return;
        }
        cur++;
        grid[i][j] = 3;
        for(int k=0;k<4;k++){
            int x = i+dx[k], y = j+dy[k];
            if(x<n && x>=0 && y>=0 && y<m && grid[x][y]!=-1 && grid[x][y]!=3){
                dfs(x, y, grid, cur);
            }
        }
        grid[i][j] = 0;
    }
    public int uniquePathsIII(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        z = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) z++;
            }
        }
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,1);
                }
            }
        }
        return ans;
    }
}
