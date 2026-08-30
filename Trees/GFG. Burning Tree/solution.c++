/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  private:
    Node* markParents(Node* root, unordered_map<Node*,Node*>& parentTrack, int &target){
        queue<Node*>q;
        q.push(root);
        Node* targetNode = NULL;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr -> data == target) targetNode = curr;
            if(curr -> left){
                parentTrack[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                parentTrack[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
        return targetNode;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>parentTrack;
        Node* targetNode = markParents(root, parentTrack, target);
        unordered_map<Node*, bool>vis;
        queue<Node*>q;
        q.push(targetNode);
        vis[targetNode] = true;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            bool burned = false;
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                if(curr -> left && !vis[curr -> left]){
                    burned = true;
                    vis[curr -> left] = true;
                    q.push(curr -> left);
                }
                if(curr -> right && !vis[curr -> right]){
                    burned = true;
                    vis[curr -> right] = true;
                    q.push(curr -> right);
                }
                if(parentTrack[curr] && !vis[parentTrack[curr]]){
                    burned = true;
                    vis[parentTrack[curr]] = true;
                    q.push(parentTrack[curr]);
                }
            }
            if(burned) maxi++;
        }
        return maxi;
    }
};

/*TC: O(n)

markParents() visits every node once, and the burning BFS also visits
every node at most once.

SC: O(n)

parentTrack + vis + queue can store up to O(n) nodes.*/
