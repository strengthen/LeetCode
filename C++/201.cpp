__________________________________________________________________________________________________
sample 16 ms submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
int rangeBitwiseAnd(int m, int n)
{
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		if ((m & (1 << i)) == (n & (1 << i)))
			res |= (m & (1 << i));
		else
			break;
	}
	return res;
}
};
__________________________________________________________________________________________________
sample 7940 kb submission
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};
__________________________________________________________________________________________________
