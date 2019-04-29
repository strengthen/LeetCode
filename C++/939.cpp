__________________________________________________________________________________________________
sample 56 ms submission
class Solution {
public:
   
     int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> rows;
        for (auto& p : points) {
            rows[p[0]].push_back(p[1]);
        }
        
        for (auto& it : rows) {
            sort(it.second.begin(), it.second.end());
        }
        
        int ans = 160000000;
        for (auto& it1 : rows) {
            if (it1.second.size() <= 1) continue;
            for (auto& it2 : rows) {
                if (it2.first <= it1.first) continue;
                if (it2.second.size() <= 1) continue;
                
                int i = 0;
                int j = 0;
                int last = -1;
                while (i < it1.second.size() && j < it2.second.size()) {
                    if (it1.second[i] < it2.second[j]) {
                        i++;
                    }
                    else if (it1.second[i] > it2.second[j]) {
                        j++;
                    }
                    else {
                        if (last >= 0) {
                            ans = min(ans, (it2.first - it1.first) * (it1.second[i] - last));
                        }
                        last = it1.second[i];
                        i++;
                        j++;
                    }
                }
            }
        }
        if (ans == 160000000) return 0;
        return ans;   
     }   
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
