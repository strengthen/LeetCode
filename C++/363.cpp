__________________________________________________________________________________________________
sample 16 ms submission
static auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// Time complexity -> O( columns x columns x rows x log rows)
//  time complexity is O[min(m,n)^2 * max(m,n) * log(max(m,n))], space O(max(m, n))
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        int width = matrix.size(), height = matrix[0].size();

		int result = -INT_MAX;
		for (int row1 = 0; row1 < height; row1++) {
			vector<int> sum(width, 0);
			for (int row2 = row1; row2 < height; row2++) {
				for (int column = 0; column < width; column++) {
					sum[column] += matrix[column][row2];
				}

				int curSum = 0;
				for (int s : sum) {
					curSum += s;
					if (k == s || curSum == k) return k;
					if (curSum < k && curSum > result) result = curSum;
					if (curSum < 0) curSum = 0;
				}
				if (curSum < k) continue;

				int curMax = INT_MIN;
				set<int> sumSet;
				sumSet.insert(0);
				for (int s : sum) {
					curSum += s;
					auto it = sumSet.lower_bound(curSum - k);
					if (it != sumSet.end()) {
						curMax = std::max(curMax, curSum - *it);
					}
					if (result == k) return k;
					sumSet.insert(curSum);
				}
				result = max(result, curMax);
			}
		}

		return result;
    }
};
__________________________________________________________________________________________________
sample 10000 kb submission
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int kk) {
        int w = matrix.size();
        int h = matrix[0].size();
        int sums[w][h];
        int i,j,k,l;
        sums[0][0] = matrix[0][0];
        for(i=1; i<w; i++){
            sums[i][0] = sums[i-1][0]+matrix[i][0];
        }
        for(j=1; j<h; j++){
            sums[0][j] = sums[0][j-1]+matrix[0][j];
        }
        for(i=1; i<w; i++ ){
            for(j=1; j<h; j++){
                sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i][j];
            }
        }
        int res = matrix[0][0];
        for(i=0; i<w; i++){
            for(j=0; j<h; j++){
                for(k=i; k<w; k++){
                    for(l=j; l<h; l++){
                        int pr=0,pc=0,prc=0;
                        if(i>0) pr = sums[i-1][l];
                        if(j>0) pc = sums[k][j-1];
                        if(i>0 && j>0) prc = sums[i-1][j-1];
                        int area = sums[k][l] - pr - pc + prc;
                        if (kk >= area){
                            res = (abs(kk-area) < abs(kk-res)) ? area : res;
                        }
                    }
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
