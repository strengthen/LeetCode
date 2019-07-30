__________________________________________________________________________________________________
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        sort(begin(A), end(A));
        while (A.size() >= 2 and A.back() == A[A.size() - 2]) {
            int x = A.back();
            while (!A.empty() and A.back() == x) {
                A.pop_back();
            }
        }
        if (A.empty()) {
            return -1;
        }
        return A.back();
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int,int> M;
        int ans = -1;
        for(int num : A) {
            M[num]++;
        }
        
        for(auto KV : M) {
            if(KV.second == 1) {
                ans = max(ans,KV.first); 
            }
        }
        
        return ans;
    }
};

__________________________________________________________________________________________________
