class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        if(n <= 1) return 0.0;
        vector<int>howMany(n-1,0);
        for(int gasStations=1; gasStations <= k; gasStations++){
            long double maxSection = -1;
            int maxInd = -1;
            for(int i=0; i<n-1; i++){
                long double diff = stations[i+1] - stations[i];
                long double sectionLength = diff / (long double)(howMany[i]+1);
                if(sectionLength > maxSection){
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        long double maxAns = -1;
        for(int i=0; i<n-1; i++){
            long double diff = stations[i+1] - stations[i];
            long double sectionLength = diff / (long double)(howMany[i]+1);
            maxAns = max(maxAns, sectionLength);
        }
        return maxAns;
    }
};

//TC :- k*n + n
//SC :- n-1

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        if(n <= 1) return 0.0;
        vector<int>howMany(n-1,0);
        priority_queue<pair<long double,int>>pq;
        for(int i=0; i<n-1; i++) pq.push({stations[i+1] - stations[i], i});
        for(int gasStations=1; gasStations<=k; gasStations++){
            auto it = pq.top();
            pq.pop();
            int secInd = it.second;
            howMany[secInd]++;
            long double diff = stations[secInd + 1] - stations[secInd];
            long double newSecLen = diff / (long double)(howMany[secInd] + 1);
            pq.push({newSecLen, secInd});
        }
        return pq.top().first;
    }
};

//n log n + k log n
//n-1 + n-1

/*### Helper Function Note — Minimize Max Distance of Gas Stations

Goal of helper(dist):

"Given a maximum allowed distance `dist`, how many new gas
stations are required to make every adjacent gap <= dist?"

For every adjacent gap:

    gap = arr[i] - arr[i-1]

Number of new stations needed:

    ceil(gap / dist) - 1

Example 1:
    gap = 10, dist = 3

    ceil(10 / 3) - 1
    = 4 - 1
    = 3 stations

    0 ---- 3 ---- 6 ---- 9 ---- 10

Example 2:
    gap = 9, dist = 3

    ceil(9 / 3) - 1
    = 3 - 1
    = 2 stations

    0 ---- 3 ---- 6 ---- 9

Why subtract 1?
    gap / dist tells us approximately how many sections
    the gap needs to be divided into.

    Number of new stations = number of sections - 1

For all gaps, add the required stations:

    cnt += numberInBetween

Then:

    if cnt > K:
        We need too many stations.
        `dist` is too small → increase dist.

    else:
        We can achieve this distance with K stations.
        Try a smaller dist.

So helper(dist) answers:

    "How many gas stations are required if the
     maximum allowed gap is `dist`?"

This gives the monotonic property needed for
Binary Search on Answer.*/

class Solution {
  private:
    int noOfStations(long double dist, vector<int>& stations){
        int n = stations.size();
        int cnt = 0;
        for(int i=1; i<n; i++){
            int numberInBetween = (stations[i] - stations[i-1]) / dist;
            if((stations[i] - stations[i-1]) / dist == (dist * numberInBetween)) numberInBetween--;
            cnt += numberInBetween;
        }
        return cnt;
    }
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        long double low = 0, high = 0;
        for(int i=0; i<n-1; i++) high = max(high, (long double)stations[i+1] - stations[i]);
        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (low + high)/2.0;
            int cnt = noOfStations(mid, stations);
            if(cnt > k) low = mid;
            else high = mid;
        }
        return high;
    }
};

/*TC: O(n × log(maxGap / 10^-6))
SC: O(1)

Each binary search iteration checks all adjacent gaps → O(n).
Binary search continues until precision reaches 10^-6.*/