__________________________________________________________________________________________________
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (helper(stations, K, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
    bool helper(vector<int>& stations, int K, double mid) {
        int cnt = 0, n = stations.size();
        for (int i = 0; i < n - 1; ++i) {
            cnt += (stations[i + 1] - stations[i]) / mid;
        }
        return cnt <= K;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            int cnt = 0, n = stations.size();
            for (int i = 0; i < n - 1; ++i) {
                cnt += (stations[i + 1] - stations[i]) / mid;
            }
            if (cnt <= K) right = mid;
            else left = mid;
        }
        return left;
    }
};
__________________________________________________________________________________________________
