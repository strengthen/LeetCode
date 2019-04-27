__________________________________________________________________________________________________
sample 40 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int findLongestChain(vector<vector<int>> &pairs) {
		sort(pairs.begin(), pairs.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
			return lhs[1] < rhs[1];
		});
		int value = INT_MIN, length = 0;
		for (vector<int> &pair : pairs)
			if (value < pair[0]) {
				value = pair[1];
				++length;
			}
		return length;
	}
};
__________________________________________________________________________________________________
sample 17164 kb submission
auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
bool cmp(vector<int> &a,vector<int> & b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //this part also using the greedy algorithm 
        sort(pairs.begin(),pairs.end(),cmp);
        int retv=1;
        int cur=pairs[0][1];
        
        for(int i = 1;i<pairs.size();i++)
        {
            if(cur<pairs[i][0])
            {
                retv++;
                cur = pairs[i][1];
            }
        }
        return retv;
    }
};
__________________________________________________________________________________________________
