class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int followee: follows[userId]) {
            int i = 10;
            int index = tweets[followee].size() - 1;
            while (i > 0 && index >= 0) {
                --i;
                pq.push(tweets[followee][index]);
                --index;
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }
        {
            int i = 10;
            int index = tweets[userId].size() - 1;
            while (i > 0 && index >= 0) {
                --i;
                pq.push(tweets[userId][index]);
                --index;
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }
        
        int size = pq.size();
        vector<int> ans(size);
        for (int i = size - 1; i >= 0; --i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
