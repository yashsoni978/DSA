class Node {
private:
    Node* links[26];
    bool flag;

public:
    Node() {
        flag = false;

        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

// TC: O(L) for insert, search, and startsWith
// SC: O(N * L) in worst case
// L = length of word/prefix, N = number of words