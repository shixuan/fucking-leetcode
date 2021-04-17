class Trie {
private:
    bool end;
    Trie *children[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        end = false;
        memset(children, 0, sizeof(children));
    }

    ~Trie() {
        for(auto child : children) {
            if(child != nullptr)    
                delete child;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = this;
        for(char ch : word) {
            int idx = ch - 'a';
            if(cur->children[idx] == nullptr) 
                cur->children[idx] = new Trie();
            cur = cur->children[idx];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = this;
        for(char ch : word) {
            int idx = ch - 'a';
            if(cur->children[idx] == nullptr) 
                return false;
            cur = cur->children[idx];
        }

        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = this;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(cur->children[idx] == nullptr) 
                return false;
            cur = cur->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */v