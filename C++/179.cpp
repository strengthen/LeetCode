__________________________________________________________________________________________________
sample 4 ms submission
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();


//x<y 当且仅当 [xy]<[yx]
bool Less(const std::string& x,const std::string& y){
    //return x+y<y+x;
    int len_x = x.size();
    int len_y = y.size();
    int len = std::min(len_x,len_y);
    
    for(int i=0;i<len;i++){
        if(x[i]!=y[i]) return x[i]<y[i];
    }
    
    if(len_x>len_y){
        for(int i=len;i<len_x;i++){
            if(x[i]!=x[i-len_y]) return x[i]<x[i-len_y]; 
        }
        for(int i=len_x;i<len_x+len_y;i++){
            if(y[i-len_x]!=x[i-len_y]) return y[i-len_x]<x[i-len_y]; 
        }      
    }
    
    if(len_x<len_y){
        for(int i=len;i<len_y;i++){
            if(y[i-len_x]!=y[i]) return y[i-len_x]<y[i]; 
        }   
        for(int i=len;i<len_y;i++){
            if(y[i-len_x]!=x[i-len_y]) return y[i-len_x]<x[i-len_y]; 
        }          
    }
    
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> temp;
        for(int i:nums){
            temp.emplace_back(std::to_string(i));
        }
        std::sort(temp.begin(),temp.end(),Less);
        if(temp[nums.size()-1]=="0") return "0";
        std::string res;
        for(auto it=temp.rbegin();it!=temp.rend();++it){
            res += *it;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8892 kb submission
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
        list<string> L;
        list<string>::iterator itr;
        
        for(int i = 0; i < nums.size(); ++i){
            string cur = int2string(nums[i]);
            for(itr = L.begin(); itr != L.end(); ++itr){
                if(larger(cur, *itr)){
                    L.insert(itr, cur);
                    break;
                }
            }
            if(itr == L.end()) L.push_back(cur);
        }
        
        string result;
        for(itr = L.begin(); itr != L.end(); ++itr){
            result.append(*itr);
        }

        if(result[0] == '0') return "0";
        else return result;
        
    }
    
    bool larger(string st1, string st2){
        string tem1 = st1+st2;
        string tem2 = st2+st1;
        
        for(int i = 0; i < tem1.size(); ++i){
            if(tem1[i] > tem2[i]) return true;
            else if(tem1[i] < tem2[i]) return false;
        }
        
        if(st1.size() < st2.size()) return true;
        else return false;
    }
    
    string int2string(int num){
        if(num == 0) return "0";    //处理0的情况
        
        string result;
        
        while(num != 0){
            result.push_back('0'+num%10);
            num /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
};
__________________________________________________________________________________________________
