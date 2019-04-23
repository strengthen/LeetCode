__________________________________________________________________________________________________
8ms
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
	int rows = matrix.size();
	if (rows == 0) return 0;
	int cols = matrix[0].size();
	if (cols == 0) return 0;

	vector<int> left(cols, 0);
	vector<int> right(cols, cols);
	vector<int> height(cols, 0);

	int area = 0;
	for (int i = 0; i < rows; ++i) {
	  int current_left = 0;
	  int current_right = cols;

	  for (int j = 0; j < cols; ++j) {
		if (matrix[i][j] == '1') {
		  ++height[j];
		  left[j] = max(left[j], current_left);
		} else {
		  height[j] = 0;
		  left[j] = 0;
		  current_left = j + 1;
		}
	  }
	  
	  for (int j = cols - 1; j >=0; --j) {
		if (matrix[i][j] == '1') {
		  right[j] = min(right[j], current_right);
		} else {
		  right[j] = cols;
		  current_right = j;
		}
	  }

	  for (int j = 0; j < cols; ++j) 
		area = max(area, (right[j] - left[j]) * height[j]);
	}

	return area;
  }
};
__________________________________________________________________________________________________
10748 kb
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> A(m, 0);
        stack<int>  st;
        
        int ans = 0, pos = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[j] = matrix[i][j] == '1' ? A[j]+1 : 0;
                while (!st.empty() && A[st.top()] > A[j]) {
                    pos = st.top(); st.pop();
                    ans = max(ans, A[pos] * (st.empty() ? j : j-st.top()-1));
                }
                st.push(j);
            }
            
            while (!st.empty()) {
                pos = st.top(); st.pop();
                ans = max(ans, A[pos] * (st.empty() ? m : m-st.top()-1));
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
