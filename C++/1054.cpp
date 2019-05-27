__________________________________________________________________________________________________
sample 180 ms submission
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        for (int i = 0; i < barcodes.size() - 1; ++i) {
            if (barcodes[i] == barcodes[i + 1]) {
                int diff = i + 2;
                while (diff < barcodes.size() && barcodes[i] == barcodes[diff]) {
                    ++diff;
                }
                if (diff >= barcodes.size()) {
                    reverse(barcodes.begin(), barcodes.end());
                    return rearrangeBarcodes(barcodes);
                }
                swap(barcodes[i + 1], barcodes[diff]);
            }
        }
        return barcodes;
    }
};
__________________________________________________________________________________________________
sample 184 ms submission
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for (int t : barcodes) m[t]++;
        int pos = 0, n = barcodes.size();
        vector<pair<int, int>> s;
        for (auto it = m.begin(); it != m.end(); it++) s.push_back({it->second, it->first});
        sort(s.begin(), s.end());
        vector<int> result(n);
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            for (int i = 0; i < it->first; i++, pos += 2) {
                if (pos >= n) pos = 1;
                result[pos] = it->second;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 188 ms submission
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int nums[10000+100];
        int state = -1;
        int max_num=0;
        memset(nums,0,sizeof(nums));
        for(int i=0;i<b.size();i++){
            nums[b[i]]++;
            max_num = max(max_num, nums[b[i]]);
            if(max_num>=int(b.size()/2) && max_num == nums[b[i]]){
                state = b[i];
            }
        }
        int ou_start = 0;
        int ji_start = 1;
        vector<int> ans(b.size(), 0);
        
        if(state!=-1){
            while(nums[state]){
                ans[ou_start] = state;
                ou_start += 2;
                nums[state]--;
            }
        }
        for(int i=1;i<=10000;i++){
            if(nums[i]){
                while(nums[i]){
                    if(ou_start<b.size()){
                        ans[ou_start] = i;
                        ou_start += 2;
                    }else{
                        ans[ji_start] =i;
                        ji_start += 2;
                    }
                    nums[i]--;
                }
            }
        }        
        return ans;        
    }        
};