__________________________________________________________________________________________________
sample 36 ms submission
void beforeMain(void) __attribute__((constructor));

void beforeMain(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}


class Twitter {
  typedef typename std::unordered_set<int> follows_t;

  struct tweet_t {
    int ID;
    int time;
    tweet_t* next;
    tweet_t(int id = 0, int t = 0, tweet_t* next = nullptr)
        : ID(id), time(t), next(next){};
    ~tweet_t() { delete next; };
    bool operator()(const tweet_t*& t1, const tweet_t*& t2) {
      return t1->time < t2->time;
    };
  };
  struct user_t {
    tweet_t* tweets = nullptr;
    follows_t follows;
    ~user_t() { delete tweets; }
  };
  typedef typename std::unordered_map<int, user_t> users_t;
  
  users_t Users{};
  int time = 0;

 public:
  void postTweet(const int userId, const int ID) {
    ++time;
    user_t& user = Users[userId];
    user.tweets = new tweet_t(ID, time, user.tweets);
  }

  void follow(int followerId, int followeeId) {
    if (followeeId != followerId) {
      Users[followerId].follows.emplace(followeeId);
    }
  }

  void unfollow(int followerId, int followeeId) {
    if (followeeId != followerId) {
      auto fR = Users.find(followerId);
      if (fR != Users.end()) {
        fR->second.follows.erase(followeeId);
      };
    }
  }

      vector<int> getNewsFeed(const int userId) {
    const auto user = Users.find(userId);
    if (user == Users.cend()) {
      return {};
    }

    std::vector<const tweet_t*> Q;
    Q.reserve(2 + user->second.follows.size());
    if (user->second.tweets != nullptr) {
      Q.emplace_back(user->second.tweets);
      std::push_heap(Q.begin(), Q.end(), tweet_t());
    }

    for (const auto& feID : user->second.follows) {
      const auto fE = Users.find(feID);
      if (fE != Users.cend()) {
        if (fE->second.tweets != nullptr) {
          Q.emplace_back(fE->second.tweets);
          std::push_heap(Q.begin(), Q.end(), tweet_t());
        }
      }
    };

    vector<int> feed;
    feed.reserve(10);
    while (feed.size() < 10 && !Q.empty()) {
      const tweet_t* tweet = Q.front();
      feed.emplace_back(tweet->ID);

      std::pop_heap(Q.begin(), Q.end(), tweet_t());
      // Q.pop_back();

      if (tweet->next != nullptr) {
        // Q.push_back(tweet->next);
        Q.back() = tweet->next;
        std::push_heap(Q.begin(), Q.end(), tweet_t());
      } else {
        Q.pop_back();
      }
    };
    feed.shrink_to_fit();
    return feed;
  }
};
__________________________________________________________________________________________________
sample 21140 kb submission
class Twitter {
public:
    /** Initialize your data structure here. */
    int FEED = 10;
    unordered_map<int, set<int>>following;
    vector<pair<int,int>>tweets;
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        set<int>followees = following[userId];
        for(int i=tweets.size()-1;i>-1;--i){
            if(feed.size()==FEED)break;
            if(followees.count(tweets[i].first) || tweets[i].first==userId)
                feed.push_back(tweets[i].second);
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
__________________________________________________________________________________________________
