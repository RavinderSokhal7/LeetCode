/*
 Iterator for Combination
Design an Iterator class, which has:
    A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
    A function next() that returns the next combination of length combinationLength in lexicographical order.
    A function hasNext() that returns True if and only if there exists a next combination.
Example:
CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
Constraints:

    1 <= combinationLength <= characters.length <= 15
    There will be at most 10^4 function calls per test.
    It's guaranteed that all calls of the function next are valid.
*/
class CombinationIterator {
    vector<string> com;
    int it;
    void dfs(vector<string> &com, int cur, string t, string chars, int clen){
        int n = chars.size();
        if(cur>=n && t.size()!=clen) return;
        if(t.size() == clen){
            com.push_back(t);
            return;
        }
        for(int i=cur;i<n-clen+t.size()+1;i++){
            t+=chars[i];
            dfs(com, i+1, t, chars, clen);
            t.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        dfs(com, 0, "", characters, combinationLength);
        it = 0;
    }
    
    string next() {
        if(it<com.size())
        return com[it++];
        return "";
    }
    
    bool hasNext() {
        return it!=com.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
