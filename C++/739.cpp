__________________________________________________________________________________________________
sample 164 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {   
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        vector<int> out(T.size());
        for (int i = T.size() - 1; i >= 0; --i) {
            int j = i+1;
            while (j < T.size() && T[j] <= T[i])
                j = (out[j] > 0) ? (j + out[j]) : T.size();                
            out[i] = (j < T.size()) ? (j-i) : 0;
        }        
        return out;
    }
};
__________________________________________________________________________________________________
sample 14788 kb submission
class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0) j = res[j] + j;
            else j = temperatures.size();
        }
        // either j == size || temperatures[j] > temperatures[i]
        if (j < temperatures.size()) res[i] = j - i;
    }
    return res;
}
};
__________________________________________________________________________________________________
