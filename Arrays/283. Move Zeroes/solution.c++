class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != 0) temp.push_back(nums[i]);//n
        }
        for(int i=0; i<temp.size(); i++) nums[i] = temp[i];//n-x
        int noOfnz = temp.size();
        for(int i=noOfnz; i<n; i++) nums[i] = 0;//n
    }
};

//sc :- x (worst case)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){//x
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return; //no zero found
        for(int i=j+1; i<n; i++){//n-x
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};