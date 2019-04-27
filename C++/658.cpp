__________________________________________________________________________________________________
sample 72 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<int> findClosestElements(vector<int> &arr, int k, int x) {
		vector<int>::const_iterator index = lower_bound(arr.cbegin(), arr.cend(), x);
		if (index == arr.cbegin())
			return vector<int>(arr.cbegin(), arr.cbegin() + k);
		vector<int>::const_iterator b = index - 1, e = index;
		while (e - b - 1 < k) {
			if (e == arr.cend())
				return vector<int>(arr.cend() - k, arr.cend());
			else if (b == arr.cend())
				return vector<int>(arr.cbegin(), arr.cbegin() + k);
			if (*e - x < x - *b)
				++e;
			else if (b == arr.cbegin())
				b = arr.cend();
			else
				--b;
		}
		return vector<int>(b + 1, e);
	}
};
__________________________________________________________________________________________________
sample 13116 kb submission
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};
__________________________________________________________________________________________________
