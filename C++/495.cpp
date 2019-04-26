__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        int total = duration;
        for (int i = 1; i < timeSeries.size(); ++i)
            total += duration - std::max(0, timeSeries[i - 1] + duration - timeSeries[i]);
        return total;
    }
};

static int ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 10860 kb submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
        int findPoisonedDuration(vector<int>& timeSeries, int duration){
                if(!timeSeries.size()) return 0;
                
                int ans=duration;
                
                for(int i=1;i<timeSeries.size();i++){
                        int gap=timeSeries[i]-timeSeries[i-1];
                        ans+= gap>=duration ? duration : gap;
                }
                
                return ans; 
        }
};
__________________________________________________________________________________________________
