__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int start = 0,end;
        string prefix = "a";
        set<char> vowl = {'a','e','i','o','u','A','E','I','O','U'};
        while(start>=0 && start<S.length()) {
            end = S.find(" ",start);
            if(end == string::npos) end = S.length();
            string word = S.substr(start,end-start);
            start = end + 1;
            if(vowl.find(word[0]) != vowl.end()) {
                res.append(word);
            } else {
                res.append(word.substr(1,word.length())).push_back(word[0]);
            }
            res.append("ma").append(prefix).push_back(' ');
            prefix.append("a");
        }
        return res.substr(0,res.length()-1);
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        istringstream ss(S);
        string res, t;
        int cnt = 1;
        while (ss >> t) {
            res += ' ' + (vowel.count(t[0]) ? t : t.substr(1) + t[0]) + "ma" + string(cnt, 'a');
            ++cnt;
        }
        return res.substr(1);
    }
};
__________________________________________________________________________________________________
sample 9276 kb submission
static int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string toGoatLatin(string S) {
        istringstream is(S);
        ostringstream os;
        string V="aeiouAEIOU",s,a="a";
        while(is>>s){
            if(V.find(s[0]) == string::npos)
                os << s.substr(1) << s[0];
            else
                os << s;
            os << "ma" << a << ' ';
            a.push_back('a');
        }
        string res = os.str();
        res.pop_back();
        return res;
    }
};
__________________________________________________________________________________________________
