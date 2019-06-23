__________________________________________________________________________________________________
class Solution {
    set<string> merge(set<string>&a, set<string>&b){
        if(a.size() == 0){
            return b;
        }
        if(b.size() == 0){
            return a;
        }
        set<string> ans;
        for(auto& v1: a){
            for(auto& v2: b){
                ans.insert(v1+v2);
            }
        }
        return ans;
    }
    
    //{a,b,c}
    set<string> parseRule1(const string& str, int& i){
        set<string> ans;
        i++;
        ans = parseRule2(str, i);
        i++;
        return ans;
    }
    //{a,b},{c,d}
    set<string> parseRule2(const string& str, int& i){
        set<string> ans;
        ans = parseRule3(str, i);
        while(i<str.length()){
            if(str[i] != ','){
                break;
            }
            i++;
            set<string> tmp = parseRule3(str, i);
            ans.insert(tmp.begin(), tmp.end());
        }
        return ans;
    }
    //a{c,d}b{e,f}
    set<string> parseRule3(const string& str, int& i){
        set<string> ans;
        while(i < str.length()){
            if(str[i] == '}' || str[i] == ','){
                break;
            }
            if(str[i] == '{'){
                set<string> tmp = parseRule1(str, i);
                ans = merge(ans, tmp);
            }else{
                set<string> tmp;
                string tmpStr;
                while(i < str.length() && str[i] <= 'z' && str[i] >= 'a'){
                    tmpStr.push_back(str[i++]);
                }
                tmp.insert(tmpStr);
                ans = merge(ans, tmp);
            }
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string str) {
        int pos = 0;
        set<string> ans = parseRule2(str, pos);
        return vector<string>(ans.begin(), ans.end());
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
