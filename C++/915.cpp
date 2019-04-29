__________________________________________________________________________________________________
sample 16 ms submission
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {

        int runningMax = A[0];
        int candidate = 0;
        int tempMax = A[0];
        for(int i=1;i<A.size();i++){
            if(A[i]<runningMax){
                candidate = i;
                continue;
            }
            //cout<<"Got "<<A[i]<<" max being "<<runningMax<<endl;
            while(i<A.size() && A[i]>=runningMax){
                //cout<<"Got "<<A[i]<<" tempmax being "<<tempMax<<endl;
                tempMax=max(tempMax,A[i]);
                ++i;
            }
            if(i>=A.size())break;
            runningMax=tempMax;
            candidate = i;
        }
        return candidate+1;
    }
};
__________________________________________________________________________________________________
sample 11024 kb submission
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int max_now = A[0];
        int allmax = A[0];
        int res = 1;
        for(int i=0;i<A.size();i++){
            if(A[i] < max_now){
                res = i+1;
                max_now = allmax;
            }
            else{
                allmax = max(allmax,A[i]);
            }
        }
        return res;
        
    }
};
__________________________________________________________________________________________________
