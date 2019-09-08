__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& A, int st, int en) {
        int n = A.size();
        int d = 0, ans;
        for(int i = st;i != en;i = (i + 1) % n) {
            d += A[i];
        }
        ans = d;
        
        d = 0;
        for(int i = en;i != st;i = (i + 1) % n) {
            d += A[i];
        }
        return min(d, ans);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int result1 = 0;
        int result2 = 0;
        
        for (int i = start; i != destination; i = (i + 1) % distance.size()) {
            result1 += distance[i];
        }
        
        for (int i = destination; i != start; i = (i + 1) % distance.size()) {
            result2 += distance[i];
        }
        
        return min(result1, result2);
    }
};
__________________________________________________________________________________________________
