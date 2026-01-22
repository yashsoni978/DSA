class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i=0; i<k-1; i++) colors.push_back(colors[i]);
        int cnt = 0;
        for(int i=0; i<n; i++){
            bool isAlternating = true;
            for(int j=i; j<i+k-1; j++){
                if(colors[j] == colors[j+1]){
                    isAlternating = false;
                    break;
                }
            }
            if(isAlternating) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i=0; i<k-1; i++) colors.push_back(colors[i]);
        int N = n + (k-1);
        int i = 0, j = 1;
        int res = 0;
        while(j < N){
            if(colors[j] == colors[j-1]){
                i = j;
                j++;
                continue;
            }
            if(j-i+1 == k){
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;
        int len = 1, last = colors[0];
        for(int i=1; i<n; i++){
            if(colors[i] == last){
                len = 1;
                last = colors[i];
                continue;
            }
            len++;
            if(len >= k) res++;
            last = colors[i];
        }
        for(int i=0; i<k-1; i++){
            if(colors[i] == last){
                len = 1;
                last = colors[i];
                break;
            }
            len++;
            if(len >= k) res++;
            last = colors[i];
        }
        return res;
    }
};