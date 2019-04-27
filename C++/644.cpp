__________________________________________________________________________________________________
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        double res = (double)sums[k - 1] / k;
        for (int i = k; i < n; ++i) {
            double t = sums[i];
            if (t > res * (i + 1)) res = t / (i + 1);
            for (int j = i - k; j >= 0; --j) {
                t = sums[i] -  sums[j];
                if (t > res * (i - j)) res = t / (i - j);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double preSum = accumulate(nums.begin(), nums.begin() + k, 0);
        double sum = preSum, res = preSum / k;
        for (int i = k; i < nums.size(); ++i) {
            preSum += nums[i];
            sum = preSum;
            if (sum > res * (i + 1)) res = sum / (i + 1);
            for (int j = 0; j <= i - k; ++j) {
                sum -= nums[j];
                if (sum > res * (i - j)) res = sum / (i - j);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sums(n + 1, 0);
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= n; ++i) {
                sums[i] = sums[i - 1] + nums[i - 1] - mid;
                if (i >= k) {
                    minSum = min(minSum, sums[i - k]);
                }
                if (i >= k && sums[i] > minSum) {check = true; break;} 
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, sum = 0, preSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i] - mid;
                if (i >= k) {
                    preSum += nums[i - k] - mid;
                    minSum = min(minSum, preSum);
                }
                if (i >= k - 1 && sum > minSum) {check = true; break;}
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
};