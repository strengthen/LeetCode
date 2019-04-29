__________________________________________________________________________________________________
sample 4 ms submission
/* 我们排序每一个面试者到A地和到B地cost之差，前N个（到A地cost较小的N个）取到A地cost，后N个取到B地cost，这样平均情况是NlogN
   考虑到我们只需要到A地较小的元素在前半部分（较小元素之间的排序无关紧要），而到B地cost较小的元素在后半部分
   所以可以考虑使用快速选择算法替代快速排序，将平均复杂度从 NlogN 减小到 N
 */
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort(costs.begin(), costs.end(), [](const vector<int>& c1, const vector<int>& c2) {
        //     return (c1[0] - c1[1]) < (c2[0] - c2[1]);
        //  });
        nth_element(costs.begin(), costs.begin() + costs.size() / 2 - 1, costs.end(), [](const vector<int>& c1, const vector<int>& c2) {
            return (c1[0] - c1[1]) < (c2[0] - c2[1]);
        });
        int res_cost = 0;
        for (int i = 0, j = costs.size() - 1; i < j; ++i, --j) {
            res_cost += costs[i][0] + costs[j][1];
        }
        return res_cost;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort by saving
        std::sort(costs.begin(), costs.end(), comp);
        int n = costs.size();
        int half = n / 2;
        int total = 0;
        for(int i = 0; i < half; ++i) {
            total += costs[i][0] + costs[n - i - 1][1];
        }
        return total;
    }
    
   static bool comp(vector<int>& cost1, vector<int>& cost2) {
        return cost1[0] - cost1[1] < cost2[0] - cost2[1];
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){return a[0]-a[1] < b[0]-b[1];});
        int n = costs.size() / 2;
        int res = 0;
        for(int i = 0; i < costs.size(); i++){
            if(i >= n) res += costs[i][1];
            else res += costs[i][0];
        }
        return res;
    }
};