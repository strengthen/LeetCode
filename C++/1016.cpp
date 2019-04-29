__________________________________________________________________________________________________
sample 4 ms submission
bool checksub(string binary, string S){
    //int start,end=0;
    //size_t found = S.find(binary);
    if(S.find(binary)!= string::npos){
        return true;
    }
    else{
        return false;
    }
    
}
bool binary(int num, string S){
    vector<int> result;
    while(num>0){
        int temp = num%2;
        result.push_back(temp);
        num = num/2;
    }
    //result.push_back(0);
    reverse(result.begin(),result.end());
    string x = "";
    for(int i=0;i<result.size();i++){
        x+= to_string(result[i]);
    }
    //cout<<x<<endl;
    if(checksub(x, S)){
        //cout<<checksub(x,S)<<endl;
        return true;   
    }
    else{
        return false;    
    }
    
}
class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=N;i>=1;i--){
            if(!binary(i,S))
                return false;
            //cout<<i<<endl;
            //else continue;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N; i >= 1; --i) {
            const string& s = Int2Str(i);
            if (S.find(s) == string::npos) return false;
        }
        return true;
    }
    
    string Int2Str(int n) {
        if (n == 0) return "0";
        string s;
        while (n) {
            s += '0' + (n&0x1);
            n >>=1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
__________________________________________________________________________________________________
