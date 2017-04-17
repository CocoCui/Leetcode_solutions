struct Node {
    vector<Node*> sons;
    bool word;
    Node() {
        sons = vector<Node*>(26, NULL);
        word = 0;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node root;
    Trie() {
        root = Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = &root;
        for(char c: word){
            if(cur -> sons[c - 'a'] == NULL) cur -> sons[c - 'a'] = new Node();
            cur = cur -> sons[c - 'a'];
        }
        cur -> word = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = &root;
        for(char c: word){
            if(cur -> sons[c - 'a'] == NULL) return 0;
            cur = cur -> sons[c - 'a'];
        }
        return cur -> word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = &root;
        for(char c: prefix){
            if(cur -> sons[c - 'a'] == NULL) return 0;
            cur = cur -> sons[c - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
