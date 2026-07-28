/* Brute
Idea:
- Store all tweets globally as {time, userId, tweetId}.
- Store follow relationships using a hash map.
- For getNewsFeed(), traverse tweets from latest to oldest.
- Pick tweets posted by the user or users they follow.
- Stop after collecting 10 tweets.

TC:
postTweet()  : O(1)
getNewsFeed(): O(T)
follow()     : O(1)
unfollow()   : O(1)

SC: O(T + F)
(T = total tweets, F = total follow relations)
*/

class Twitter {
public:
    int timer;
    vector<vector<int>>tweets;
    unordered_map<int, unordered_set<int>>followMap;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({timer++, userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        for(int i=tweets.size()-1; i>=0 && ans.size() < 10; i--){
            int uid = tweets[i][1];
            if(uid == userId || followMap[userId].count(uid)) ans.push_back(tweets[i][2]);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

/*/* Optimal (Heap + K-way Merge)
Idea:
- Store tweets separately for each user as {time, tweetId}.
- Keep follow relationships in a hash map.
- Push the latest tweet of the user and every followee into a max heap.
- Pop the most recent tweet.
- Push the previous tweet of the same user.
- Repeat until 10 tweets are collected.

Why Heap?
- Each user's tweets are already sorted by time.
- Similar to Merge K Sorted Lists.
- Heap always gives the most recent tweet among all users.

TC:
postTweet()  : O(1)
getNewsFeed(): O((F+1) log(F+1))
follow()     : O(1)
unfollow()   : O(1)

SC:
Tweets : O(T)
Heap   : O(F)

(F = number of followees)
*/

class Twitter {
public:
    int timer;
    unordered_map<int, unordered_set<int>>follows;
    unordered_map<int, vector<pair<int,int>>>tweets;   
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq;
        if(!tweets[userId].empty()){
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
        }
        for(int followee : follows[userId]){
            if(!tweets[followee].empty()){
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].first, tweets[followee][idx].second, followee, idx});
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size() < 10){
            auto curr = pq.top();
            pq.pop();
            int tweetId = curr[1], user = curr[2], idx = curr[3];
            ans.push_back(tweetId);
            if(idx > 0) pq.push({tweets[user][idx-1].first, tweets[user][idx-1].second, user, idx-1});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */