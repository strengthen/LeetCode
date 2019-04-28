__________________________________________________________________________________________________
sample 120 ms submission
class Solution {
public:
     int numSimilarGroups(vector<string>& A) {
      if(A.empty()) return 0;
      if(A[0].size()<20) return help2(A);
         else return help1(A);
    }
	bool check(string& str1, string& str2) {
		int len = str1.size(), cnt = 0;
		for (int i = 0; i < len; ++i) {
			if (str1[i] != str2[i]) {
				cnt++;
				if (cnt > 2)
					return false;
			}
		}
		return true;
	}
	int find(int x,vector<int>& p) {
		if (x != p[x]) p[x] = find(p[x],p);
		return p[x];
	}
    int help1(vector<string>& A) {
        int n = A.size();
        vector<int> fa(n, 0);
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(A[i],A[j])) {
					fa[find(i,fa)]=find(j,fa);
                }
            }
        }
        int ans=0;
     for(int i=0;i<fa.size();i++){
         if(fa[i]==i)
             ans++;
     }
        return ans;
    }
    int help2(vector<string>& A) {
		unordered_set<string> sA(A.begin(), A.end());
		queue<string> q;
		int n = 0;
		while (!sA.empty()) {
			q.push(*(sA.begin()));
			sA.erase(sA.begin());
			n++;
			while (!q.empty()) {
				string s = q.front();
				q.pop();
				for (int i = 0; i < s.size(); i++)
					for (int j = i + 1; j < s.size(); j++) {
						if (s[i] != s[j]) {
							swap(s[i], s[j]);
							if (sA.count(s)) {
								q.push(s);
								sA.erase(s);
							}
							swap(s[i], s[j]);
							if (sA.empty()) return n;
						}
					}
			}
		}
		return n;
	}
};
__________________________________________________________________________________________________
sample 13348 kb submission
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        vector<int> roots(A.size(), 0);
        for(int i = 0; i < A.size(); ++i) {
            roots[i] = i;
        }
        function<int(int)> find_root = [&](int index) {
            if (roots[index] != index)
                roots[index] = find_root(roots[index]);
            return roots[index];
        };
        auto is_similar = [](const string& X, const string& Y) -> bool {
            if (X.size() != Y.size())
                return false;
            int diff = 0;
            for (int i = 0; i < X.size(); ++i){
                if (X[i] != Y[i]) {
                   diff++;
                }
            }
            return diff <= 2;
        };

        for (int i = 0; i < A.size(); ++i){
            int ri = find_root(i);
            for (int j = i + 1; j < A.size(); ++j) {
                if (is_similar(A[i], A[j])) {
                    int rj = find_root(j);
                    if (rj != ri){
                        roots[rj] = ri;
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            result += (roots[i] == i) ? 1 : 0;
        }
        return result;
    }
};
__________________________________________________________________________________________________
