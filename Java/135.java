__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int candy(int[] ratings) {
        if (ratings.length == 0) {
            return 0;
        }
        int result = 1;
        int last = 1;
        for (int i=1; i<ratings.length;) {
            if (ratings[i] > ratings[i-1]) {
                last++;
                result += last;
                i++;
            } else if (ratings[i] == ratings[i-1]) {
                last = 1;
                result++;
                i++;
            } else {
                int count = 0;
                while (i < ratings.length && ratings[i] < ratings[i-1]) {
                    count++;
                    i++;
                }
                if (count >= last) {
                    result += (1+count)*count/2 + count + 1 - last;
                    last = 1;
                } else {
                    result += (1+count)*count/2;
                    last = 1;
                }
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 35960 kb submission
class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
}
__________________________________________________________________________________________________
