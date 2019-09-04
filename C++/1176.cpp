__________________________________________________________________________________________________
sample 8 ms submission
static const auto s = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int T = 0;
        int points = 0;
        for(int i = 0; i < k && i < calories.size(); ++i) {
            T += calories[i]; 
        }
        if(T > upper) ++points;
        if(T < lower) --points;
        
        for(int i = k; i < calories.size(); ++i) {
            T += calories[i];
            T -= calories[i-k]; 
            
            if(T > upper) ++points;
            if(T < lower) --points;
        }
        return points;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int result = 0, base = 0;
        for (int i = 0; i < k; ++i)
            base += calories[i];
        for (int i = 0; i < calories.size() - k; ++i) {
            if (base < lower)
                --result;
            if (base > upper)
                ++result;
            base -= calories[i];
            base += calories[i + k];
        }
        if (base < lower)
            --result;
        if (base > upper)
            ++result;
        return result;
    }
};
__________________________________________________________________________________________________
