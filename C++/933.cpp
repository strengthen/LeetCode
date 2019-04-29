__________________________________________________________________________________________________
sample 160 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
__________________________________________________________________________________________________
sample 49676 kb submission
class RecentCounter {
public:
    vector<int> memo;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        memo.push_back(t);
        while (t - memo.front() > 3000) 
            //printf("%d\n", t-memo.front());
            memo.erase(memo.begin());
        return memo.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
__________________________________________________________________________________________________
