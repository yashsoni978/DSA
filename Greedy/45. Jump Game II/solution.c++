/*At every jump, don't decide exactly where to jump. Instead, look at all positions reachable with the current number of jumps and choose the one that gives us the farthest reach for the next jump.*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0, end = 0, jumps = 0;
        for(int i=0; i<n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == end){//we have finished exploring everything reachable using the current number of jumps so take another jump
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};