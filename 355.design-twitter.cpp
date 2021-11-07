/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mTwitters.push_back(pair(userId,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int i = 0;
        for(auto itr = mTwitters.rbegin(); itr < mTwitters.rend() && i < 10; ++itr){
            if(itr->first == userId || 
            mUserFollwees[itr->first].find(userId) != mUserFollwees[itr->first].end()){
                res.push_back(itr->second);
                ++i;
            }
        }   
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mUserFollwees[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mUserFollwees[followeeId].erase(followerId);
    }
private:
    typedef unordered_map<int,unordered_set<int>> UserFollowees;
    UserFollowees mUserFollwees;
    std::vector<pair<int,int>> mTwitters; 
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

