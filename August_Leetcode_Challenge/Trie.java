/*
Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
*/
// Solution :
class Node{
    Node[] children;
    boolean isWord;
    Node(){
        children = new Node[26];
        isWord = false;
    }
}

class WordDictionary {
	Node root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        Node p = root;
        for(char c:word.toCharArray()){
        	if(p.children[c-'a']!=null){
        		p = p.children[c-'a'];
        	}
        	else{
        		p = p.children[c-'a'] = new Node();
        	}
        }
        p.isWord = true;
    }

    private boolean dfs(int cur, String word, Node p){
    	for(int i=cur+1;i<word.length();i++){
        	char c = word.charAt(i);
        	if(c == '.'){
        		for(int x=0;x<26;x++){
        			Node q = p.children[x];
        			if(q!=null){
        				if(dfs(i,word,q)) return true;
        			}
        		}
        		return false;
        	}
        	else if(p.children[c-'a']!=null){
        		p = p.children[c-'a'];
        	}
        	else{
        		return false;
        	}
        }
        if(p.isWord) return true;
        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return dfs(-1,word,root);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
