__________________________________________________________________________________________________
sample 8 ms submission

static int x = []() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int uniqueLetterString(string S)
    {
        vector<vector<int>> m(26, vector<int>());
        const int divisor = 1e9 + 7;
        
        int n = S.length();
        
        for (int i = 0; i < n; ++i)
            m[S[i] - 'A'].push_back(i);
        
        long counter = 0;
        
        for (auto &v : m)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                long prev = -1;
                
                if (i > 0)
                    prev = v[i - 1];
                
                long next = S.length();
                
                if (i < (v.size() - 1))
                    next = v[i + 1];
                
                counter = (counter + (v[i] - prev) * (next - v[i])) % divisor;
            }
        }
        return counter;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
 public:
  static const int kMod = 1000000000 + 7;

  int uniqueLetterString(string S) {
    int n = S.size();
    std::vector<int> prev(n), next(n);
    std::vector<int> index(26, -1);
    for (int i = 0; i < n; ++ i) {
      int token = S[i] - 'A';
      prev[i] = index[token];
      index[token] = i;
    }
    std::fill(index.begin(), index.end(), n);
    for (int i = n - 1; i >= 0; -- i) {
      int token = S[i] - 'A';
      next[i] = index[token];
      index[token] = i;
    }

    int answer = 0;
    for (int i = 0; i < n; ++ i) {
      int left = i - prev[i];
      int right = next[i] - i;
      answer = (answer + (long long)left * right) % kMod;
    }
    return answer;
  }
};
__________________________________________________________________________________________________
sample 9612 kb submission
class Solution {
    const int BASE = 1000000007;
public:
    int uniqueLetterString(string S) {
        long prevUniq = 0;
        long result = 0;
        vector<pair<int, int> > lastPos(26, make_pair(-1, -1)); // char -> last 2 and last 1 pos
        for (int i = 0; i < S.length(); ++i) {
            long curr = prevUniq;
            int idx = S[i] - 'A';
            curr += i - lastPos[idx].second;
            curr -= lastPos[idx].second - lastPos[idx].first;
            lastPos[idx].first = lastPos[idx].second;
            lastPos[idx].second = i;
            result = (result + curr) % BASE;
            //printf("i %d, curr %d, result %d\n", i, curr, result);
            prevUniq = curr;
        }
        return result;
    }
};