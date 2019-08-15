__________________________________________________________________________________________________
sample 88 ms submission
class Twitter:
    MAX_NUM = 10
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.n = 0
        self.followees = {}
        self.tweets = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        if userId in self.tweets:
            q = self.tweets[userId]
        else:
            q = collections.deque()
            self.tweets[userId] = q
        if len(q) == self.MAX_NUM:
            q.popleft()
        self.n += 1
        q.append((tweetId, self.n))
        

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        items = []
        if userId in self.tweets:
            items.extend(self.tweets[userId])
        if userId in self.followees:
            for user in self.followees[userId]:
                if user in self.tweets:
                    items.extend(self.tweets[user])
        items = sorted(items, key=lambda x: x[1], reverse=True)
        return [e[0] for e in items[:self.MAX_NUM]]
        
    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId == followeeId:
            return
        
        if followerId in self.followees:
            items = self.followees[followerId]
        else:
            items = set()
            self.followees[followerId] = items
        items.add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId in self.followees:
            items = self.followees[followerId]
            if followeeId in items:
                items.remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
__________________________________________________________________________________________________
sample 17672 kb submission
from collections import defaultdict

class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tweets    = []
        self.followers = defaultdict(set)
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.tweets.append((userId, tweetId))
        

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item
        in the news feed must be posted by users who the user followed or by the
        user herself. Tweets must be ordered from most recent to least recent.
        """
        LIMIT = 10
        count = 0
        news_feed = []
        for i in range(len(self.tweets)-1, -1, -1):
            _userId, _tweetId = self.tweets[i]
            if userId == _userId or userId in self.followers[_userId]:
                news_feed.append(_tweetId)
                count += 1
                #if len(news_feed) == LIMIT:
                if count == LIMIT:
                    return news_feed
        return news_feed             
                        
        
    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.followers[followeeId].add(followerId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        try:
            self.followers[followeeId].remove(followerId)
        except KeyError:
            pass
__________________________________________________________________________________________________
