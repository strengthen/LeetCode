__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string reverseOnlyLetters(string S) {
    
      int i = 0, j = S.size() - 1;
      while (i < j) {
        while (i < j && !isalpha(S[i])) ++i;
        while (i < j && !isalpha(S[j])) --j;
        swap(S[i++], S[j--]);
      }
      return S;
    }
};
__________________________________________________________________________________________________
sample 8320 kb submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
     bool isLetter(char letter){
        int n = (int) letter;
        if ((n >= 'A' && n <='Z') || (n >= 'a' && n <='z')) return true;
        return false;
    }
    string reverseOnlyLetters(string S) {
        
        int n = S.length();
        int l = 0 , r = n-1;
        
        while(l < r){
            if(!isLetter(S[l])) { l++; continue; }
            if(!isLetter(S[r])) { r--; continue; }
            
            swap(S[l] , S[r]);
            ++l;
            --r;
        }
        
        return S;
    }
};
__________________________________________________________________________________________________
