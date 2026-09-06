class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i=0; i<n; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};
/*┌──────────────────────────────────────────────┐
│ 🟢 GREEDY IDEA                               │
│                                              │
│ At every index i, choose to maximize the     │
│ farthest position we can reach:              │
│                                              │
│   maxIndex = max(maxIndex, i + nums[i])      │
│                                              │
│ We don't care which exact jump we take.      │
│ We only keep the BEST (farthest) reach.      │
│                                              │
│ If i > maxIndex → this index is unreachable  │
│ → return false.                              │
└──────────────────────────────────────────────┘*/