__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string addStrings(string num1, string num2) {
        int alen = num1.length(), blen = num2.length();
        int len = max(alen,blen);
        string zeros(abs(alen-blen),'0');
        if(alen>blen){
            num2=zeros+num2;
        }
        else{
            num1=zeros+num1;
        }
        string res;
        int carry = 0; int dig;
        for(int i=len-1; i>=0; i--){
            dig = (num1[i]-'0'+num2[i]-'0'+carry) % 10;
            carry = (num1[i]-'0'+num2[i]-'0'+carry) / 10;
            res.push_back(dig+'0');
        }
        if(carry!=0){
            res.push_back(carry+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
__________________________________________________________________________________________________
sample 9232 kb submission
class Solution {
public:
    string addStrings(string num1, string num2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(num1 == "0" && num2 == "0") return "0";
        string s;
        int sizeheigh = num1.size()>num2.size()?num1.size():num2.size();
        int sizelow = num1.size()<num2.size()?num1.size():num2.size();
        reverse(num1.begin() , num1.end());
        reverse(num2.begin() , num2.end());
        if(num1.size() == num2.size()){
            num1+='0';
            num2+='0';
        }
        else{
            num1.size() < num2.size() ? num1+='0':num2+='0';
        }
        
        for(int i=sizelow+1 ; i<=sizeheigh ; i++){
            if(num1.size() <= sizeheigh) num1 += '0';
            if(num2.size() <= sizeheigh) num2 += '0';
            
        }
        string ans = "";
        int numo = 0, numf = 0;
        for(int i=0 ; i<=sizeheigh ; i++){
            int numo = num1[i]-'0' + num2[i]-'0' + numf;
            numf = numo/10;
            s+=(numo%10)+'0';
        }
        reverse(s.begin() , s.end());
        if(s[0] == '0') s = s.substr(1 , sizeheigh);
        return s;
    }
};
__________________________________________________________________________________________________
