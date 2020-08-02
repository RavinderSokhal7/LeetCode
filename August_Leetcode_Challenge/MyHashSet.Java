/*
Design HashSet

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.


Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)


Note:

    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.
*/
// Solution : time : 0( 1 ) , O ( log n ) : space : O ( n ) : Bst
class MyHashSet {
    class Node{
        int hash;
        int key;
        // int value;
        Node left;
        Node right;
        Node(int h, int k){
            hash = h;key = k;
        }
    }

    private int initialCapacity = 1001;
    
    private int hashCode(int key){
        return key%initialCapacity;
    }
    private Node [] HashT;
    private Node insert(Node root, int key){
    	int hash = hashCode(key);
    	if(root == null) return new Node(hash, key);
    	Node p = root;
    	while(p!=null){
    		if(p.key == key) return root;
    		else if(p.key>key){
    			if(p.left==null){
    				p.left = new Node (hash, key);return root;
    			}
    			p = p.left;
    		}
    		else{
    			if(p.right==null){
    				p.right = new Node(hash, key); return root;
    			}
    			p = p.right;
    		}
    	}
    	return root;
    }
    private boolean isLeaf(Node p){
    	if(p.left == null && p.right == null) return true;
    	return false;
    }
    private boolean isSingle(Node p){
    	if((p.left!=null && p.right==null) || (p.left==null && p.right!=null)) return true;
    	return false;
    }
    private Node succesor(Node p){
    	p = p.right;
    	if(p==null) return null;
    	while(p.left!=null) p = p.left;
    	return p;
    }
    private Node delete(Node root, int key){
    	if(root==null) return null;
    	Node p = root;
    	if(p.key == key){
			if(isLeaf(p)){
				return null;
			}
			else if(isSingle(p)){
				if(p.left!=null){
					return p.left;
				}
				return p.right;
			}
			else{
				Node q = succesor(p);
				p.key = q.key;
				p.right = delete(p.right, p.key);
			}
		}
		else if(p.key<key) p.right = delete(p.right, key);
		else p.left = delete(p.left, key);
    	return root;
    }

    private boolean find(Node p, int key){
    	if(p==null) return false;
    	while(p!=null){
    		if(p.key==key) return true;
    		else if(p.key<key) p = p.right;
    		else p = p.left;
    	}
    	return false;
    }
    /** Initialize your data structure here. */
    public MyHashSet() {
        HashT = new Node[initialCapacity];
    }
    
    public void add(int key) {
        int hash = hashCode(key);
        HashT[hash] = insert(HashT[hash], key);
    }
    
    public void remove(int key) {
        int hash = hashCode(key);
        HashT[hash] = delete(HashT[hash], key);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return find(HashT[hashCode(key)],key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
