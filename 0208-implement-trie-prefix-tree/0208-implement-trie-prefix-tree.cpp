class Trie {
public:

    struct Node{
        bool endswith;
        Node * child[26];

        Node(){
            endswith = false;
            for(int i = 0;i<26;i++){
                child[i] = nullptr;
            }
        }
    };

    Node *root;

    Trie() {
        root = new Node();
        
    }
    
    void insert(string word) {
        Node *curr = root;
        for(char c : word){
            int i = c-'a';
            if(curr->child[i] == nullptr){
                curr->child[i] = new Node();
            }
            curr = curr->child[i];
        }
        curr->endswith = true;
    }
    
    bool search(string word) {
        Node *curr = root;

        for(char ch : word){
            int i = ch - 'a';

            if(curr->child[i]==nullptr){
                return false;
            }
            curr = curr->child[i];
        }
        return curr->endswith;
        
    }
    
    bool startsWith(string prefix) {
        Node * curr = root;

        for(char ch : prefix){
            int i = ch - 'a';

            if(curr->child[i] == nullptr){
                return false;
            }
            curr  = curr->child[i];
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
 */