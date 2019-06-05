__________________________________________________________________________________________________
sample 0 ms submission
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 34068 kb submission
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int i = 1, j = n -1 ;
    while(i <= j) {
        int mid = i + (j - i) / 2;
        if(guess(mid) == 0) {
            return mid;
        } else if(guess(mid) == 1) {
            i = mid + 1;
        } else {
            j = mid -1;
        }
    }
    return i;        
    }
}
__________________________________________________________________________________________________
