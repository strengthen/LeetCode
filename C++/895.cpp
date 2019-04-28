__________________________________________________________________________________________________
sample 220 ms submission
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxfreq;
    FreqStack() 
    {
        freq.clear();
        m.clear();
        maxfreq=0;
    }
    
    void push(int x) 
    {
        freq[x]++;
        maxfreq=max(freq[x],maxfreq);
        m[freq[x]].push(x);
        
    }
    
    int pop() 
    {
        int ans=m[maxfreq].top();
        m[maxfreq].pop();
        freq[ans]--;
        if(m[maxfreq].size()==0)maxfreq--;
        return ans;
    }
};
__________________________________________________________________________________________________
sample 67192 kb submission
class FreqStack {
public:    
    
    int idx;
    FreqStack() {
        idx = 0;
    }
    
    void push(int x) {
        mp[x]++;
        q.push({mp[x], {idx++, x}});
    }
    
    int pop() {
        auto temp = q.top();
        q.pop();
        int val = temp.second.second;
        if(--mp[val] == 0) mp.erase(val);
        return val;
    }
private:
    priority_queue<pair<int, pair<int,int>>> q;
    unordered_map<int,int> mp;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
__________________________________________________________________________________________________
