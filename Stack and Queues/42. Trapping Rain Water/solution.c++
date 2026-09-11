class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMax(n);
        prefixMax[0] = height[0];
        for(int i=1; i<n; i++) prefixMax[i] = max(prefixMax[i-1], height[i]);
        vector<int>suffixMax(n);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) suffixMax[i] = max(suffixMax[i+1], height[i]);
        int water = 0;
        for(int i=0; i<n; i++) water += min(prefixMax[i], suffixMax[i]) - height[i];
        return water; 
    }
};  
//3n and 2n

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, total = 0, lMax = 0, rMax = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] <= height[r]){
                    if(height[l] >= lMax) lMax = height[l];
                    else total += lMax - height[l];
                    l++;
                }
            }
            else{
                if(height[r] >= rMax) rMax = height[r];
                else total += rMax - height[r];
                r--;
            }
        }
        return total;
    }
};

//n and 1