__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string crackSafe(int n, int k) {
     
        const int m=pow(k,n-1);
        vector<int>p;
        for(int i=0;i<k;i++)
        {
            for(int q=0;q<m;q++)
            {
                p.emplace_back(q*k+i);
            }
        }
        
        const int total=pow(k,n);
        string result(n-1,'0'+k-1);
        for(int i=0;i<total;i++)
        {
            int j=i;
            while(p[j]>=0)
            {
                result.push_back('0'+j/m);
            
            auto pj=p[j];
            p[j]=-1;
            j=pj;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 8972 kb submission
class Solution {
public:
    string crackSafe(int n, int k) {
        // Compute the length. Total length will be s * k
        int s = 1;
        for (int i = 0; i < n - 1; ++i)
            s *= k;

        // Construct the permutation according to wiki
        std::vector<int> inds(s * k);
        for (int i = 0; i < k * s; ++i)
            inds[i] = i / s + (i % s) * k;

        std::string seq;
        for (int off = 0; off < s * k; ++off)
        {
            // Find cycles in the permutation
            int c = off, tmp = 0;
            while (inds[c] != -1)
            {
                seq.push_back(c / s + '0');
                tmp = inds[c];
                inds[c] = -1;
                c = tmp;
            }
        }

        // Need to append n - 1 more characters
        for (int i = 0; i < n - 1; ++i)
            seq.push_back(seq[i]);
        return seq;
    }
};
__________________________________________________________________________________________________
