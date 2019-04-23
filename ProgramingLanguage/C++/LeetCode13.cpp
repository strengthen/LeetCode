__________________________________________________________________________________________________
12ms
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    int romanToInt(string &s) {
        int num[26] = {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
        int res = 0;
        int len = s.size();
        for(int i=0;i<s.size();i++){
            res += num[s[len-i-1]-'A'];
            if(s[len-i-1]=='V' || s[len-i-1]=='X') num['I'-'A'] = -1;
            if(s[len-i-1]=='L' || s[len-i-1]=='C') num['X'-'A'] = -10;
            if(s[len-i-1]=='D' || s[len-i-1]=='M') num['C'-'A'] = -100;
        }
        return res;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    int charValue(char c)
    {
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5 ; 
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100 ; 
            case 'D' : return 500;
            case 'M' : return 1000;
                default : 
                return 0;
        }
        return 0;
    }
    
    
    int romanToInt(string s) 
    {
        int result=0;
        if(s.empty()) return 0;
        if(s.size()==1) return charValue(s[0]); // only 1 
        
        int temp=charValue(s[0]); // store first char 
        for(int i =1;i<s.size();++i)
        {
            int v = charValue(s[i]); // from 1 calcuate the char value 
            if(v>temp) // if its greater then IV we have to minus for the value 5-1
            {
                result=result-temp;
                temp=v;
                
            }
            else 
            {
                result=result+temp; // VI we have to add 5+1
                temp=v;
            }
        }
        result+=temp;
        return result; 
    }
};
__________________________________________________________________________________________________
20ms
namespace {  
  int getTokenValue(const char c) {
    switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
    }
  }                                 
}

class Solution {
  public:
  int romanToInt(string s) {
    vector<int> values;
    values.resize(s.size());
    std::transform(s.begin(), s.end(), values.begin(), &getTokenValue);
    
    for (int i = 1; i < values.size(); ++i) {
      if ((values[i-1] == values[i] / 10) ||
          (values[i-1] == values[i] / 5)) {
        values[i-1] *= -1;
      }
    }
    
    return std::accumulate(values.begin(), values.end(), 0);
  }
};
__________________________________________________________________________________________________
8204 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int va[]{1,5,10,50,100,500,1000};
        string sy="IVXLCDM";
        int t[s.size()];
        for(int i = 0; i<s.size();i++)
        {
            for(int j=0;j<7;j++)
            {
                if(s[i]==sy[j])
                {
                    t[i]=j;
                    break;
                }
            }
        }
        int re = 0;
        for(int i=0;i<s.size();i++)
        {
            re+=va[t[i]];
            if(i!=s.size()-1&&t[i]<t[i+1])
            {
                re += va[t[i+1]]-2*va[t[i]];
                i++;
            }
        }
        return re;
    }
};
__________________________________________________________________________________________________
8344 kb
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution {
public:
    int romanToInt(string s) {
        enum prior { I = 1, IV = 4, V=5, IX = 9, X=10, XL = 40, L=50, XC = 90, C=100,CD = 400, D=500,CM= 900, M=1000};
        int ans = 0;
        int i = 0, l = s.length();
        while(i<l){
            char x = s[i];
            switch(x){
                case 'M':
                    ans+=M;
                    i++;
                    continue;
                case 'D':
                    ans+=D;
                    i++;
                    continue;
                case 'C':
                    if(i+1<l && s[i+1]=='D'){
                        ans+=CD;
                        i+=2;
                        continue;
                    }
                    else if(i+1<l && s[i+1] == 'M'){
                        ans+=CM;
                        i+=2;
                        continue;
                    }
                    else{
                        ans+=C;
                        i++;
                        continue;
                    }
                case 'L':
                    ans+=L;
                    i++;
                    continue;
                case 'X':
                        if(i+1<l && s[i+1]=='L'){
                        ans+=XL;
                        i+=2;
                        continue;
                    }
                    else if(i+1<l && s[i+1] == 'C'){
                        ans+=XC;
                        i+=2;
                        continue;
                    }
                    else{
                        ans+=X;
                        i++;
                        continue;
                    }
                case 'V':
                    ans+=V;
                    i++;
                    continue;
                case 'I':
                      if(i+1<l && s[i+1]=='V'){
                        ans+=IV;
                        i+=2;
                        continue;
                    }
                    else if(i+1<l && s[i+1] == 'X'){
                        ans+=IX;
                        i+=2;
                        continue;
                    }
                    else{
                        ans+=I;
                        i++;
                        continue;
                    }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
