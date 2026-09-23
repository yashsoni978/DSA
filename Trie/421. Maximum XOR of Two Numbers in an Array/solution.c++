class Node {
private:
    Node* links[2];

public:
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // Prefer opposite bit to maximize XOR
            if (node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        // Insert all numbers
        for (int num : nums) {
            trie.insert(num);
        }

        int maxi = 0;

        // Find maximum XOR for each number
        for (int num : nums) {
            maxi = max(maxi, trie.getMax(num));
        }

        return maxi;
    }
};

// TC: O(32 * N) = O(N)
// SC: O(32 * N) = O(N)
// N = number of elements