__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // just use greedy, think about a row a1,b2,x,x,a2,x,b1,x
        // to fix the first couple, swapping a1,b1 or b2,a2 has no effect on later actions
        // will end up with either a1,a2,x,x,b2,x,b1,x, or b1,b2,x,x,a2,x,a1,x
        int n = row.size(), cnt = 0;
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[row[i]] = i;
        for (int i = 0; i < n; i += 2) {
            if (row[i]/2 != row[i+1]/2) { // not a couple
                fix(row, pos, i);
                cnt++;
            }
        }
        return cnt;
    }

    void fix(vector<int> &row, vector<int> &pos, int i) {
        // don't actually need to do full swap, moving one number is enough
        // because we don't care about already "fixed" couples
        int x = row[i];
        int y = x % 2 ? x - 1 : x + 1;
        row[pos[y]] = row[i+1];
        pos[row[i+1]] = pos[y];
    }
};
__________________________________________________________________________________________________
sample 8608 kb submission
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        return bruteForce(row);
    }

    int bruteForce(vector<int>& row) {
        if (row.empty())
            return 0;
        
        const int n = row.size();
        int ret = 0;
        for (int i=0; i<n-1; i += 2) {
            int x = row[i];
            int y = (x^1);
            if (row[i+1] == y) continue;
            ++ret;
            for (int j=i+2; j<n; ++j) {
                if (row[j] == y) {
                    row[j] = row[i+1];
                    row[i+1] = y;
                    break;
                }    
            }
        }
        return ret;
    }
    
    // Should be TLE (because it's complexity is O(n!))
    int solve(vector<int>& rows, int p) {
    	if (p >= rows.size()) 
    		return 0;

    	int x = rows[p];
    	int y = rows[p+1];

    	if (x == (y^1))
    		return solve(rows, p+2);

    	int ret = 2e9;
    	for (int j=p+1; j<rows.size(); ++j) {
    		if (rows[j] == (x^1)) {
    			swap(rows[j], rows[p+1]);
    			ret = min(ret, solve(rows, p+2)+1);
    			swap(rows[j], rows[p+1]);
    		}

    		if (rows[j] == (y^1)) {
    			swap(rows[j], rows[p]);
    			ret = min(ret, solve(rows, p+2)+1);
    			swap(rows[j], rows[p]);	
    		}
    	}

		return ret;
    }    
};
__________________________________________________________________________________________________
