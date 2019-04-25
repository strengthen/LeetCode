__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n,"");
        int flag;
        for(int i = 0;i<n;i++){
            flag = 0;
            int j = i+1;
            if(j%3 == 0){
                res[i] += "Fizz";
                flag = 1;
            }
            if(j%5 == 0){
                res[i] += "Buzz";
                flag = 1;
            }
            if(flag == 0)
                res[i] = to_string(j);    
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 9680 kb submission
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for(int i = 1; i <=n;++i){
            if(i%3){
                if(i%5){
                    ret[i-1]=to_string(i);
                }
            }
            else{
                ret[i-1]=string("Fizz");
            }
            if(i%5==0)ret[i-1]+=string("Buzz");
        } 
        return ret;
    }
};
__________________________________________________________________________________________________
