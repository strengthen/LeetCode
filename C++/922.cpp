__________________________________________________________________________________________________
sample 76 ms submission
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		ios::sync_with_stdio(false);
		int i, j, len = A.size();
		for (i = 0, j = 1; i < len && j < len; i += 2, j += 2) {
			while (i < len && A[i] % 2 == 0)	i += 2;
			while (j < len && A[j] % 2 != 0)	j += 2;
			if (i < len && j < len) swap(A[i], A[j]);
		}
		return A;
	}
};
__________________________________________________________________________________________________
sample 11960 kb submission
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> sorted(A.size(), 0);
        int oddCounter = 1;
        int evenCounter = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) {
                sorted[evenCounter] = A[i];
                evenCounter += 2;
            } else {
                sorted[oddCounter] = A[i];
                oddCounter += 2;
            }
        }
        return sorted;
    }
};
__________________________________________________________________________________________________
