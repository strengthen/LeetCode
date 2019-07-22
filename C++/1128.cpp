__________________________________________________________________________________________________
sample 40 ms submission
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> C;
    for (const auto& d : dominoes) {
      ++ C[min(d[0], d[1]) * 10 + max(d[0], d[1])];
    }
    int ret = 0;
    for (const auto& p : C) {
      ret += p.second * (p.second - 1) / 2;
    }
    return ret;
  }
};
__________________________________________________________________________________________________
class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& v) 
    {
        map<pair<int,int>, int> mp;
        for(int i=0;i<v.size();i++)
        {
            if(v[i][1]<v[i][0])
                swap(v[i][0],v[i][1]);
            mp[make_pair(v[i][0],v[i][1])]++;
        }
        int ans=0;
        for(map<pair<int,int>, int>::iterator it=mp.begin();it!=mp.end();it++)
            ans+=(it->second*(it->second-1)/2);
        return ans;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> freq;
        long long total = 0;

        for (vector<int> domino : dominoes) {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);

            total += freq[make_pair(domino[0], domino[1])]++;
        }

        return total;
    }
};