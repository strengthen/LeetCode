__________________________________________________________________________________________________
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        for (int i = 0; i < n; i++)
            hours[i] = hours[i] > 8 ? +1 : -1;

        vector<int> sums(n + 1, 0);

        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + hours[i];

        int best = 0;

        for (int i = 0; i < n; i++)
            for (int j = n; j > i && j - i > best; j--)
                if (sums[i] < sums[j])
                    best = j - i;

        return best;
    }
};

__________________________________________________________________________________________________
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for (int i = 0; i < hours.size(); ++i)
            if (hours[i] > 8) hours[i] = 1;
            else hours[i] = -1;
        
        int ans = 0;
        for (int i = 0; i < hours.size(); ++i) {
            int bal = 0, cur = -1;
            for (int j = i; j < hours.size(); ++j) {
                bal += hours[j];
                if (bal > 0) cur = j;
            }
            ans = max(ans, cur - i + 1);
        }
        return ans;
    }
};

__________________________________________________________________________________________________
