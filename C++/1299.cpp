__________________________________________________________________________________________________
sample 32 ms submission
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int max_right = -1;
        vector<int> res = arr;
        for ( int i = size - 1; i >= 0; i-- ) {
            res[i] = max_right;
            max_right = max(max_right, arr[i]);
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 40 ms submission
static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cerr.tie(nullptr);
    std::cout.tie(nullptr);
	return 0;
}();
class Solution
{
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            if (arr[i] > max) max ^= arr[i] ^= max ^= arr[i];
            else arr[i] = max;
        }
        return arr;
    }
};
__________________________________________________________________________________________________
