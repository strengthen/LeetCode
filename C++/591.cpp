__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    bool tag(string& s) {
         if (s[0] != '<') {
            return false;
        }

        size_t pos = s.find('>');
        if (pos == string::npos) {
            return false;
        }
        
        //get the tag name and see if it's valid
        string t = s.substr(0, pos + 1);
        if (t.size() < 3 || t.size() > 11) {
            return false;
        }
        
        for (size_t i = 1; i < t.size() - 1; ++i) {
            if (t[i] < 'A' || t[i] > 'Z') {
                return false;
            }
        }
        
        //get the end tag and see if the given staing s ending with it
        string t2 = "</" + t.substr(1, t.size() - 1);
        if (t2.size() >= s.size() || t2 != s.substr(s.size() - t2.size(), t2.size())) {
            return false;
        }
        
        //remove the start/end tags from s
        s = s.substr(t.size(), s.size() - t.size() - t2.size());
        
        return true;
    }
    
    void cdata(string& s) {
        while (true) {
            size_t pos = s.find("<![CDATA[");
            if (pos == string::npos) {
                break;
            }
            
            size_t pos2 = s.find("]]>");
            if (pos2 == string::npos) {
                break;
            }
            
            s = s.substr(0, pos) + s.substr(pos2 + 3, s.size() - pos2 - 3);
        }
    }
    
public:
    bool isValid(string code) {
        string s(code);
        
        //check for closed tag and remove them if it's valide
        if (!tag(s)) {
            return false;
        }

        /*//see if there are other wrapping tags
        while (tag(s)) {}*/

        //remove cdata from string s
        cdata(s);
        
        //remove closed tags from s
        while (s.size() > 0) {
            //find end tage first
            size_t pos = s.find("</");
            if (pos == string::npos) {
                break; //no "</" can be found
            }
            
            size_t pos2 = s.find('>', pos);
            if (pos2 == string::npos) {
                return false; //unmatched '<'
            }
            
            //get the end tag
            string t = s.substr(pos, pos2 - pos + 1);
            
            //get the start tag
            string t2 = "<" + t.substr(2, t.size() - 2);
            
//            cout << t2 << endl;
            
            //find the start tag
            size_t pos3 = s.rfind(t2, pos - 1);
            
            if (pos3 == string::npos || pos3 > pos) {
                return false; //unmatched end tag
            }
  
            //cout << pos3 << " " << s.substr(pos3, pos2 + 1 - pos3) << endl;
            
            //do recursion for this closed tag section
            if (!isValid(s.substr(pos3, pos2 + 1 - pos3))) {
                return false; //not valid closed tag
            }
            
            //remove the closed tags from string s
            s = s.substr(0, pos3) + s.substr(pos2 + 1);
            
            //cout << s << endl;
        }
  
        //cout << s << endl;
        
        //we shouldn't have any char '<' left
        if (s.find('<') != string::npos) {
            return false;
        }
        
        //cout << s << endl;
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isValid(string code) {
    int i = 0;
    return validTag(code, i) && i == code.size();
  }

 private:
  bool validTag(string s, int& i) {
    int j = i;
    string tag = parseTagName(s, j);
    if (tag.empty()) return false;
    if (!validContent(s, j)) return false;
    int k = j + tag.size() + 2;  // expecting j = pos of "</" , k = pos of '>'
    if (k >= s.size() || s.substr(j, k + 1 - j) != "</" + tag + ">")
      return false;
    i = k + 1;
    return true;
  }

  string parseTagName(string s, int& i) {
    if (s[i] != '<') return "";
    int j = s.find('>', i);
    if (j == string::npos || j - 1 - i < 1 || 9 < j - 1 - i) return "";
    string tag = s.substr(i + 1, j - 1 - i);
    for (char ch : tag) {
      if (ch < 'A' || 'Z' < ch) return "";
    }
    i = j + 1;
    return tag;
  }

  bool validContent(string s, int& i) {
    int j = i;
    while (j < s.size()) {
      if (!validText(s, j) && !validCData(s, j) && !validTag(s, j)) break;
    }
    i = j;
    return true;
  }

  bool validText(string s, int& i) {
    int j = i;
    while (i < s.size() && s[i] != '<') {
      i++;
    }
    return i != j;
  }

  bool validCData(string s, int& i) {
    if (s.find("<![CDATA[", i) != i) return false;
    int j = s.find("]]>", i);
    if (j == string::npos) return false;
    i = j + 3;
    return true;
  }
};
__________________________________________________________________________________________________
sample 10240 kb submission
class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        for(int i = 0; i < code.size(); ++i)
        {
            if(i > 0 && st.empty())
            {
                return false;
            }
            if(code.substr(i, 9) == "<![CDATA[")
            {
                int j = i + 9;
                i = code.find("]]>", j);
                if(i < 0)
                    return false;
                i += 2;
            }
            else if(code.substr(i, 2) == "</")
            {
                int j = i + 2;
                i = code.find(">", j);
                if(i < 0)
                {
                    return false;
                }
                string tag = code.substr(j, i - j);
                if(st.empty() || st.top() != tag)
                {
                    return false;
                }
                st.pop();
            }
            else if(code.substr(i, 1) == "<")
            {
                int j = i + 1;
                i = code.find(">", j);
                if(i < 0 || i == j || i - j > 9)
                {
                    return false;
                }
                for(int k = j; k < i; ++k)
                {
                    if(code[k] < 'A' || code[k] > 'Z')
                    {
                        return false;
                    }
                }
                string tag = code.substr(j, i - j);
                st.push(tag);
            }
        }
        return st.empty();
    }
};