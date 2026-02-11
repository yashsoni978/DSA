class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int ans = 0;
        for(int x=1; x<=maxSum; x++){
            long sum = x;
            
            //fill left 
            int val = x;
            for(int i=index-1; i>=0; i--){
                val = max(1, val-1);
                sum += val;
            }
            //fill right 
            val = x;
            for(int i=index+1; i<n; i++){
                val = max(1, val-1);
                sum += val;
            }
            if(sum <= maxSum) ans = x;
            else break;
        }
        return ans;
    }
};

class Solution {
private:
    long long getElements(long long cnt, long long val){
        return val*cnt - (cnt*(cnt+1))/2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        int res = 0;
        while(l <= r){
            long long mid = l + (r-l) / 2;
            long long leftCnt = min((long long)index, mid - 1);
            long long leftSum = getElements(leftCnt, mid);
            leftSum += max((long long)0, index - mid + 1);

            long long rightCnt = min((long long)n-index-1, mid - 1);
            long long rightSum = getElements(rightCnt, mid);
            rightSum += max((long long)0, n-index-1 - mid + 1);

            if(leftSum + rightSum + mid <= maxSum){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};