__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string add(string num1, string num2) {
        string a,b;
        int bit = 0, sum;
        int n,n1 = num1.length(), n2 = num2.length();
        if(n1 < n2) return add(num2, num1);
        for(int i =0;i<n1;i++)
        {
            if(i<n2)sum = num1[n1-i-1]+num2[n2-i-1]-96+bit;
            else if(!bit)break;
            else sum = num1[n1-i-1] -48 + bit;
            bit = 0;
            if(sum>9)
            {
                bit = 1;
                sum -= 10;
            }
            num1[n1-i-1] = sum + 48;
        }
        if(bit)num1 = '1' + num1;
        return num1;
    }
    bool dfs(string num, string a, string b)
    {
        //cout<<a<<" "<<b<<endl;
        if(b != "0" && num[0] == '0')return 0;
        string c = add(a,b);
        int bit = c.length();
        if(num.length()<bit)return 0;
        string s = num.substr(0,bit);
        //cout<<s<<endl;
        if(s!=c)return 0;
        if(bit==num.length())return 1;
        return dfs(num.substr(bit),b,s);
    }
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 1; i<n;i++)
        {
            if(num[0] == '0' && i > 1)break;
            string a = num.substr(0,i);
            for(int j = 1;i + j<=n;j++)
            {
                if(num[i] == '0' && j > 1)break;
                string b = num.substr(i,j);
                if(dfs(num.substr(i+j),a,b))return 1;
            }
        }
        return 0;
    }
};
__________________________________________________________________________________________________
sample 8032 kb submission
class Solution {
public:
    
    bool dfs(long int n1, long int n2, string& num, int start, int count){
        if(start==num.size()){
            if(count >= 3)
                return true;            
            return false;
        }
        string s;
        for(int i=start; i<num.size(); i++){
            s.push_back(num[i]);
            long int n3 = stol(s);
            if(n3>n1+n2)
                return false;
            if(n3==n1+n2){
                return dfs(n2,n3,num,i+1, count+1);
            }
            if(num[start]=='0')
                break;
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) 
    {
        string s;
        for(int i=0; i<num.size() && i<12; i++){
            s.push_back(num[i]);
            long int n1 = stol(s);
            string t;
            for(int j=i+1; j<num.size()-1  && j-i<12; j++){
                t.push_back(num[j]);
                long int n2 = stol(t);
                if(dfs(n1,n2,num,j+1, 2))
                    return true;
                if(num[i+1]=='0')
                    break;
            }
            if(num[0]=='0')
                break;
        }
        return false;
    }
};
__________________________________________________________________________________________________
