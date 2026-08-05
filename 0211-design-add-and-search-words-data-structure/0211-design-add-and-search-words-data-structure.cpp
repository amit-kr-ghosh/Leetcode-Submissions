class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string &word, int idx, TrieNode* node) {
        if (idx == word.size())
            return node->isEnd;

        char c = word[idx];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(word, idx + 1, node->child[i]))
                    return true;
            }
            return false;
        }

        int pos = c - 'a';

        if (node->child[pos] == NULL)
            return false;

        return dfs(word, idx + 1, node->child[pos]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};