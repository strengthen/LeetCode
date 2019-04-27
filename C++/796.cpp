__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (
            A == B || (A + A).find(B) != string::npos
        );
    }
};
__________________________________________________________________________________________________
sample 8308 kb submission
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()){
            return false;
        }
        bool flag=false;
        int tmp = 0;
        int size = A.size();
        if(size==0){
            flag=true;
        }
        for(int i=0; i<size; i++){
            int flag2 = 1;
            for(int j=0; j<size; j++){
                tmp = (i+j)%size;
                if(A[tmp]!=B[j]){
                    flag2=0;
                }
            }
            if(flag2==1){
                flag=true;
                return flag;
            }
        }
        return flag;
    }
};
__________________________________________________________________________________________________
