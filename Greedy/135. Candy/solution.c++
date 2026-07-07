class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += max(left[i], right[i]);
        }

        return ans;
    }
};

//2n space

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n,1);
        left[0] = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }
        int cur = 1, right = 1, sum = max(1, left[n-1]);
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                right += 1;
            }
            else right = 1;
            cur = right;
            sum = sum + max(left[i], cur);
        }
        return sum;
    }
};

//n space

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down++;
            }
            if(down > peak) sum += (down - peak);
        }
        return sum;
    }
};