class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int>res(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int start = flowers[j][0];
                int end = flowers[j][1];
                if(people[i] >= start && people[i] <= end) res[i]++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int>res(n), startTime(m), endTime(m);
        for(int i=0; i<m; i++){
            startTime[i] = flowers[i][0];
            endTime[i] = flowers[i][1];
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        for(int i=0; i<n; i++){
            int alreadyBloomed = upper_bound(startTime.begin(),startTime.end(),people[i]) - startTime.begin();
            int alreadyDied = lower_bound(endTime.begin(),endTime.end(),people[i]) - endTime.begin();
            res[i] = alreadyBloomed - alreadyDied;
        }
        return res;
    }
};