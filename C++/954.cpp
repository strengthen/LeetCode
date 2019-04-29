__________________________________________________________________________________________________
sample 44 ms submission
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if(A.size()%2==1)return false;
        vector<int> lefts(10001,0);
        vector<int> rights(10001,0);
        int leftMax=INT_MIN,leftMin=INT_MAX;
        int leftCount=0,rightCount=0;
        int rightMax=INT_MIN,rightMin=INT_MAX;
        for(auto n:A ){
            if(n<0){
                leftCount++;
                leftMax=max(abs(n),leftMax);
                leftMin=min(abs(n),leftMin);
                lefts[abs(n)]++;
            }else{
                rightCount++;
                rightMax=max(abs(n),rightMax);
                rightMin=min(abs(n),rightMin);
                rights[n]++;
            }
        }
        if(leftCount%2==1)return false;
        bool result=true;
        if(leftCount>0){
            for(int i=leftMin;i<=leftMax;i++){
                for(int j=0;j<lefts[i];j++){
                    if(lefts[2*i]<1){
                        return false;
                    }
                    lefts[2*i]--;
                }
            }
        }
        if(rightCount>0){
            for(int i=rightMin;i<=rightMax;i++){
                for(int j=0;j<rights[i];j++){
                    if(rights[2*i]<1){
                        return false;
                    }
                    rights[2*i]--;
                }
            }
        }
        return result;
    }
};
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 14792 kb submission
bool comp(const int &a, const int &b)
{
    return abs(a) < abs(b);
}
class Solution {
public:
    
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> M;
        for(auto a:A)
            M[a]++;
        
        sort(A.begin(),A.end(),comp);
        
        for(auto a:A)
        {
            if(M[a]==0)
                continue;
            if(M[2*a] != 0)
            {
                M[a]--;
                M[2*a]--;
              //      cout<<a<<' '<<2*a<<endl;
                continue;
            }
        //    cout<<a<<endl;
            return false;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
