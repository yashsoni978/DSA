class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<int> ans;

        for (auto it : mpp) {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorR = 0;

        for (int num : nums)
            xorR ^= num;

        unsigned int rightMost = (unsigned int)xorR & (-(unsigned int)xorR);

        int b1 = 0, b2 = 0;

        for (int num : nums) {
            if ((unsigned int)num & rightMost)
                b1 ^= num;
            else
                b2 ^= num;
        }

        return {b1, b2};
    }
};

//2n and 1