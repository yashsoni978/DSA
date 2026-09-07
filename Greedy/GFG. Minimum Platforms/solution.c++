class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            // Consider arr[i] as the current time
            for (int j = 0; j < n; j++) {
                if (arr[j] <= arr[i] && arr[i] <= dep[j]) {
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

//n^2 and 1

/*Sort arrivals
Sort departures

If arrival <= departure:
    need another platform
    i++

Else:
    platform becomes free
    j++*/


