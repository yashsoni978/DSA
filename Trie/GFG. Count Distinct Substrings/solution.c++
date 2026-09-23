class Solution {
  public:
    int countSubs(string& s) {
        // code here
        set<string>st;
        int n = s.size();
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=i; j<n; j++){
                str += s[j];
                st.insert(str);
            }
        }
        return st.size();
    }
};
//m^2*logn (where m is elements in set)

class Node {
private:
    Node* links[26];

public:
    Node() {
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
};

class Solution {
public:
    int countSubs(string s) {

        Node* root = new Node();

        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            Node* node = root;

            for (int j = i; j < n; j++) {

                if (!node->containsKey(s[j])) {
                    count++;
                    node->put(s[j], new Node());
                }

                node = node->get(s[j]);
            }
        }

        return count;
    }
};
// TC: O(N^2)
// SC: O(N^2 * 26)
// N = length of string