__________________________________________________________________________________________________
class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& p) {
        map<pair<int,int>, int> mp;
        mp[{0,1000000000}] = 0;
        vector<int> ans;
        int mx = 0;
        for (auto &v:p) {
            vector<vector<int>> toAdd;
            cout << endl;
            int len = v.second, a = v.first, b =v.first + v.second, h = 0;
            auto it = mp.upper_bound({a,a});
            if (it != mp.begin() && (--it)->first.second <= a) ++it;
            while (it != mp.end() && it->first.first <b) {
                if (a > it->first.first) toAdd.push_back({it->first.first,a,it->second});
                if (b < it->first.second) toAdd.push_back({b,it->first.second,it->second});
                h = max(h, it->second);
                it = mp.erase(it);
            }
            mp[{a,b}] = h + len;
            for (auto &t:toAdd) mp[{t[0],t[1]}] = t[2];
            mx = max(mx, h + len);
            ans.push_back(mx);
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        map<int,int> mp = {{0,0}, {INT_MAX,0}};
        vector<int> res;
        int cur = 0;
        for(auto &p : positions){
            int l = p.first, r = p.first + p.second, h = p.second, maxH = 0;
            auto ptri = mp.upper_bound(l), ptrj = mp.lower_bound(r);        // find range
            int tmp = ptrj->first == r? ptrj->second : (--ptrj)++->second;  // tmp will be applied by new right bound 
            for(auto i = --ptri; i != ptrj; ++i)
                maxH = max(maxH, i->second);                                // find biggest height
            mp.erase(++ptri, ptrj);                                         // erase range
            mp[l] = h+maxH;                                                 // new left bound
            mp[r] = tmp;                                                    // new right bound
            cur = max(cur, mp[l]);
            res.push_back(cur);
        }
        return res;
    }
__________________________________________________________________________________________________
