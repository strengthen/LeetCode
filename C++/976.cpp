__________________________________________________________________________________________________
sample 28 ms submission
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
#include<cmath>

using namespace std;

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	int largestPerimeter(vector<int>& A)
	{
		sort(A.begin(), A.end());
		for (int i = A.size() - 1; i >= 2; --i) 
			if ((A[i - 1] + A[i - 2]) > A[i])
				return A[i - 1] + A[i - 2] + A[i];
		return 0;
	}
};
__________________________________________________________________________________________________
sample 10572 kb submission
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(A.begin() , A.end());
        for(int i=A.size()-1 ; i>=2 ; i--){
            if(A[i-1] + A[i-2] > A[i]) return A[i] + A[i-1] + A[i-2];
        }
        return 0;
    }
};
__________________________________________________________________________________________________
