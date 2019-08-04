__________________________________________________________________________________________________
sample 28 ms submission
class SnapshotArray {
public:
    int n;
    int snp = 0;
    vector < vector < pair < int, int > > > A;
    SnapshotArray(int len) {
        n = len;
        A.resize(n + 5);
        for(int i = 0;i < n;++i) {
            A[i].push_back({0, snp});
        }
    }
    
    void set(int idx, int val) {
        A[idx].push_back({val, snp});
    }
    
    int snap() {
        return snp++;
    }
    
    int get(int idx, int snap_id) {
        int lo = 0, hi = A[idx].size() - 1;
        while(lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[idx][mid].second > snap_id) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        while(lo + 1 <= hi and A[idx][lo + 1].second <= snap_id) {
            ++lo;
        }
        return A[idx][lo].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
__________________________________________________________________________________________________

__________________________________________________________________________________________________
