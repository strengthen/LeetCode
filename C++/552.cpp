__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    const int prime = 1000000007;

    struct Mat6 {
        int m[6][6];
    };

    const Mat6 identityMatrix = {
        {{1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0},
         {0, 0, 1, 0, 0, 0},
         {0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0},
         {0, 0, 0, 0, 0, 1}}
    };

    const Mat6 recurrenceMatrix = {
        {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0},
         {0, 0, 0, 1, 1, 1},
         {0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0}}
    };

    Mat6 mul(const Mat6& a, const Mat6& b) {
        Mat6 c;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                long long x = 0;
                for (int k = 0; k < 6; k++) {
                    x += (static_cast<long long>(a.m[i][k]) * b.m[k][j]) % prime;
                }
                c.m[i][j] = static_cast<int>(x % prime);
            }
        }
        return c;
    }

    void pow(Mat6& a, int n) {
        auto r = identityMatrix;
        while (n != 0) {
            if ((n % 2) == 0) {
                a = mul(a, a);
                n /= 2;
            }
            else {
                r = mul(r, a);
                n--;
            }
        }
        a = r;
    }

    int checkRecord(int n) {
        auto a = recurrenceMatrix;
        pow(a, n + 1);
        return a.m[0][3];
    }
};
__________________________________________________________________________________________________
sample 8328 kb submission
class Solution {
public:
int checkRecord(int n) {
  long preP=1, preA=0, preAP=0, preL=0, preLL=0, preAL=0, preALL=0;
  long curP, curA, curAP, curL, curLL, curAL, curALL;
  for (int i=0; i<n; i++) {
    curP=(preP+preL+preLL)%1000000007;
    curA=(preP+preL+preLL)%1000000007;
    curAP=(preA+preAL+preALL+preAP)%1000000007;
    curL=preP;
    curLL=preL;
    curAL=(preA+preAP)%1000000007;
    curALL=preAL;
    preP=curP, preA=curA, preAP=curAP, preL=curL, preLL=curLL, preAL=curAL, preALL=curALL;
  }
  return (curP+curA+curAP+curL+curLL+curAL+curALL)%1000000007;
}
};
__________________________________________________________________________________________________
