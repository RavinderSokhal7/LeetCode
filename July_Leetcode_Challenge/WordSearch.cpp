/*
Word Search

Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
*/
//Solution : time : O (4^n)
class Solution {
    int movex[4] = {0,0,1,-1};
    int movey[4] = {1,-1,0,0};
    bool helper(string word, int cur, int cur_i, int cur_j, vector<vector<char>> & board){
        int n = board.size();
        int m = board[0].size();
        if(cur >= word.size()) return true;
        if(cur_i<0 || cur_j<0 || cur_i>=n || cur_j >= m || board[cur_i][cur_j]!=word[cur]) return false;
        char t = board[cur_i][cur_j];
        board[cur_i][cur_j] = '#';
        for(int i=0;i<4;i++){
            if(helper(word,cur+1,cur_i + movex[i], cur_j + movey[i], board)) return true;
        }
        board[cur_i][cur_j] = t;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n==0) return false;
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && helper(word,0,i,j,board)){
                    return true;
                }
            }
        }
        return false;
    }
};
