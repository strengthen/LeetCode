__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k == 0) return {};
        int m = nums1.size(), n = nums2.size();
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b) { return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second]; };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for (int i = 0; i < m; i++) {
            pq.push({i,0});
        }
        vector<pair<int,int>> res;
        while (k-- && pq.size()) {
            auto top = pq.top(); pq.pop();
            res.push_back({nums1[top.first], nums2[top.second]});
            if (top.second + 1 < n) {
                pq.push({top.first, top.second+1});
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8980 kb submission
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); 
            min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
    
};
__________________________________________________________________________________________________
