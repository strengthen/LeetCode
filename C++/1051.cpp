__________________________________________________________________________________________________
class Solution {
    const static int RANGE = 100;
    int count[RANGE + 1];
    
    vector<int> csort(vector<int>& arr, int n) {
        memset(count, 0, sizeof(count));
        vector<int> ret(n);
        for (int t : arr)
            count[t]++;
        int j = 0;
        for (int i = 1; i <= RANGE; i++) {
            while (count[i]--)
                ret[j++] = i;
        }
        return ret;
    }
    
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> temp = csort(heights, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] != heights[i])
                ans++;
        }
        return ans;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
