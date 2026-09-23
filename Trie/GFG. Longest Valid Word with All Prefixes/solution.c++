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

class Solution {
private:
    Node* root;

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool checkAllPrefixes(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }

            node = node->get(ch);

            if (!node->isEnd()) {
                return false;
            }
        }

        return true;
    }

public:
    string longestValidWord(vector<string>& words) {
        root = new Node();

        // Insert all words into Trie
        for (string word : words) {
            insert(word);
        }

        string ans = "";

        // Check every word
        for (string word : words) {
            if (checkAllPrefixes(word)) {

                if (word.length() > ans.length()) {
                    ans = word;
                }
                else if (word.length() == ans.length() && word < ans) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};

// TC: O(N * L)
// SC: O(N * L)
// N = number of words
// L = maximum length of a word