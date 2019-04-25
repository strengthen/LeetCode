__________________________________________________________________________________________________
sample 4 ms submission
auto gucciGang = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		size_t n = A.size();
		int s = 0; long t = 0;
		for (size_t i = -1; ++i < n;) {
			s += (long)i * A[i];
			t += A[i];
		}
		int num = s;
		for (size_t i = n; i-- > 0;) {
			num = max(num, s += t - (long)n * A[i]);
		}
		return num;
	}
};
__________________________________________________________________________________________________
sample 9428 kb submission
class Solution
{
public:
    int maxRotateFunction(vector<int>& A)
    {
        if (A.empty())
            return 0;
        
        int start_pos = 0;
        int max = INT_MIN;
        
        for (int i = 0; i < A.size(); ++i)
        {
            int current_max = 0;
            int pos = i;
            
            for (int j = 0; j < A.size(); ++j)
            {
                if (pos >= A.size())
                    pos -= A.size();
                
                current_max += j * A[pos];
                pos++;
            }
            
            if (current_max > max)
                max = current_max;
        }
        
        return max;
    }
};
__________________________________________________________________________________________________
