/*
Stream of Characters

Implement the StreamChecker class as follows:
    StreamChecker(words): Constructor, init the data structure with the given words.
    query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
Example:
StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
Note:

    1 <= words.length <= 2000
    1 <= words[i].length <= 2000
    Words will only consist of lowercase English letters.
    Queries will only consist of lowercase English letters.
    The number of queries is at most 40000
*/
// Solution 1 : using set or queue
class StreamChecker {
    
    class Node {
        boolean isValid;
        char val;
        Node[] children = new Node[26];
        Node(char c) {
            this.val = c;
            this.isValid = false;
        }
    }
    
    Node root;
    Queue<Node> q; // valid query status ending up with Node.

    public StreamChecker(String[] words) {
        root = new Node('X');
        for(String word : words) {
            Node node = root;
            for(int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                if(node.children[c - 'a'] == null) {
                    node.children[c - 'a'] = new Node(c);
                }
                node = node.children[c - 'a'];
                if(i == word.length() - 1) {
                    node.isValid = true;
                }
            }
        }
        q = new LinkedList<>();
        q.add(root);
    }
    
    public boolean query(char letter) {
        boolean res = false;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node node = q.poll();
            if(node.children[letter - 'a'] != null) {
                q.add(node.children[letter - 'a']);
                if(node.children[letter - 'a'].isValid) {
                    res = true;
                }
            }
            if(node == root) {
                q.add(root);
            }
        }
        return res;
    }
}

// Solution 2 : reverse storing words
class Node{
    public boolean isWord;
    public Node[] children;
    public Node(){
        isWord = false;
        children = new Node[27];
    }
}

class StreamChecker {
    private Node root;
    private StringBuilder sb;
    
    private boolean insert(String word){
        Node p = root;
        for(char c:word.toCharArray()){
            if(p.children[c-'a']==null){
                p.children[c-'a'] = new Node();
            }
            p = p.children[c-'a'];
        }
        p.isWord = true;
        return true;
    }
    
    public StreamChecker(String[] words) {
        root = new Node();
        for(String word:words){
            Node p = root;
            for(int i=word.length()-1;i>=0;i--){
                char c = word.charAt(i);
                if(p.children[c-'a']==null){
                    p.children[c-'a'] = new Node();
                }
                p = p.children[c-'a'];
            }
            p.isWord = true;
            // StringBuilder x = new StringBuilder(word);
            // x.reverse();
            // insert(x.toString());
        }
        sb = new StringBuilder();
        // c=0;
        // set = new HashSet<>();
    }
    
    public boolean query(char ch) {
        sb.append(ch);
        Node p = root;
        for(int i=sb.length()-1;i>=0;i--){
            char c = sb.charAt(i);
            p = p.children[c-'a'];
            if(p!=null && p.isWord){
                return true;
            }
            if(p==null) break;
        }
        return false;
    }
}
