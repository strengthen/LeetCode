__________________________________________________________________________________________________
sample 4 ms submission
static int x = [](){std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;}();

class Solution {
public:
    
    char bin_search(vector<char>& arr, char target, int l, int r)
    {
        while(l <= r)
        {
            int m = l + ((r - l) >> 1);
            if(arr[m] > target) {
                if(m > 0 && arr[m - 1] <= target)
                    return arr[m];
                else
                    r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return arr[0];
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        return bin_search(letters, target, 0, letters.size() - 1);
    }
};
__________________________________________________________________________________________________
sample 9016 kb submission
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0; i < letters.size(); ++i) {
            if (letters[i] > target) return letters[i];
        }
        return letters[0];
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
