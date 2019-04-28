__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
 public:
  bool isMonotonic(const std::vector<int> &A) {
    const int N = A.size();
    int i = 0;

    while (i + 1 < N && A[i] == A[i + 1]) {
      ++i;
    }

    bool inc = false;
    if (i + 1 < N) {
      inc = A[i] < A[i + 1];
    }
    while (i + 1 < N) {
      if ((A[i] < A[i + 1]) != inc && A[i]!=A[i+1]) {
        return false;
      }
      ++i;
    }
    return true;
  }
};
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        bool isIncreasing = true;
        bool isDecreasing = true;
        auto pit = A.cbegin();
        for(auto it = A.cbegin() + 1; it != A.cend(); ++it)
        {
            if(*it > *pit) isDecreasing = false;
            if(*it < *pit) isIncreasing = false; 
            pit = it;
            
            if(!isDecreasing && !isIncreasing)
                break;
        }
        return isIncreasing || isDecreasing;
    }
};
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
__________________________________________________________________________________________________
sample 14128 kb submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 1;
        
        pair<bool , int> p;
        p.first = false;
        p.second = 0;
        
        for(int i = 1 ; i < n ; ++i){
            if(!p.first){
                if(A[i] > A[i-1]){ p.first = true; p.second = 1;}
                if(A[i] < A[i-1]){ p.first = true; p.second = 2;}
            }
            
            else{
                if(p.second == 1) if(A[i] < A[i-1]) return 0;
                if(p.second == 2) if(A[i] > A[i-1]) return 0;
            }
        }
        
        return 1;
    }
};