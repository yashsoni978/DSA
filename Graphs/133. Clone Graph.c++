/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, Node* cloneNode, unordered_map<Node*, Node*>& mp){
        for(Node* n : node -> neighbors){
            //no clone made of this
            if(mp.find(n) == mp.end()){
                //make clone
                Node* clone = new Node(n->val);
                mp[n] = clone; //store in map
                cloneNode -> neighbors.push_back(clone);
                dfs(n, clone, mp);
            }
            else cloneNode->neighbors.push_back(mp[n]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* cloneNode = new Node(node->val);
        //clone its nei and do DFS but if a node reappears, we need to access that cloned node , so store them in map
        unordered_map<Node*,Node*>mp;
        mp[node] = cloneNode;
        dfs(node, cloneNode, mp);
        return cloneNode;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void bfs(queue<Node*>q, unordered_map<Node*,Node*>& mp){
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            Node* cloneNode = mp[node];
            for(Node* n : node -> neighbors){
                if(mp.find(n) == mp.end()){
                    Node* clone = new Node(n -> val);
                    mp[n] = clone;
                    cloneNode->neighbors.push_back(clone);
                    q.push(n);
                }
                else cloneNode->neighbors.push_back(mp[n]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* cloneNode = new Node(node -> val);
        unordered_map<Node*,Node*>mp;
        mp.clear();
        mp[node] = cloneNode;
        queue<Node*>q;
        q.push(node);
        bfs(q, mp);
        return cloneNode;
    }
};

