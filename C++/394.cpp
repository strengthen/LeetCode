__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string decodeString(string s) {
        
        stack < pair<int,string> > stk;
        stk.push({1,""}); 
        int counter = 0;
        for ( int i = 0; i < s.size(); i ++ )
        {
            char currChar = s[i];
            if ( currChar == '[' )
            {
                stk.push( {counter, "" } );
                counter = 0;
            }
            //if number 
            else if ( isdigit(currChar) )
            {
                counter = counter*10 + currChar - '0'; //convert to int
            }
            
            else if ( isalpha(currChar) )
            {
                stk.top().second += currChar; 
            }
            else if ( currChar == ']' )
            {
                //got our closing bracket
                pair<int,string> top = stk.top();
                stk.pop();
                string temp = "";
                while(top.first)
                {
                    temp = temp + top.second;
                    top.first--;
                }
                //add the string to the previous 
                stk.top().second += temp;
            }
            
        }
        return stk.top().second;
    }
};
__________________________________________________________________________________________________
sample 8704 kb submission
class Solution {
public:
    string decodeString(string &s, int &i){
        string ans = "";
        int n = s.size();
        while(i < n && s[i] != ']'){
            if(isdigit(s[i])){
                int number = 0;
                while(s[i] <= '9' && s[i] >= '0' && i < n){
                    number = number * 10 + (int)s[i++] - 48;
                }
        
                ++i;
                string temp = decodeString(s, i);
                ++i;
                while(number-- > 0){
                    ans += temp;
                }
            }
            else{
                ans += s[i++];
            }
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};
__________________________________________________________________________________________________
