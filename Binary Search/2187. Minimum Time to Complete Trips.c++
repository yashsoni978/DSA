class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long t = 1;
        while(true){
            long long trips = 0;
            for(int i=0; i<time.size(); i++) trips += t / time[i];
            if(trips >= totalTrips) return t;
            t++;
        }
    }
};

class Solution {
private:
    bool possible(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTime = 0;
        for(int &t : time) actualTime += givenTime / t;
        return actualTime >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1, r = (long long)*min_element(time.begin(),time.end()) * totalTrips;
        while(l < r){
            long long mid = l + (r-l) / 2;
            if(possible(time, mid, totalTrips)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};