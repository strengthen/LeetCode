__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // LCS -> LIS
        vector<int> alph[128];  // record text1's alphabet in text2 pos.
        int maps[128];
        memset(maps, 0, sizeof(maps));
        for(int i = 0; i < text1.size(); i++) maps[text1[i]] = 1;
        
        for(int j = text2.size(); j > -1; j--) if(maps[text2[j]] == 1) alph[text2[j]].push_back(j);
        vector<int> nums;
        for(int i = 0; i < text1.size(); i++) {
            if(alph[text1[i]].size() > 0) nums.insert(nums.end(), alph[text1[i]].begin(), alph[text1[i]].end());
        }
        
        // get LIS's length by monotone stack method : O(nlogn)
        vector<int> pool;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] > pool.back() ) {
                pool.push_back(nums[i]);
            } else if(nums[i] == pool.back()) {
                continue;
            } else {
                int s = 0, e = pool.size() - 1, mid = 0;
                while(s < e) {
                    mid = (s + e)/2;
                    if(pool[mid] < nums[i]) s = mid + 1;
                    else e = mid;
                }
                pool[e] = nums[i];
            }
        }
        
        return pool.size();
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lena = text1.length(), lenb = text2.length();
        int record[lena + 1][lenb + 1];
        for(int i = 0; i < lena + 1; i++){
            for(int j = 0; j < lenb + 1; j++)
                record[i][j] = 0;
        }
        for(int i = 1; i < lena + 1; i++){
            for(int j = 1; j < lenb + 1; j++){
                if(text1[i - 1] ==  text2[j - 1]){
                    record[i][j] = record[i - 1][j - 1] + 1;
                    //cout << i << " " << j << endl;
                }
                else
                    record[i][j] = max(record[i - 1][j], record[i][j - 1]);
            }
        }
        return record[lena][lenb];
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
               int n=text1.size();
        int m=text2.size();
        int l[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    l[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1])
                    l[i][j]=l[i-1][j-1]+1;
                else
                    l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
        return l[n][m];
   
    }
    
};