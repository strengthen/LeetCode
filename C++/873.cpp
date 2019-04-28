__________________________________________________________________________________________________
sample 20 ms submission
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& A)
    {
        unordered_set<int> S(A.begin(), A.end());
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = i+1; j < A.size(); ++j)
            {
                int a = A[i], b = A[j];
                long long l = 2;
                if ((res - 2)*b > A.back()) break;
                while (S.count(a + b))
                {
                    b = a + b;
                    a = b - a;
                    ++l;
                }
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};
__________________________________________________________________________________________________
sample 8688 kb submission
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        
        int L = A.size();
        if (L<=3)
            return 0;
        int maxL=0;
        int res=0;
        for (int i=L-1; i>=0; --i)
        {
            
            if (res>=i+1)
                return res;  
            
            int key=A[i];
            int j=0,k=i-1;
            while(j<k)
            {
                if (A[j]+A[k]>key)
                    k--;
                else
                    if (A[j]+A[k]<key)
                        j++;
                    else  //if A[j]+A[k]==key
                    {
                        maxL=3;
                        //cout<<key<<"    "<<k<<" "<<j<<endl;
                        res = max(res, maxL);
                        int jj=j, kk=k;
                        helper(A,jj,kk,maxL,res);                        
                        j++;k--;
                    }
             }
            
            
        }
    
        return res;
    }
    
    void helper(vector<int> &A, int jj, int kk, int maxL, int &res)
    {
        for (int i=jj-1; i>=0; --i)
        {
            if (A[i]+A[jj]==A[kk])
            {
                maxL++;
                res = max(res, maxL);
                helper(A,i,jj,maxL,res);
                return;
            }
        }
    }
};
__________________________________________________________________________________________________
