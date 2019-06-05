__________________________________________________________________________________________________
sample 61 ms submission
class Twitter {
    private Map<Integer, List<Tweet>> userTweetMap = new HashMap<>();
    
    private Map<Integer, List<Integer>> userFolloweeMap = new HashMap<>();
    
    private long count = 0L;
    
    class Tweet {
        int id;
        long timestamp;
        Tweet next;
        
        Tweet(int tweetId, Tweet next) {
            this.id = tweetId;
            this.timestamp = ++count;
            this.next = next;
        }
    }

    /** Initialize your data structure here. */
    public Twitter() {
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        List<Tweet> tweetList = userTweetMap.get(userId);
        
        if (tweetList == null) {
            tweetList = new ArrayList<>();
            userTweetMap.put(userId, tweetList);
        }
        
        Tweet last = null;
        if (tweetList.size() > 0) {
            last = tweetList.get(0);
        }
        
        tweetList.add(0, new Tweet(tweetId, last));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();
        
        Queue<Tweet> queue = new PriorityQueue<>((Tweet a, Tweet b) -> {
            return a.timestamp == b.timestamp ? 0 : (a.timestamp > b.timestamp ? -1 : 1);
        });
        addTweet(queue, userTweetMap.get(userId));
        
        List<Integer> followeeList = userFolloweeMap.get(userId);
        if (followeeList != null) {
            for (Integer followeeId : followeeList) {
                addTweet(queue, userTweetMap.get(followeeId));
            }
        }
        
        while (result.size() < 10 && !queue.isEmpty()) {
            Tweet t = queue.poll();
            result.add(t.id);
            
            if (t.next != null) {
                queue.offer(t.next);
            }
        }
        
        return result;
    }
    
    private void addTweet(Queue<Tweet> queue, List<Tweet> tweetList) {
        if (tweetList != null && tweetList.size() > 0) {
            queue.offer(tweetList.get(0));
        }
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        
        List<Integer> followeeList = userFolloweeMap.get(followerId);
        
        if (followeeList == null) {
            followeeList = new ArrayList<>();
            userFolloweeMap.put(followerId, followeeList);
        }
        
        if (!followeeList.contains(followeeId)) {
            followeeList.add(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        List<Integer> followeeList = userFolloweeMap.get(followerId);
        
        if (followeeList == null) {
            return;
        }
        
        followeeList.remove(Integer.valueOf(followeeId));
    }
}
__________________________________________________________________________________________________
sample 42656 kb submission
class Twitter {

    int tweetsize = 10;
	int tcounter = 0;
	
	//table to store user and subscriber
	Map<Integer, Set<Integer>> subMap;
	//map to store 10 most recent tweets
	Map<Integer, Deque<TweetEvent>> tweetMap;
	
	
    /** Initialize your data structure here. */
    public Twitter() {
    	subMap = new HashMap<>();
    	tweetMap = new HashMap<>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        Deque<TweetEvent> tweets = tweetMap.computeIfAbsent(userId, k->new LinkedList<>());
        if (tweets.size() >= tweetsize) {
        	tweets.removeLast();
        }
        tweets.addFirst(new TweetEvent(tweetId, tcounter++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        //get all subscribed and sort
    	List<TweetEvent> tweets = new ArrayList<>();
    	
    	Set<Integer> subset = subMap.computeIfAbsent(userId, k->new HashSet<>());
    	if (!subset.contains(userId)) {
    		//add self first
    		subset.add(userId);
    	}
    	
    	for (Integer sub : subset) {
    		if (tweetMap.containsKey(sub)) {
    			tweets.addAll(tweetMap.get(sub));
    		}
    	}
    	
    	Collections.sort(tweets);
    	List<Integer> output = new ArrayList<>();
    	for (int i=0; i< this.tweetsize && i<tweets.size(); i++) {
    		output.add(tweets.get(i).tweetId);
    	}
    	return output;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
    	Set<Integer> subset = subMap.computeIfAbsent(followerId, k->new HashSet<>());
        subset.add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (!subMap.containsKey(followerId)) {
        	return;
        }
        subMap.get(followerId).remove(followeeId);
    }
}

class TweetEvent implements Comparable<TweetEvent> {
	int tweetId;
	int tweetnum;
	
	TweetEvent(int tweetId, int tweetnum) {
		this.tweetId = tweetId;
		this.tweetnum = tweetnum;
	}
	
	@Override
	public int compareTo(TweetEvent other) {
		if (this.tweetnum == other.tweetnum) {
			return 0;
		}
		return (this.tweetnum > other.tweetnum) ? -1 : 1;
		
	}
}


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
__________________________________________________________________________________________________
