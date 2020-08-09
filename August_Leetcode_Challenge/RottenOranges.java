/*
Rotten Oranges
*/
class Pair{
    int x;
    int y;
    Pair(int a, int b){
        x = a; y = b;
    }
}

class Solution {
    private static int [] mx = {0,0,1,-1};
    private static int [] my = {1,-1,0,0};
    
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        if(n==0) return 0;
        int m = grid[0].length;
        if(m==0) return 0;
        Queue<Pair> q = new LinkedList<>();
        boolean one = false, two = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.offer(new Pair(i,j));two = true;
                }
                else if(grid[i][j] == 1){
                    one = true;
                }
            }
        }
        if(!one) return 0;
        if(!two) return -1;
        one = false;
        int ans = 0;
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Pair p = q.poll();
                int x = p.x, y = p.y;
                for(int a=0;a<4;a++){
                    int g = x+mx[a], h = y+my[a];
                    if( g>=0 && g< n && h<m && h>=0 && grid[g][h]==1){
                        grid[g][h] = 2;
                        q.offer(new Pair(g,h));
                    }
                }
            }
            ans++;
        }
        ans--;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    one = true;
                }
            }
        }
        if(one) ans = -1;
        return ans;
    }
}
