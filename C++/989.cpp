__________________________________________________________________________________________________
sample 104 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        vector<int> out;
        for (int i = A.size() - 1; K > 0 || i >= 0; K /= 10) {
            if (i >= 0)
                K += A[i--];
            out.push_back(K % 10);
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
__________________________________________________________________________________________________
sample 12356 kb submission
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int step = 0,i=A.size()-1,temp;
        while (K!=0||step!=0){
            temp = K%10;
            if(i>=0){
              temp = temp + step+A[i];
              step = temp>=10?1:0;
              temp = step?temp-10:temp;
              A[i] = temp;
              i--;
            }else{
              temp+=step;
              step = temp>=10?1:0;
              temp = step?temp-10:temp;
              A.insert(A.begin(),temp);
            }
            K/=10;
        }
      return A;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
