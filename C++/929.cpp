__________________________________________________________________________________________________
sample 12 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<std::string> count;
        for(auto &str:emails){
            int index = 0;
            int i = 0;
            bool plus = false;
            for(;i<str.size();i++){
                if(str[i]=='.') continue;
                
                if(str[i]=='+'){
                    plus = true;
                    break;
                }
                
                if(str[i]=='@') break;    
                str[index] = str[i];
                index++;
            }
            
            if(plus){
                for(;i<str.size();i++){
                    if(str[i]=='@') break;    
                }
            }               
        
            for(;i<str.size();i++){
                str[index] = str[i];
                index++;
            }
            str.resize(index);
            count.insert(str);
            
        }
        return count.size();
    }
};
__________________________________________________________________________________________________
× Close
sample 11148 kb submission
class Solution {
public:
    inline unsigned int emailHash(const string& email) {
        unsigned int seed = 131;
        unsigned int hash = 0;
        
        // 0 - localname
        // 1 - domain
        // 2 - '+' found
        unsigned int state = 0;
        
        for (auto&& c : email) {
            switch (state) {
                case 0:
                    if (c == '.') {
                    } else if (c == '+') {
                        state = 2;
                    } else if (c == '@') {
                        state = 1;
                    } else {
                        hash = hash * seed + c;
                    }
                    break;
                case 1:
                    hash = hash * seed + c;
                    break;
                case 2:
                    if (c == '@') {
                        state = 1;
                    }
                    break;
            }
        }
        
        return hash;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<unsigned int> h;
        for (auto&& email : emails) {
            h.insert(emailHash(email));
        }
        return h.size();
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
