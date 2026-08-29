/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int, map<int,multiset<int>>>nodes;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node -> val);
            if(node -> left) q.push({node -> left, {x-1, y+1}});
            if(node -> right) q.push({node -> right, {x+1, y+1}});
        }
        vector<vector<int>>ans;
        for(auto p : nodes){
            vector<int>col;
            for(auto q : p.second) col.insert(col.end(), q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};

/*TC: O(n log n)

Each node is inserted into a map/multiset, which takes O(log n) in the worst case.

SC: O(n)

The queue, map, multisets, and answer together can store O(n) elements.*/