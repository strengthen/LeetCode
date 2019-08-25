__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    
    vector < int > getFreq(vector < string > &A) {
        int n = A.size();
        
        vector < int > freq;
        for(int i = 0;i < n;++i) {
            char mi = 'z' + 3;
            for(int j = 0;j < A[i].size();++j) {
                mi = min(mi, A[i][j]);
            }
            
            int f = 0;
            for(int j = 0;j < A[i].size();++j) {
                if(A[i][j] == mi) {
                    ++f;
                }
            }
            freq.push_back(f);
        }
        return freq;
    }
    
    vector<int> numSmallerByLeadingCount(vector<string>& Q, vector<string>& A) {
        vector < int > freqA = getFreq(A);
        vector < int > freqQ = getFreq(Q);
        
        vector < int > ans;
        sort(freqA.begin(), freqA.end());
        
        for(int i = 0;i < freqQ.size();++i) {
            int x = freqQ[i];
            int lo = 0, hi = freqA.size();
            while(lo + 1 < hi) {
                int mid = lo + (hi - lo)/2;
                if(freqA[mid] > x) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            while(hi > 0 and freqA[hi - 1] > x) {
                --hi;
            }
            ans.push_back(A.size() - hi);
            
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    vector<int> numSmallerByLeadingCount(vector<string>& queries, vector<string>& words) {
        
        vector<int>b(11, 0);
        
        for(int i=0;i<words.size();i++){
            string s=words[i];
            vector<int>f(26,0);
            for(int j=0;j<s.size();j++)
                f[s[j]-'a']++;
            for(int j=0;j<26;j++)
                if(f[j]>0){
                    b[f[j]]++;
                    break;
                }
        }
        
        vector<int>ans(queries.size(),0);
        
        for(int i=0;i<queries.size();i++){
            string s=queries[i];
            vector<int>f(26,0);
            for(int j=0;j<s.size();j++)
                f[s[j]-'a']++;
            for(int j=0;j<26;j++)
                if(f[j]>0){
                    int val =f[j];
                    int sum=0;
                    for(int k=val+1;k<11;k++)
                        sum+=b[k];
                    ans[i]=sum;
                    break;
                }
            
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
