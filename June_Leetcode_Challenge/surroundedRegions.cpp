/*
Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
class Solution {
    void dfs(vector<vector<char>>& board, int i, int j){
        int n = board.size(),m = board[0].size();
        if(i<0||j<0||i>n-1||j>m-1||board[i][j]=='X'||board[i][j]=='R') return;
        board[i][j] = 'R';
        dfs(board,i,j+1);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i-1,j);
    }
    void dfso(vector<vector<char>>& board, int i, int j){
        int n = board.size(),m = board[0].size();
        if(i<0||j<0||i>n-1||j>m-1||board[i][j]=='X'||board[i][j]=='O') return;
        board[i][j] = 'O';
        dfso(board,i,j+1);
        dfso(board,i+1,j);
        dfso(board,i,j-1);
        dfso(board,i-1,j);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][m-1]=='O') dfs(board,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[n-1][i]=='O') dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='R') dfso(board,i,0);
            if(board[i][m-1]=='R') dfso(board,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='R') dfso(board,0,i);
            if(board[n-1][i]=='R') dfso(board,n-1,i);
        }         
    }
};

/*
["X","O","X","O","X","O"]
["O","X","O","X","O","X"]
["X","O","X","O","X","O"]
["O","X","O","X","O","X"]
*/
