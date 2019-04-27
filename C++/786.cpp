__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        double max_f;
        double l = 0.0;
        double r = 1.0;
        int total = 0;
        double mid,f;
        int p,q;
        while(l < r){
            mid = (l + r) / 2;
            total = 0;
            p,q = 0;
            max_f = 0.0;
            int j = 1;
            for (int i = 0; i< A.size(); i++){
                while(j < n && A[i]>A[j]*mid) j++;
                total+=(n-j);
                if (n ==j) break;
                const double f = static_cast<double>(A[i])/A[j];
                if (f > max_f){
                    p = i;
                    q = j;
                    max_f = f;
                }
            }
            // cout << total << endl;
            if (total > K) r = mid;
            if (total < K) l = mid;
            if (total == K) return {A[p],A[q]};
        }
        return {};
    }
};
__________________________________________________________________________________________________
sample 9124 kb submission
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        double low =0, high =1.0;
        
        vector<int> result(2);
        //這題用1e-6 會錯 要用 1e-9
        while(low + 1e-9 < high){
            double mid = low + (high-low)/2;
            
            int p=0, q=1;
            int count=0;
            for(int i=-1,j=1;j<n;j++){
                while((double)A[i+1] < A[j] *mid) i++;
                count += i+1;
                
                if(i>=0 && (double)A[i] *q >  (double)A[j] *p){
                    p = A[i];
                    q = A[j];
                }
            }
            if(count < K)
                low = mid;
            else if(count > K)
                high = mid;
            else{
                result[0] = p;
                result[1] = q;
                break;
            }
        }
        return result;    
    }
};
__________________________________________________________________________________________________
