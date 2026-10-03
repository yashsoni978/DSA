class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3(n+m);
        int left = 0, right = 0, index = 0;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]) nums3[index++] = nums1[left++];
            else nums3[index++] = nums2[right++];
        }
        while(left < m){
            nums3[index++] = nums1[left++];
        }
        while(right < n){
            nums3[index++] = nums2[right++];
        }
        for(int i=0; i<n+m; i++) nums1[i] = nums3[i];
    }
};

//n+m + n+m
//n+m

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1, right = 0;
        while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else break;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);
        for(int i=0; i<n; i++) nums1[m+i] = nums2[i];//Because the first m positions of nums1 already contain its original elements. So we start copying nums2 from index m
        /*Before:

nums1 = [1, 3, 5, 0, 0, 0]
                    ↑  ↑  ↑
                   empty space

After:

nums1 = [1, 3, 5, 2, 4, 6]*/
    }
};

//min(n,m) + nlogn + mlogm
//1

class Solution {
private:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
        if(nums1[ind1] > nums2[ind2])
            swap(nums1[ind1], nums2[ind2]);
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                if(left < m && right >= m) swapIfGreater(nums1, nums2, left, right - m);
                else if(left >= m) swapIfGreater(nums2, nums2, left - m, right - m);
                else swapIfGreater(nums1, nums1, left, right);
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for(int i=0; i<n; i++) nums1[m+i] = nums2[i];
    }
};