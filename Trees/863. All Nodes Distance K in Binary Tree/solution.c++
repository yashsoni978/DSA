/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parentTrack, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left){
                parentTrack[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                parentTrack[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        markParents(root, parentTrack, target);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !vis[curr -> left]){
                    q.push(curr -> left);
                    vis[curr -> left] = true;
                }
                if(curr -> right && !vis[curr -> right]){
                    q.push(curr -> right);
                    vis[curr -> right] = true;
                }
                if(parentTrack[curr] && !vis[parentTrack[curr]]){
                    q.push(parentTrack[curr]);
                    vis[parentTrack[curr]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node -> val);
        }
        return ans;
    }
};

/*TC: O(n)

markParents() visits every node once, and the BFS from target also visits
each node at most once.

SC: O(n)

Parent map + visited map + queue can store up to O(n) nodes.*/