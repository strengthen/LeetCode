__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = (minutesToTest - 1) / minutesToDie + 1;
        if (buckets == 1) return 0;
        return log(buckets - 1) / log(t + 1) + 1;
    }
};
__________________________________________________________________________________________________
sample 8136 kb submission
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int matrix_size = minutesToTest / minutesToDie + 1;
        int num_dimensions = 0;
        while (pow(matrix_size, num_dimensions) < buckets) ++num_dimensions;
        return num_dimensions;
    }
};
__________________________________________________________________________________________________
