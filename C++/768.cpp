__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> mins(arr.size(), INT_MAX);
        for (int i=arr.size()-2;i>=0;i--)
            mins[i] = min(mins[i+1], arr[i+1]);
        int maxV = -1, count = 0;
        for (int i=0; i<arr.size();i++) {
            maxV = max(maxV, arr[i]);
            if (maxV<=mins[i]) count += 1;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 9800 kb submission
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        
        vector<int> aux(N,arr.back());
        for(int i=N-2;i>=0;i--)
            aux[i] = min(arr[i],aux[i+1]);
        
        int chunk = 0, max_v = -1;
        for(int i=0;i<N;i++){
            max_v = max_v == -1 ? arr[i] : max(max_v,arr[i]);
            if(i == N-1 || max_v <= aux[i+1]){
                chunk++;
                max_v = -1;
            }
        }
        return  chunk;
    }
};
__________________________________________________________________________________________________
