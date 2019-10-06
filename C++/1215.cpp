__________________________________________________________________________________________________
sample 68 ms submission
class Solution {
public:
  vector<int> countSteppingNumbers(int low, int high) {
    S.clear();
    this->L = high;

    for (int i = 1; i <= 9; ++ i) search(i);

    vector<int> ans;
    if (0 >= low && 0 <= high) {
      ans.push_back(0);
    }
    for (int x : S) {
      if (x >= low && x <= high) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
private:
  int L;
  vector<int> S;
  void search(long long x) {
    if (x > L) return;
    S.push_back(x);
    int last = x % 10;
    if (last != 0) search(x * 10 + last - 1);
    if (last != 9) search(x * 10 + last + 1);
  }
};
__________________________________________________________________________________________________
sample 76 ms submission
class Solution {
    typedef long long ll;
    vector<ll> s[11];
    void init(int n) {
        if (n == 1)
            for (ll i=0; i<10; i++) s[n].push_back(i);
        else {
            init(n-1);
            for (ll a : s[n-1]) 
                for (ll k : {a%10-1, a%10+1})
                    if (a >= pow(10, n-2) && k>=0 && k<=9) s[n].push_back(a*10+k);
        }
    }
public:
    vector<int> countSteppingNumbers(int low, int high) {
        init(10);
        vector<int> res;
        for (auto& ss : s) 
            for (auto& i : ss)
                if (i>=low && i<=high) res.push_back(i);
        return res;
    }
};
__________________________________________________________________________________________________
sample 140 ms submission
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<vector<string>> v(10);
        v[0]=vector<string>({"0","1","2","3","4","5","6","7","8","9"});
        int i, j;
        for(i=1;i<10;i++)
        {
            for(j=0;j<(int)v[i-1].size();j++)
            {
                string s="a"+v[i-1][j];
                if(v[i-1][j][0]!='0')
                {
                    s[0]=v[i-1][j][0]-1;
                    if(i<9||s[0]<'2')
                        v[i].push_back(s);
                }
                if(v[i-1][j][0]!='9')
                {
                    s[0]=v[i-1][j][0]+1;
                    if(i<9||s[0]<'2')
                        v[i].push_back(s);
                }
            }       
        }
        vector<int> r;
        vector<int> result;
        for(i=0;i<10;i++)
            for(j=0;j<(int)v[i].size();j++)
                r.push_back(stoi(v[i][j]));
        sort(r.begin(), r.end());
        for(i=0;i<(int)r.size();i++)
        {
            if(r[i]>=low&&r[i]<=high)
            {
                int x=result.size();
                if(x==0||result[x-1]!=r[i])
                    result.push_back(r[i]);
            }
        }
        return result;
    }
};