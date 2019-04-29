__________________________________________________________________________________________________
sample 36 ms submission
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    vector<int> diStringMatch(string &S) {
        int len = S.size()+1;
        std::vector<int> res(len);
        int small = 0;
        int big = len-1;
    
        for(int i=0;i<len-1;i++){
            int mask = S[i]-'I';
            res[i] = mask ? big:small;
            big -= bool(mask);
            small += bool(!mask);
        }
        res[len-1] = small;
        return res;
    }
};
__________________________________________________________________________________________________
sample 10184 kb submission
class Solution {
public:
    vector<int> diStringMatch(string S) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int size = S.size();
        vector<int> v(size+1);
        int front = 0 , back = size;
        for(int i=0 ; i<size ; i++){
            if(S[i] == 'D'){
                v[i] = back;
                back--;
            }
            else{
                v[i] = front;
                front++;
            }
        }
        if(S[size-1] == 'D') v[size] = front;
        else v[size] = back;
        return v;
    }
};
__________________________________________________________________________________________________
