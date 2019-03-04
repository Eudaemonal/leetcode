#include <iostream>
#include <string>

class TrieNode{
public:
    bool leaf;
    TrieNode* next[26];

    TrieNode() {
        leaf = false;
        std::fill_n(next, 26, nullptr);
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        root->leaf = true;
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        TrieNode* curr = root;
        int len = word.length(), i = 0;
        if(len == 0) return;
        
        while(word[i] && curr->next[word[i] - 'a']){
            curr = curr->next[word[i] - 'a'];
            i++;
        }
        if(!word[i]){
            curr->leaf = true;
        }else {
            while(word[i]){
                curr = curr->next[word[i] - 'a'] = new TrieNode();
                i++;
            }
            curr->leaf = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        TrieNode* curr = root;
        int len = word.length(), i = 0;
        if(len == 0) return false;
        while(word[i] && curr->next[word[i] - 'a']){
            curr = curr->next[word[i] - 'a'];
            i++;
        }
        if(!word[i] && curr->leaf) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;
        int len = prefix.length(), i = 0;
        if(len == 0) return true;
        while(prefix[i] && curr->next[prefix[i] - 'a']){
            curr = curr->next[prefix[i] - 'a'];
            i++;
        }
        if(prefix[i]) return false;
        return true;
    }

private:
    TrieNode* root;

};

int main(int argc, char *argv[]){
    try{
        Trie trie;

        trie.insert("apple");
        trie.search("apple");   // returns true
        trie.search("app");     // returns false
        trie.startsWith("app"); // returns true
        trie.insert("app");   
        trie.search("app");     // returns true

        return EXIT_SUCCESS;
    }catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
