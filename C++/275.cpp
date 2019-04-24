__________________________________________________________________________________________________
sample 8 ms submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	int hIndex(vector<int>& citations) {
		size_t n = citations.size();
		size_t i = 0, j = n;
		for (; i < j;) {
			size_t k = (i + j) / 2;
			if (n - k <= citations[k]) { j = k; }
			else { i = k + 1; }
		}
		return n - i;
	}
};
__________________________________________________________________________________________________
sample 12688 kb submission
class Solution {
public:
    int hIndex(vector<int>& citations) {
        reverse(citations.begin(), citations.end());
    
        int index = 0;
    
        for(int i = 0; i < citations.size(); i++)
            if(citations[i] >= i + 1) 
                index = i + 1 > index ? i + 1 : index;
    
        return index;
    }
};
__________________________________________________________________________________________________
