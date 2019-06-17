__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> H;
        for (auto p : items)
            H[p[0]].push_back(p[1]);
        vector<vector<int>> ret;
        for (auto p : H)
        {
            sort(p.second.begin(), p.second.end(), greater<int>());
            int sum = 0;
            for (int i = 0; i < 5; ++ i)
                sum += p.second[i];
            ret.push_back({p.first, sum/5});
        }
        return ret;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
