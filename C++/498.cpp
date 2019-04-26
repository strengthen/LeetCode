__________________________________________________________________________________________________
sample 60 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	if (rows == 0) return {};
	int cols = matrix[0].size();
	if (cols == 0) return {};

	vector<int> res;
	int distance = rows + cols - 2;
	bool up_flag = true;
	if (rows < cols) {
	  for (int i = 0; i <= distance; ++i) {
		if (up_flag) {
		  for (int j = rows - 1; j >= 0; --j) {
			if (i < j || i - j >= cols) continue;
			res.push_back(matrix[j][i - j]);
		  }
		} else {
		  for (int j = 0; j <= i && j < rows; ++j) {
			if (i - j >= cols) continue;
			res.push_back(matrix[j][i - j]);
		  }
		}
		up_flag = !up_flag;
	  }
	} else {
	  for (int i = 0; i <= distance; ++i) {
		if (up_flag) {
		  for (int j = 0; j <= i && j < cols; ++j) {
			if (i - j >= rows) continue;
			res.push_back(matrix[i - j][j]);
		  }
		} else {
		  for (int j = cols - 1; j >= 0; --j) {
			if (i - j >= rows || i < j) continue;
			res.push_back(matrix[i - j][j]);
		  }
		}
		up_flag = !up_flag;
	  }
	}

	return res;
  }
};
__________________________________________________________________________________________________
sample 14260 kb submission
struct Solution {
    int m, n, i, j, k, diag;
    bool dirUp;

    inline void traverseDiags(const int endDiag, vector<int>& flat, vector<vector<int>>& matrix) {
        while (diag < endDiag) {

            // go up-right, or go down-left
            if (dirUp) {
                while (i >= 0 && j < n) flat[k++] = matrix[i--][j++];
                if (j == n) {
                    --j;
                    i += 2;
                }
                else
                    ++i;
            }
            else {
                while (j >= 0 && i < m) flat[k++] = matrix[i++][j--];
                if (i == m) {
                    --i;
                    j += 2;
                }
                else
                    ++j;
            }

            ++diag;
            dirUp = !dirUp;
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (!m) return {};
        n = matrix[0].size();

        matrix = matrix;

        // current coords into matrix
        i = 0;
        j = 0;

        // output array of flattened matrix, and current index into it
        vector<int> flat(m*n);
        k = 0;

        // current diagonal of a total of (m + n - 1) diag to traverse
        const int numDiags = m+n-1;
        diag = 0;

        // current direction to travel
        dirUp = true;

        // num diags to traverse for upper and lower triangle
        const int sqLen = min(m, n) - 1;

        traverseDiags(sqLen           , flat, matrix); // upper triangle
        traverseDiags(numDiags - sqLen, flat, matrix); // middle diags
        traverseDiags(numDiags        , flat, matrix); // lower triangle
        
        return flat;
    }
};
__________________________________________________________________________________________________
