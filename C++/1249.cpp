__________________________________________________________________________________________________
sample 4 ms submission
//Fast IO
static auto magic = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); return false;}();

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		//Parse for the number of wrong parenthesis
		string ans = s;
		int count = 0;
		int index = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != '(' && s[i] != ')')
			{
				ans [index++] = s[i];
			}
			else {
				if (s[i] == '(')
				{
					count++;
					ans[index++] = s[i];
				}
				else {
					if (count > 0)
					{
						count--;
						ans[index++] = s[i];
					}
				}
			}
		}
		ans = ans.substr(0, index);
		if (count == 0)
			return ans;
		
		//If count > 0, it means we need to remove '(' count number of times from the end
		index = 0;
		string res = ans;
		for (int i = ans.length()-1; i >=0 ; i--)
		{
			if (ans[i] == '(' && count > 0)
			{
				count--;
			}
			else {
				res[index++] = ans[i];
			}
		}
		res = res.substr(0, index);
		
		//reverse the string as we have parsed it from the back in the before loop
		int left = 0;
		int right = res.length() - 1;
		while (left < right)
		{
			char te = res[left];
			res[left] = res[right];
			res[right] = te;
			left++;
			right--;
		}
		
		//return the result
		return res;
	}
};
__________________________________________________________________________________________________
sample 12 ms submission
#include <iostream>
#include <stack>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> sta;
        stack <int> idxToRemove;
        int strlen = s.size();
        //cout << "s.size()=" << s.size() << "s.length=" << s.length() << endl;
        for (int i=0; i<strlen; ++i) {
            if (s[i] == '(') {
                sta.push(i);
                //cout<<"push i=" << i << endl;
            }else if (s[i] == ')') {
                if (!sta.empty()) {
                    sta.pop();
                    //cout << "pop" << endl;
                }else {
                    //remove this closing parens
                    cout << "stack empty, remove this paren i=" << i << endl;
                    s[i] = '*';
                }
            }
            //cout << "i=" << i << "=" << s[i] << endl;
        }
        while (!sta.empty()) {
            cout << "sta not empty, s[" << sta.top() << "] change to *" << endl;
            s[sta.top()] = '*';
            sta.pop();
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
__________________________________________________________________________________________________
