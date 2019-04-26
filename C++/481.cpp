__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int magicalString(int n) {
        int res(1);
        if(!n) return 0;
        string str(n,'0');
        str[0] = '1';
        // Initialize the string

        int idx1(0), idx2(0);
        // idx1 corresponds to the pointer to the actual string
        // idx2 corresponds to the pointer to the number

        while(idx1<n) {
            int rep = str[idx2] - '0'; // Get the number of repeats
            if(rep==2) {
                idx1++;
                if(idx1==n) break;
                str[idx1] = str[idx1-1];
                if(str[idx1]=='1') res++;
            }
            idx2++;
            idx1++;
            if(idx1<n) {
                str[idx1] = str[idx1-1]=='1'?'2':'1';
                if(str[idx1]=='1') res++;
            }
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 8844 kb submission
class Solution {
public:
    int magicalString(int n) {
        if(n<=0)return 0;
        if(n<=3)return 1;
        int sim[100002];
        sim[0]=1;
        sim[1]=2;
        sim[2]=2;
        int id = 2;
        int res = 1;
        int next = 1;
        int qid = 3;
        while(qid<n){
            int mul = 1;
            sim[qid++]=next;
            if(sim[id]==2&&qid<n)sim[qid++]=next,++mul;
            res+=mul*(next==1);
            next = next%2+1;
            ++id;
        }
        return res;
    }
};
__________________________________________________________________________________________________
