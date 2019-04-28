__________________________________________________________________________________________________
sample 436 ms submission
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A)
    {
        vector<int> c;
        for (auto i = 0, st = 0, en = 0; i < A.size(); ++i, st = en, en = c.size())
        {
            c.push_back(A[i]);
            for (auto j = st; j < en; ++j)
                if (c.back() != (c[j] | A[i])) c.push_back(c[j] | A[i]);
        }
        return unordered_set<int>(begin(c), end(c)).size();
    }
};
__________________________________________________________________________________________________
sample 308724 kb submission
class Solution {
public:
	int subarrayBitwiseORs(vector<int>& A) {
		set <int> results;
		set <int> temp;
		int k = 0;
		for (size_t i = 0; i < A.size(); i++) {
			set<int> temp2;
			for (auto a : temp) {
				temp2.insert(A[i] | a);
			}
			temp2.insert(A[i]);
			results.insert(temp2.begin(), temp2.end());
			temp = temp2;
		}
		return results.size();
	}
};
__________________________________________________________________________________________________
