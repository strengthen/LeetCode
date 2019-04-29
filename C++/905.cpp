__________________________________________________________________________________________________
sample 24 ms submission
const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int size = A.size();
        //if (size <= 1) return A;
        int i = 0;
        int j = size - 1;
        
        while(true) {
            while(A[i] % 2 == 0) {
                if (++i == size) break;
            }    
            
            while(A[j] % 2 == 1) {
                if (--j < 0) break;
            }
            
            if (i >= j) break;
            
            A[i] = A[i] + A[j];
            A[j] = A[i] - A[j];
            A[i] = A[i] - A[j];
        }
        
        return A;
    }
};
__________________________________________________________________________________________________
sample 9480 kb submission
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::partition(A.begin(), A.end(), [](auto a) { return (a & 1) == 0; });
        return std::move(A);
    }
};

static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
