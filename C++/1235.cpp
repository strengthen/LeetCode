__________________________________________________________________________________________________
sample 72 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class my_greater{
public:
    bool operator()(const std::pair<int,int> a, const std::pair<int,int> b) const {
        return a.second>b.second;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        std::vector<std::tuple<int,int,int>> jobs(startTime.size());
        for(int i=0;i<startTime.size();i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        
        std::sort(jobs.begin(),jobs.end(),[](std::tuple<int,int,int> &a,std::tuple<int,int,int> &b){
            return std::get<0>(a)<std::get<0>(b);
        });
        
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,my_greater> profit_queue;
        int max_profit = 0;
        
        for(int i=0;i<jobs.size();i++){
            while(!profit_queue.empty() && profit_queue.top().second<=std::get<0>(jobs[i])){
                if(profit_queue.top().first>max_profit) max_profit = profit_queue.top().first;
                profit_queue.pop();
            }
            
            profit_queue.push({max_profit+std::get<2>(jobs[i]),std::get<1>(jobs[i])});
        }
        
        while(!profit_queue.empty()){
            if(profit_queue.top().first>max_profit) max_profit = profit_queue.top().first;
            profit_queue.pop();
        }        
        
        return max_profit;
    }
};
__________________________________________________________________________________________________
sample 80 ms submission
[[maybe_unused]] static const auto _ = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
private:
    struct Job {
        int left;
        int right;
        int profit;
        Job(int l, int r, int p) : left(l), right(r), profit(p) {};
    };
    
    vector<Job> jobs;
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for (int i = 0; i < startTime.size(); ++i) 
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        
        // sort jobs by their left values, from max to min
        auto f = [](const Job& lhs, const Job& rhs) { return lhs.left > rhs.left; };
        sort(jobs.begin(), jobs.end(), f);  
        
        int ret = 0;
        map<int, int> m{{INT_MAX, 0}};  // <right, profit>
        for (int i = 0; i < jobs.size(); ++i) {  // loop jobs
            int cur_profit = jobs[i].profit + m.lower_bound(jobs[i].right)->second;  // O(logn)
            auto recorded_it = m.lower_bound(jobs[i].left);  // O(logn), find recorded
            if (cur_profit > recorded_it->second)  // check if cur_profit > recorded_profit
                if (jobs[i].left == recorded_it->first) recorded_it->second = cur_profit;
                else m.emplace_hint(recorded_it, jobs[i].left, cur_profit);  // O(1) by hint-emplace
            ret = max(ret, cur_profit);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
