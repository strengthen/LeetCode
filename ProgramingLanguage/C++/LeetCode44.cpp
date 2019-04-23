__________________________________________________________________________________________________
8ms
class Solution {

  private:
    inline bool eq(char s, char p) { return p == '?' ? true : s == p; }

  public:  
    bool getMatchOffset(string& s, string& p, int& s0, int p0, int p1) {
        int ssz = s.size(), pz = p.size();

        // Match against '*'
        if (p0 == p1 && p[p0] == '*') {
            s0 = ssz; return true;
        }

        bool skip = p[p0] == '*';
        if (skip) { p0++; }

        int psz = p1 - p0 + 1;

        // Check if this pattern is a suffix
        if (skip && p1 == pz - 1) {
            // Extract source string range that actually needs to be matched
            s0 = max(s0, ssz - psz);
        }

        // Calculate number of test trials we have
        int tries = skip ? max((ssz - s0) - psz + 1, 0) : 1;
        int searchOff = s0, i = 0;

        while (tries-- > 0 && s0 + psz <= ssz) {
            for (i = 0; i < psz; i++) {
                if (searchOff == s0 && eq(s[s0 + i], p[p0])) {
                    searchOff = s0 + i;
                }

                if (!eq(s[s0 + i], p[p0 + i])) {
                    break;
                }
            }
            
            if (i == psz) {
                // We ran out of further tries because we found a valid match
                tries = 0; s0 += i;
            } else {
                // Try next sliding window for a match
                s0 = searchOff == s0 ? s0 + i + 1 : searchOff;
                searchOff = s0;
            }
        }

        return i == psz;
    }
    
    bool isMatch(string s, string p) {
        if (p.size() == 0) { return s.size() == 0; }

        int s0 = 0, p0 = 0, p1 = -1;
        int sz = s.size(), pz = p.size();

        bool lastMatch = false;
        
        do {
            // Calculate next search pattern range
            p0 = p1 = p1 + 1;
            for (p1 = p0 + 1; p1 < pz; p1++) {
                if (p[p1] == '*') {
                    if (p[p1-1] == '*') { p0++; }
                    else { break; }
                }
            }
            p1--;
            
            if (p1 >= pz) { break; }

            lastMatch = getMatchOffset(s, p, s0, p0, p1);
        } while (lastMatch && p1 < pz);

        return lastMatch && p1 >= pz && s0 == sz;
    }
};

auto opt = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}();
__________________________________________________________________________________________________
12ms
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        
        int i =0, j = 0;
        int match = 0, index = -1;
        while(i < n1) {
            if(j < n2 && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            } else if(j < n2 && p[j] == '*') {
                index = j;
                match = i;
                j++;
            } else if(index != -1) {
                j = index+1;
                match++;
                i = match;
            } else 
                return false;
        }
        while(j < n2 && p[j] == '*')
            j++;
        
        return j == n2;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    bool isMatch(string s, string p) {
  int len_s = static_cast<int>(s.length()),
      len_p = static_cast<int>(p.length());
  int i = 0, j = 0, flag = -1, temp_s = 0;

  while (i < len_s) {
    if (j < len_p && (p[j] == '?' || p[j] == s[i])) {
      i++;
      j++;
    } else if (j < len_p && p[j] == '*') {
      flag = ++j;
      temp_s = i;
    } else if (flag != -1) {
      j = flag;
      i = ++temp_s;
    } else {
      return false;
    }
  }

  while (j < len_p && p[j] == '*') j++;

  return j == len_p;
    }
};
__________________________________________________________________________________________________
8780 kb 
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool match(string s ,string p,int a,int b){
        return s[a] == p[b]||p[b] == '?';
    }
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        int ps = 0,pp = 0;
        int star = -1;
        while(ps<lens){
            int match; 
            if(s[ps] == p[pp]||p[pp] == '?'){
                ps++;pp++;
            }else if((pp<lenp)&&p[pp] == '*'){
                star = pp++;
                match = ps;
            }else if(star > -1){
                pp = star+1;
                ps = ++match;
            }else{
                return false;
            }
        }
        while(pp<lenp&&p[pp] == '*'){
            pp++;
        }
        return pp == lenp;
    }
};
__________________________________________________________________________________________________
9920 kb
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool match(string s ,string p,int a,int b){
        return s[a] == p[b]||p[b] == '?';
    }
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        bool dp[lens+1][lenp+1]={false};
        dp[0][0] = true;
        for(int i = 1 ; i <= lens ; i ++){
            dp[i][0] = false;
        }
        for(int i = 1 ; i <= lenp ;i ++){
            dp[0][i] = (p[i-1] == '*')&&(i-1>=0)&&dp[0][i-1];
        }
        
        //bool dp[lenp+1] = {false};
        //dp[0] = true;
        /*for(int i = 1 ; i <= lenp ;i ++){
            dp[i] = (p[i-1] == '*')&&dp[i-1];
        }*/
        for(int i = 1 ; i <= lens ; i ++){
            //bool pre = dp[0];
            for(int j = 1 ; j <= lenp ; j++){
                //bool temp = dp[j];
                //dp[0] = dp[0]&&(p[j-1]=='*');
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                    //dp[j] = dp[j]||dp[j-1];
                }else{
                    dp[i][j] = (s[i-1]==p[j-1]||p[j-1]=='?')&&dp[i-1][j-1];
                    //dp[j] = match(s,p,i-1,j-1)&&pre;
                }
                //pre = temp;
            }
        }
        return dp[lens][lenp];
    }
};
__________________________________________________________________________________________________