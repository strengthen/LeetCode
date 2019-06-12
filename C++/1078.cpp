__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        size_t pos=text.find(first,0);
        int fl = first.length();
        int sl = second.length();
        int tl = text.length();
        while(pos!=string::npos)
        {
            if(pos == 0 || text[pos-1] == ' ')
            {
                if(pos+fl+sl+2 < tl && text[pos+fl] == ' ')
                {
                    if(text.substr(pos+fl+1, sl) == second && text[pos+fl+1+sl] == ' ')
                    {
                        size_t tp = text.find(' ', pos+fl+sl+2);
                        if(tp == string::npos)
                            res.push_back(text.substr(pos+fl+sl+2, tl-pos-fl-sl-2));
                        else
                            res.push_back(text.substr(pos+fl+sl+2, tp-pos-fl-sl-2));
                    }
                }
            }
            pos = text.find(first, pos+1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
  vector<string> res;
  auto bigram = first + " " + second + " ";
  auto p = text.find(bigram);
  while (p != string::npos) {
    auto p1 = p + bigram.size(), p2 = p1;
    while (p2 < text.size() && text[p2] != ' ') ++p2;
    res.push_back(text.substr(p1, p2 - p1));
    p = text.find(bigram, p + 1);
  }
  return res;
 }
};