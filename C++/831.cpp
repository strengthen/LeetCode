__________________________________________________________________________________________________
× Close
sample 4 ms submission
class Solution {
public:
    string maskPII(string S) {
        if(S == "") return "";
        if(S.find('@') != string::npos) return mask1(S);
        else {
            int nums = 0;
            string toMask = "";
            for(int i = 0; i < S.size(); ++i) {
                if('0' <= S[i] && S[i] <= '9') {
                    nums += 1;
                    toMask += S[i];
                }
            }
            if(nums == 10) return mask2(toMask);
            else return mask3(toMask);
        }
        cout << "fuck" << endl;
        return "";
    }
    
    string mask1(const string& toMask) {
        auto pos = toMask.find('@');
        string domain = toMask.substr(pos);
        string name = toMask.substr(0, pos);
        char left = name[0], right = name.back();
        left = tolower(left);
        right = tolower(right);
        for(auto &ch : domain) ch = tolower(ch);
        string res = string(1, left) + "*****" + string(1, right) + domain;
        return res;
    }
    
    string mask2(const string& toMask) {
        string local = toMask.substr(toMask.size() - 4);
        string res = "***-***-" + local;
        return res;
    }
    
    string mask3(const string& toMask) {
        string local = toMask.substr(toMask.size() - 4);
        string res = "";
        if(toMask.size() == 11) res = "+*-***-***-" + local;
        else if(toMask.size() == 12) res = "+**-***-***-" + local;
        else res = "+***-***-***-" + local;
        return res;
    }
};
__________________________________________________________________________________________________
sample 8592 kb submission
class Solution {
public:
    string maskPII(string S) {
        int n = S.length();
        int lst = 0;
        int flag = 0;
        for(int i = 0;i<n;i++)
        {
            if(S[i]=='@')
            {   lst = i-1; 
                flag = 1;}
        }
        if(flag==1)
        {
            string ans = "";
            char a = S[0];
            char b = S[lst];
            if(S[0]<97  )
            a = S[0]+32;
            if(S[lst]<97 )
            b = S[lst]+32;
            ans+=a;
            ans+="*****";
            ans+=b;
            for(int i = lst+1;i<n;i++)
            {
                if(S[i]>64 && S[i]<92)
                    S[i]+=32;
                ans+=S[i];
            }
            return ans;
        }
        else{
            string ans = "";
            int count = 0;
            for(int i = 0;i<n;i++)
            {
                if(S[i]>=48 && S[i]<=57)
                {
                    count++;
                }
            }
            if(count==10)
            {
                ans = "***-***-";
                int c = 0;int lsi = 0;
                
                for(int  i= n;i>=0;i--)
                {
                    if(S[i]>=48 && S[i]<=57){
                        c++;
                        if(c==4)
                        {
                            lsi = i;
                            break;
                        }
                    }
                }
                for(int i = lsi;i<n;i++)
                {
                    if(S[i]>=48 && S[i]<=57){
                        ans+=S[i];
                    }
                }
               
            }
            else{
             
                ans = "+";
                for(int k = 11;k<=count;k++)
                    ans+="*";
                ans+="-***-***-";
                int c = 0;int lsi = 0;
                
                for(int i = n;i>=0;i--)
                {
                    if(S[i]>=48 && S[i]<=57){
                        c++;
                        if(c==4)
                        {
                            lsi = i;
                            break;
                        }
                    }
                }
                for(int i = lsi;i<n;i++)
                {
                    if(S[i]>=48 && S[i]<=57){
                        ans+=S[i];
                    }
                }
                
            }
            return ans;
        }
    }
};
__________________________________________________________________________________________________
