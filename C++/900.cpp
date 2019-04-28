__________________________________________________________________________________________________
sample 8 ms submission
class RLEIterator {
public:
    vector<int> A;
    vector<int> B;
    int64_t i = 0;
    int64_t ii = 0;
    RLEIterator(vector<int>& a) {
        for(int i = 0; i < a.size(); i+=2) {
            A.push_back(a[i]);
            B.push_back(a[i+1]);
        }
    }
    
    int next(int n) {
        while(true) {
            if(A[i] == 0) {
                i++;
                continue;
            }
            if(i >= A.size()) {
                return -1;
            }
            if(ii + n <= A[i]) {
                ii += n;
                int ret = B[i];
                if(ii == A[i]) {
                    ii = 0;
                    i++;
                }
                return ret;
            }
            n -= (A[i] - ii);
            ii = 0;
            i++;
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
__________________________________________________________________________________________________
sample 10024 kb submission
class RLEIterator {
    vector<int> arr;
    int idx, used;
public:
    RLEIterator(vector<int> arr) {
        this->arr=arr;
        idx=used=0;
    }
    
    int next(int n) {
        while (idx<arr.size()){
            if (arr[idx]-used<n){
                n-=(arr[idx]-used);
                idx+=2;
                used=0;
            }
            else{
                used+=n;
                return arr[idx+1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
__________________________________________________________________________________________________
