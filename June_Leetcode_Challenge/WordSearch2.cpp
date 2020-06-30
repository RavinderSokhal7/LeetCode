/*

*/
//Solution 1: using trie, time : O( max(#words*maxWordSize, boardWidth*boardLength*maxWordSize) ), space : similar to time

class trieNode{
	
public:
	map<char,trieNode*> children;
	bool isWord;
	trieNode(){
		this->isWord = false;
	}
	bool insertWord(string s){
		if(s.size()==0) return false;
		int i = 0;
		char ch=s[i];
        trieNode* p = this;
		while(i<s.size() && p->children.find(ch)!=p->children.end()){
			p = p->children[ch];
			i++;
			if(i>=s.size()) break;
			ch = s[i];
		}
		if(i==s.size()){
			if(p->isWord==true) return false;
			p->isWord = true;
			return true;
		}
		ch = s[i];
		while(i<s.size()){
			p->children[ch] = new trieNode();
			p = p->children[ch];
			i++;
			if(i>=s.size()) break;
			ch = s[i];
		}
		p->isWord = true;
		return true;
	}
};

class Solution {
	int xi[4] = {-1,1,0,0};
	int yj[4] = {0,0,1,-1};
	void helper(trieNode* p, int i, int j, string word, vector<vector<char>>& board, unordered_set<string> &ans,vector<vector<bool>> &usedBoard){//vector<string>& ans){
		int n = board.size(), m = board[0].size();
		// if(i<0 || j<0 || i>=n || j>=m){
		// 	return;
		// }
		if(p->isWord){
			if(ans.find(word)==ans.end())
				ans.insert(word);
			// ans.push_back(word);
		}
		for(int e=0;e<4;e++){
			int x = i + xi[e], y = j+yj[e];
			if(x<0 || y<0 || x>=n || y>=m) continue;
			if(usedBoard[x][y]==false && p->children.find(board[x][y])!=p->children.end()){
                word+=board[x][y];
                usedBoard[x][y] = true;
				helper(p->children[board[x][y]], x, y, word, board, ans,usedBoard);
                word.pop_back();
                usedBoard[x][y] = false;
			}
		}
		return;
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = words.size();
        if(n==0) return words;
        vector<string> ans;
        if(board.size() == 0) return ans;
        trieNode* root = new trieNode();
        for(auto word:words){
        	root->insertWord(word);
        }
        unordered_set<string> anss;
        vector<vector<bool>> usedBoard(board.size(), vector<bool> (board[0].size(),false));
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[0].size();j++){
        		if(root->children.find(board[i][j])!=root->children.end()){
                    string x = "";
                    x+=board[i][j];
                    usedBoard[i][j] = true;
        			helper(root->children[board[i][j]],i,j,x,board,anss, usedBoard);
        			usedBoard[i][j] = false;
                }
        	}
        }
        for(auto word:anss){
        	ans.push_back(word);
        }
        return ans;
    }
};

//Solution 2: using space only for trie, and manipulating space given as input
class trieNode{
	
public:
	map<char,trieNode*> children;
	bool isWord;
	trieNode(){
		this->isWord = false;
	}
	bool insertWord(string s){
		if(s.size()==0) return false;
		int i = 0;
		char ch=s[i];
        trieNode* p = this;
		while(i<s.size() && p->children.find(ch)!=p->children.end()){
			p = p->children[ch];
			i++;
			if(i>=s.size()) break;
			ch = s[i];
		}
		if(i==s.size()){
			if(p->isWord==true) return false;
			p->isWord = true;
			return true;
		}
		ch = s[i];
		while(i<s.size()){
			p->children[ch] = new trieNode();
			p = p->children[ch];
			i++;
			if(i>=s.size()) break;
			ch = s[i];
		}
		p->isWord = true;
		return true;
	}
};

class Solution {
	int xi[4] = {-1,1,0,0};
	int yj[4] = {0,0,1,-1};
	void helper(trieNode* p, int i, int j, string word, vector<vector<char>>& board, vector<string> &ans){
		int n = board.size(), m = board[0].size();
        
		if(p->isWord){
            ans.push_back(word);
            p->isWord = false;
		}
		for(int e=0;e<4;e++){
			int x = i + xi[e], y = j+yj[e];
			if(x<0 || y<0 || x>=n || y>=m) continue;
			if(p->children.find(board[x][y])!=p->children.end()){
                word+=board[x][y];
                char ch = board[x][y];
                board[x][y] = ' ';
				helper(p->children[ch], x, y, word, board, ans);
                word.pop_back();
                board[x][y] = ch;
			}
		}
		return;
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = words.size();
        if(n==0) return words;
        vector<string> ans;
        if(board.size() == 0) return ans;
        trieNode* root = new trieNode();
        for(auto word:words){
        	root->insertWord(word);
        }
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[0].size();j++){
        		if(root->children.find(board[i][j])!=root->children.end()){
                    string x = "";
                    char ch = board[i][j];
                    x+=ch;
                    board[i][j] = ' ';
        			      helper(root->children[ch],i,j,x,board,ans);
        			      board[i][j] = ch;
                }
        	}
        }
        return ans;
    }
};
