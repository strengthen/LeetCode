__________________________________________________________________________________________________
sample 4 ms submission
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            int x = guess(mid);
            
            if(x == 0) return mid;
            else if(x == 1) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 7984 kb submission
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        int start = 1;
        int finish = n;
        while(start <= finish){
            if(guess(start) == 0)
                return start;
            if(guess(finish) == 0)
                return finish;
            int middle = start + (finish - start) / 2;
            if(guess(middle) == 0)
                return middle;
            else if(guess(middle) < 0)
                finish = middle - 1;
            else
                start = middle + 1;
        }
        return 0;
    }
};
__________________________________________________________________________________________________
