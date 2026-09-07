//Choose those meetings which are ending faster so we can get maximum meetings

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n = s.size();
        vector<pair<pair<int,int>, int>> meetings;
        for(int i=0; i<n; i++) meetings.push_back({{f[i],i+1}, s[i]});//because If two meetings have the same finish time, prefer the meeting with the smaller index
        sort(meetings.begin(), meetings.end());
        vector<int>ans;
        int lastFinish = -1;
        for(auto &meeting : meetings){
            int finish = meeting.first.first;
            int index = meeting.first.second;
            int start = meeting.second;
            if(start > lastFinish){
                ans.push_back(index);
                lastFinish = finish;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*Time Complexity
Creating meetings: O(n)
Sorting meetings: O(n log n)
Selecting meetings: O(n)
Sorting ans: O(n log n)

Therefore:

TC = O(n log n)
Space Complexity
meetings: O(n)
ans: O(n)

Therefore:

SC = O(n)*/