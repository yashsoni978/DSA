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

            // Prefer opposite bit
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
    vector<int> maximizeXor(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {

        sort(nums.begin(), nums.end());

        // {mi, {xi, original_index}}
        vector<pair<int, pair<int, int>>> offlineQueries;

        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({
                queries[i][1],
                {queries[i][0], i}
            });
        }

        // Sort queries by mi
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(queries.size());

        Trie trie;

        int index = 0;

        for (auto query : offlineQueries) {

            int mi = query.first;
            int xi = query.second.first;
            int queryIndex = query.second.second;

            // Insert all nums <= mi
            while (index < nums.size() &&
                   nums[index] <= mi) {

                trie.insert(nums[index]);
                index++;
            }

            // No valid number
            if (index == 0) {
                ans[queryIndex] = -1;
            }
            else {
                ans[queryIndex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};class Node {
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

            // Prefer opposite bit
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
    vector<int> maximizeXor(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {

        sort(nums.begin(), nums.end());

        // {mi, {xi, original_index}}
        vector<pair<int, pair<int, int>>> offlineQueries;

        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({
                queries[i][1],
                {queries[i][0], i}
            });
        }

        // Sort queries by mi
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(queries.size());

        Trie trie;

        int index = 0;

        for (auto query : offlineQueries) {

            int mi = query.first;
            int xi = query.second.first;
            int queryIndex = query.second.second;

            // Insert all nums <= mi
            while (index < nums.size() &&
                   nums[index] <= mi) {

                trie.insert(nums[index]);
                index++;
            }

            // No valid number
            if (index == 0) {
                ans[queryIndex] = -1;
            }
            else {
                ans[queryIndex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};
// TC: O(N log N + Q log Q + 32 * (N + Q))
// SC: O(32 * N + Q)
// N = size of nums, Q = number of queries