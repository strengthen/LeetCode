__________________________________________________________________________________________________
sample 8 ms submission
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iterator>
#include <numeric>
#include <bitset>

using namespace std;

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	vector<string> reorderLogFiles(vector<string>& logs)
	{
		vector <pair<string, string>> alpha;
		vector<string> digit;
		int i;
		for (string& s : logs)
		{
			i = s.find(' ') + 1;
			if (isalpha(s[i]))
			{
				alpha.emplace_back(s.substr(i), move(s));
			}
			else
				digit.emplace_back(move(s));
		}
		sort(alpha.begin(), alpha.end(), [](const pair<string, string> & a, const pair<string, string> & b) {
			return a.first < b.first || a.first == b.first && a.second < b.second;
			});
		vector<string> ans;
		for (auto& p : alpha)
			ans.emplace_back(p.second);
		ans.insert(ans.end(), digit.begin(), digit.end());
		return ans;
	}
};
__________________________________________________________________________________________________
sample 11948 kb submission
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),[&](const string& a, const string&  b)->bool {
        int sp1 = a.find(' ');
        int sp2 = b.find(' ');
        bool c1 = a[sp1+1]>='a' && a[sp1+1]<='z';
        bool c2 = b[sp2+1]>='a' && b[sp2+1]<='z';
        if(!c1 && !c2)return false;
        if(c1 && !c2)return true;
        if(!c1 && c2)return false;
        return strcmp(a.c_str()+sp1,b.c_str()+sp2)<0;
    });
    return logs;
    }
};
__________________________________________________________________________________________________
