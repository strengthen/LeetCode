__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool dfs(int set, int maxInteger, int total)
    {
        if (total <= 0) {
            return false;
        }
        if (dp[set]) {
            return dp[set] == 1;
        }
        for (int i = maxInteger - 1; i >= 0; --i) {
            int temp = 1 << i;
            if (!(set & temp) && !dfs(set | temp, maxInteger, total - i - 1)) {
                return dp[set] = 1;
            }
        }
        return !(dp[set] = -1);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal < 2) {
            return true;
        }
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (sum < desiredTotal) {
            return false;
        }
        if (sum == desiredTotal) {
            return maxChoosableInteger % 2;
        }
        return dfs(0, maxChoosableInteger, desiredTotal);
    }
    char dp[1 << 20]{};
};
__________________________________________________________________________________________________
sample 9748 kb submission
class Solution {
public:
    char dp[1 << 20];
    char helper(int turn, int total, int leftStep, int maxChoosableInteger, int desiredTotal) {
        if (total >= desiredTotal) return -turn;
        if (dp[leftStep] != 0) return dp[leftStep];

        for (int i = 0; i < maxChoosableInteger; i++) {
            if ((leftStep & (1 << i)) != 0) continue;
            if (helper(-turn, total + (i + 1), leftStep | (1 << i), maxChoosableInteger, desiredTotal) == turn) {
                dp[leftStep] = turn;
                return dp[leftStep];
            }
        }

        dp[leftStep] = -turn;
        return dp[leftStep];
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        if (desiredTotal == 0) return true;
        return helper(1, 0, 0, maxChoosableInteger, desiredTotal) == 1;
    }
};
__________________________________________________________________________________________________
