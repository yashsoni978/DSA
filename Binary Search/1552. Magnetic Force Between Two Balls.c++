class Solution {
private:
    bool canPlace(vector<int>& pos, int m, int dist){
        int n = pos.size();
        int lastPos = pos[0], cnt = 1;
        for(int i=1; i<pos.size(); i++){
            if(pos[i] - lastPos >= dist){
                cnt++;
                lastPos = pos[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int minDist = 1, maxDist = position[n-1] - position[0];
        int minForce = 0;
        for(int d=minDist; d<=maxDist; d++){
            if(canPlace(position, m, d)) minForce = d;
            else break;
        }
        return minForce;
    }
};

class Solution {
private:
    bool canPlace(vector<int>& pos, int m, int dist){
        int n = pos.size();
        int lastPos = pos[0], cnt = 1;
        for(int i=1; i<pos.size(); i++){
            if(pos[i] - lastPos >= dist){
                cnt++;
                lastPos = pos[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int minDist = 1, maxDist = position[n-1] - position[0];
        int minForce = 0;
        int l = 1, r = position[n-1] - position[0];
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canPlace(position, m, mid)){
                minForce = mid;
                l = mid + 1;
            }
            else r = mid-1;
        }
        return minForce;
    }
};