__________________________________________________________________________________________________
sample 24 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int i:A){
            sum += i;
        }
        
        if(sum%3) return false;
        
        int index = 0;
        int sum_part = 0;
        while(index<A.size() && sum_part!=sum/3){
            sum_part += A[index]; 
            index++;
        }
        
        if(index==A.size()) return false;

        sum_part = 0;
        while(index<A.size() && sum_part!=sum/3){
            sum_part += A[index]; 
            index++;
        }
        
        if(index==A.size()) return false;
        return true;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
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
	bool canThreePartsEqualSum(vector<int>& A)
	{
		int all = accumulate(A.begin(), A.end(), 0);
		if (all % 3)
			return false;
		int sum = all / 3;
		int i = 0, j = A.size() - 1;
		int left = 0, right = 0;
		while (i < A.size() - 2 && left != sum)
			left += A[i++];
		if (left != sum)
			return false;
		while (i < j && right != sum)
			right += A[j--];
		if (right != sum)
			return false;
		return accumulate(A.begin() + i, A.begin() + j + 1, 0) == sum;
	}
};
__________________________________________________________________________________________________
