__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> ans = {};
    int maxSum = -1;
    
    bool IsValid(vector<int> &nums) {
        
        if (nums[0] > 2) {
            return false;
        }
        
        if (nums[0] == 2 && nums[1] > 3) {
            return false;
        }
        
        if (nums[2] > 5) {
            return false;
        }
    
        return true;
    }
    
    void Permutation(vector<int> &A, int l, int r) {
        
        if (l >= r) {
            
            int sum = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
            
            if (IsValid(A) && sum > maxSum) {
                ans = A;
                maxSum = sum;
            }
            return;
        }
        
    
        for (int i = l; i <= r; ++i) {
            swap(A[l], A[i]);
            Permutation(A, l+1, r);
            swap(A[l], A[i]);
        }
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        
        
        Permutation(A, 0, A.size()-1);
        
        if (ans.size() == 0) {
            return "";
        }
        
        return to_string(ans[0]) + to_string(ans[1]) + ":" + to_string(ans[2]) + to_string(ans[3]);
    }
};
__________________________________________________________________________________________________
sample 8456 kb submission
auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.rbegin(),A.rend());
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i!=j && i!=k && j!=k){
                        int hour=A[i]*10+A[j];
                        int minute=A[k]*10+A[6-i-j-k];
                        if(hour<=23 && minute<=59){
                            return to_string(A[i])+to_string(A[j])+":"+to_string(A[k])+to_string(A[6-i-j-k]);
                        }
                    }
                }
            }
        }
        
        return "";
        
        
    }
};
__________________________________________________________________________________________________
