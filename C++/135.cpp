__________________________________________________________________________________________________
12ms
class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        vector<int> candies(length, 0);
        int cur_max = 0;
        int prev = -1;
        for(int i = 0; i < length; ++i) {
            if (ratings[i] > prev) {
                ++cur_max;
                candies[i] = cur_max;
            } else {
                cur_max = 1;
                candies[i] = cur_max;
            }
            prev = ratings[i];
        }
        cur_max = 0;
        prev = -1;
        for(int i = length - 1; i >= 0; --i) {
            if (ratings[i] > prev) {
                ++cur_max;
                candies[i] = max(cur_max, candies[i]);
            } else {
                cur_max = 1;
                candies[i] = max(candies[i], cur_max);
            }
            prev = ratings[i];
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
9964 kb
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        int total = 1;
        int prev = 1;
        int countDown = 0;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                if (countDown > 0) {
                    total += countDown * (countDown + 1) / 2;
                    if (prev <= countDown) {
                        total += countDown + 1 - prev;
                    }
                    countDown = 0;
                    prev = 1;
                }
                if (ratings[i] == ratings[i - 1]) {
                    prev = 1;
                } else {
                    prev++;
                }
                total += prev;
            } else {
                countDown++;
            }
        }
        if (countDown > 0) {
            total += countDown * (countDown + 1) / 2;
            if (prev <= countDown) {
                total += countDown + 1 - prev;
            }
        }
        return total;
    }
};
__________________________________________________________________________________________________
