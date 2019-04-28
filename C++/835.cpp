__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> Abits, Bbits;
        toBitset(A, Abits);
        toBitset(B, Bbits);

        int r = A.size(), c = A[0].size();
        int res = comp(Abits, Bbits, r, c);
        // shift to left and up can be done by this way
        // res = max(res, comp(Bbits, Abits, r, c));
        return res;
    }

    int comp(vector<int>& Abits, vector<int>& Bbits, int r, int c) {
        int res = 0;
        for (int i = -(r - 1); i < r; i++) {
            for (int j = -(c - 1); j < c; j++) {
                int total = 0;
                for (int k = 0; k < r; k++) {
                    int i1 = i > 0? i : 0, i2 = i < 0? -i : 0;
                    if (k + i1 >= r || k + i2 >= r) continue;
                    int j1 = j > 0? j : 0, j2 = j < 0? -j : 0;
                    int val = (Abits[k + i1] >> j1) & (Bbits[k + i2] >> j2);
                    total += bitset<30>(val).count();
                }
                res = max(res, total);
            }
        }
        return res;
    }

    void toBitset(const vector<vector<int>>& A, vector<int>& res) {
        for (int i = 0; i < A.size(); i++) {
            int val = 0;
            for (int j = 0; j < A[i].size(); j++) {
                val <<= 1;
                val += A[i][j];
            }
            res.push_back(val);
            // cout<<val<<" ";
        }
        // cout<<endl;
    }
};
__________________________________________________________________________________________________
sample 9220 kb submission
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rows=A.size();
        int cols=A[0].size();
        
        if(rows ==0 || cols==0) return 0;
        
        int maxol=0;
        
        for(int rs=0; rs<rows; rs++) {
            int rlen=rows-rs;
            for(int cs=0; cs<cols; cs++) {
                int clen=cols-cs;
                int thisol=0;
                for (int i=0; i<rlen; i++) {
                    for (int j=0; j<clen;j++) {
                        if(A[i][j] && B[rs+i][cs+j])
                            thisol++;
                    }
                }
                #printf("rs=%d, rlen=%d, cs=%d, clen=%d, thisol=%d, maxol=%d\n", rs, rlen, cs, clen, thisol, maxol);
                if (thisol >maxol)
                    maxol=thisol;
                
                 thisol=0;
                for (int i=0; i<rlen; i++) {
                    for (int j=0; j<clen;j++) {
                        if(A[i+rs][j+cs] && B[i][j])
                            thisol++;
                    }
                }
                #printf("rs=%d, rlen=%d, cs=%d, clen=%d, thisol=%d, maxol=%d\n", rs, rlen, cs, clen, thisol, maxol);
                if (thisol >maxol)
                    maxol=thisol;                 
            }  
        }
        
        return maxol;
    }
};
__________________________________________________________________________________________________
