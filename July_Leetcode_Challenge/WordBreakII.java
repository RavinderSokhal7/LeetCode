/*
 Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
*/
// Solution : time : O( 2^n ) : space O ( dictionary in TRIE ) :: Backtracking Results in TLE:
class Node{
    Node [] children;
    boolean isWord;
    Node(){
        children = new Node[26];
        isWord = false;
    }
    
}

class Solution {
    
    private Node insert(Node root, String word){
        if(root==null){
            return insert(new Node(), word);
        }
        Node p = root;
        for(char c : word.toCharArray()){
            if(p.children[c-'a']!=null){
                p = p.children[c-'a'];
            }
            else{
                p.children[c-'a'] = new Node();
                p = p.children[c-'a'];
            }
        }
        if(p!=null){
            p.isWord = true;
        }
        return root;
    }
    
    private boolean search(Node root, String word){
        if(root==null) return false;
        Node p = root;
        for(char c: word.toCharArray()){
            if(p.children[c-'a']==null) return false;
            p = p.children[c-'a'];
        }
        return p.isWord;
    }
    
    private void helper(String s, int cur, Node root, StringBuilder sb, List<String> ans){
        int n = s.length();
        if(cur>=n){
            sb.deleteCharAt(sb.length()-1);
            String tmp = sb.toString();
            ans.add(tmp);
            return ;
        }
        Node p = root;
        for(int i=cur;i<n;i++){
            char c = s.charAt(i);
            if(p.children[c-'a']==null) return;
            p = p.children[c-'a'];
            sb.append(c);
            int l = sb.length();
            if(p.isWord){
                sb.append(" ");
                helper(s, i+1, root, sb, ans);
                sb.delete(l,sb.length());
            }
        }
        return ;
    }
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> ans = new ArrayList<>();
        if(s.length()==0 || wordDict.size()==0) return ans;
        Node root = null;
        for(String word : wordDict){
            root = insert(root, word);
        }
        StringBuilder sb = new StringBuilder();
        helper(s, 0, root, sb, ans);
        return ans;
    }
}
