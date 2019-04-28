__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string pushDominoes(string a) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        char left = 'L';
        const int n = a.length();
        for (int i = 0; i < n; i++) {
            const char c = a[i];
            if ('.' == c) {
                int j = i + 1;
                while (j < n && a[j] == '.') {
                    j++;
                }
                char right = a[j] ? a[j] : 'R';

                const int dot_start = i;
                const int dot_end = j;
                const int len = dot_end - dot_start;

                if (left == 'L' && right == 'R') {
                    /*nothing*/
                }
                if (left == right) {
                    for (int j = dot_start; j < dot_end; j++) {
                        a[j] = left;
                    }
                }
                if (left == 'R' && right == 'L') {
                    const int step = len >> 1;
                    for (int j = 0; j < step; j++) {
                        a[dot_start+j] = 'R';
                        a[dot_end-j-1] = 'L';
                    }
                }
                
                left = right;
                i = dot_end;
            } else {
                left = c;
            }
        }
        return a;
    }
};
__________________________________________________________________________________________________
sample 11568 kb submission
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0,r = 0;
        while(i < n){
            if(dominoes[i] == 'L'){
                for(int j = i - 1;j >= 0 && dominoes[j] == '.';j--)dominoes[j] = 'L';
                i++;
            }else if(dominoes[i] == 'R'){
                int j = i + 1;
                while(j < n && dominoes[j] != 'L'){
                    if(dominoes[j] == 'R'){
                        for(int p = i;p < j;p++)dominoes[p] = 'R';
                        i = j;
                    }
                    j++;
                }
                if(j == n){
                    for(int k = i;k < n;k++)dominoes[k] = 'R';
                }else{
                    int k1,k2;
                    // cout<<"k1 = "<<i<<", k2 = "<<j<<endl;
                    for(k1 = i,k2 = j;k1 < k2;k1++,k2--){
                        dominoes[k1] = 'R';
                        dominoes[k2] = 'L';
                    }
                    if(k1 == k2)dominoes[k2] = '.';
                }                
                i = j + 1;
            }else{
                i++;
            }
            // cout<<"i = "<<i<<endl;
        }
        return dominoes;
        // "RR.L.R...L...RRR...L"
        
    }
};
__________________________________________________________________________________________________
