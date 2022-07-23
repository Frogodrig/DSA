#include<iostream>
using namespace std;

class TrieNode {

    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {

    public:
        TrieNode* root;    

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            //assumption: word will be in all CAPS.
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) { //present
                child = root->children[index];

            } else { //absent
                child = new TrieNode(word[0]);
                root->children[index] = child;

            }

            //Revursive calls
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }
        
        bool searchUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) { //present
                child = root->children[index];

            } else { //absent
                return false;

            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }

        bool deleteUtil(TrieNode* root, string word) {

            int index = word[0] - 'A';

            //base case 
            if(word.length() == 0) {
                root->isTerminal = false;
                if(root->children[index]->children == NULL) {
                    return true;
                } else {
                    return false;
                }
            }

            
            TrieNode* child = root->children[index];

            if(deleteUtil(child, word.substr(1))) {
                delete root->children[index];

            }

            if(root->isTerminal || root->children[index]->children != NULL) {
                return false;

            } else {
                return true;

            }
        }

        void deleteWord(string word) {
            deleteUtil(root, word);
        }
};

int main() {
    
    Trie* T = new Trie();
    T->insertWord("ABCD");
    
    cout<<"Present or Not "<<T->searchWord("ABCD");
    
    return 0;
}
