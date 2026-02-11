class Solution {
private:
    int get(vector<int>& dist, int speed){
        double totalTime = 0.0;
        int n = dist.size();
        for(int i=0; i<n-1; i++) totalTime += ceil((double)dist[i]/speed);
        totalTime += (double)dist[n-1]/speed;
        return totalTime;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        for(int speed = 1; speed <= 10000000; speed++){
            double time = get(dist, speed);
            if(time <= hour) return speed;
        }
        return -1;
    }
};

class Solution {
private:
    double getTime(vector<int>& dist, int speed){
        double totalTime = 0.0;
        int n = dist.size();
        for(int i=0; i<n-1; i++) totalTime += ceil((double)dist[i]/speed);
        totalTime += ((double)dist[n-1]/speed);
        return totalTime;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 10000000;
        int res = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            double time = getTime(dist, mid); 
            if(time <= hour){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};