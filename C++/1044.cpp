__________________________________________________________________________________________________
sample 64 ms submission
//#include <bits/stdc++.h>
//using namespace std;

#define NDEBUG
#include <cassert>


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<string> vs;
typedef vector<char> vch;
typedef vector<bool> vb;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define clamp(v,lo,hi) min(max(v,lo),hi)

template <typename T>
inline bool found(set<T> &s, T elem) { return s.find(elem) != s.end(); }
template <typename T>
inline bool found(unordered_set<T> &s, T elem) { return s.find(elem) != s.end(); }
template <typename T, typename U>
inline bool found(map<T,U> &s, U elem) { return s.find(elem) != s.end(); }
template <typename T, typename U>
inline bool found(unordered_map<T,U> &s, U elem) { return s.find(elem) != s.end(); }
template <typename T>
inline bool found(vector<T> &s, T elem) { return find(s.begin(), s.end(), elem) != s.end(); }
inline int found(string &s, string t) { return (int)s.find(t); }
inline int found(string &s, int c) { return (int)s.find(c); }

template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }

inline ll square(ll x) { return x * x; }
inline ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
template <typename T>
inline T mod(T a, T b) { return ((a % b) + b) % b; }


unsigned char mask[]={0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) \
                      ?(mask[(i)%8]|t[(i)/8]) \
                      :((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int) \
                      ?((int*)s)[i] \
                      :((unsigned char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))
void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
  int i, sum=0;
  for(i=0; i<=K; i++) bkt[i]=0;
  for(i=0; i<n; i++) bkt[chr(i)]++;
  for(i=0; i<=K; i++)
  { sum+=bkt[i]; bkt[i]=end ? sum : sum-bkt[i]; }
}
void induceSAl(unsigned char *t, int *SA,
               unsigned char *s, int *bkt,
               int n, int K, int cs, bool end) {
  int i, j;
  getBuckets(s, bkt, n, K, cs, end);
  for(i=0; i<n; i++) {
    j=SA[i]-1;
    if(j>=0 && !tget(j)) SA[bkt[chr(j)]++]=j;
  }
}
void induceSAs(unsigned char *t, int *SA,
               unsigned char *s, int *bkt,
               int n, int K, int cs, bool end) {
  int i, j;
  getBuckets(s, bkt, n, K, cs, end);
  for(i=n-1; i>=0; i--) {
      j=SA[i]-1;
      if(j>=0 && tget(j)) SA[--bkt[chr(j)]]=j;
  }
}
void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
  unsigned char t[n/8 + 1];
  int i, j;
  tset(n-2, 0); tset(n-1, 1);
  for(i=n-3; i>=0; i--)
    tset(i, (chr(i)<chr(i+1)
             || (chr(i)==chr(i+1)
             && tget(i+1)==1))?1:0);
  int bkt[K+1];
  getBuckets(s, bkt, n, K, cs, true);
  for(i=0; i<n; i++) SA[i]=-1;
  for(i=1; i<n; i++)
    if(isLMS(i)) SA[--bkt[chr(i)]]=i;
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
  int n1=0;
  for(i=0; i<n; i++)
    if(isLMS(SA[i])) SA[n1++]=SA[i];
  for(i=n1; i<n; i++) SA[i]=-1;
  int name=0, prev=-1;
  for(i=0; i<n1; i++) {
    int pos=SA[i]; bool diff=false;
    for(int d=0; d<n; d++)
      if(prev==-1 || chr(pos+d)!=chr(prev+d)
                  || tget(pos+d)!=tget(prev+d))
      { diff=true; break; }
      else if(d>0 && (isLMS(pos+d) ||
                      isLMS(prev+d)))
        break;
    if(diff) { name++; prev=pos; }
    pos=(pos%2==0)?pos/2:(pos-1)/2;
    SA[n1+pos]=name-1;
  }
  for(i=n-1, j=n-1; i>=n1; i--)
      if(SA[i]>=0) SA[j--]=SA[i];
  assert(n >= n1);
  int *SA1=SA, *s1=SA+n-n1;
  if (name < n1)
    SA_IS((unsigned char*)s1, SA1, n1,
          name-1, sizeof(int));
  else
    for(i=0; i<n1; i++) SA1[s1[i]] = i;
  getBuckets(s, bkt, n, K, cs, true);
  for(i=1, j=0; i<n; i++)
    if(isLMS(i)) s1[j++]=i;
  for(i=0; i<n1; i++) SA1[i]=s1[SA1[i]];
  for(i=n1; i<n; i++) SA[i]=-1;
  for(i=n1-1; i>=0; i--) {
      j=SA[i]; SA[i]=-1;
      SA[--bkt[chr(j)]]=j;
  }
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
}

vector<int> SA_IS(string& s) {
    int L = s.size();
    vector<int> SA(L+1);
    SA_IS((unsigned char*)s.c_str(), &SA[0], L+1, 256, 1);
    return SA;
}


class Solution {
public:
    string longestDupSubstring(string S) {
        int L = S.size();
        const char *s = S.c_str();

        vi sa = SA_IS(S);
        ++L;

        auto lcp = [=](int i, int j) {
            int len = 0;
            while (true) {
                if (i>=L || j>=L || s[i] != s[j]) break;
                ++len; ++i; ++j;
            }
            return len;
        };

        vi rsa(L); rep(i,L) rsa[sa[i]] = i;
#if 0
        vi hgt(L); int h=0;
        rep(i,L){
            if (rsa[i] == L-1) {
                hgt[rsa[i]] = -1;
                h = 0;
            } else {
                int ofs = max(0, h-1);
                hgt[rsa[i]] = h = ofs + lcp(ofs+i, ofs+sa[rsa[i]+1]);
            }
        }
        int ix = (int)(max_element(ALL(hgt)) - hgt.begin());
        int len = hgt[ix];
        assert(len >= 0);
        int at = sa[ix];

        return string(s+sa[at], s+sa[at]+len);
#else
        int h = 0;
        int hmax = -1, hmax_at = -1;
        rep(i,L){
            if (rsa[i] == L-1) {
                h = 0;
            } else {
                int ofs = max(0, h-1);
                h = ofs + lcp(ofs+i, ofs+sa[rsa[i]+1]);
            }
            if (h > hmax) {
                hmax = h;
                hmax_at = rsa[i];
            }
        }
#endif

        return string(s+sa[hmax_at], s+sa[hmax_at]+hmax);
    }
};
__________________________________________________________________________________________________
sample 88 ms submission
const int maxn = 1000005;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[maxn],wb[maxn],wv[maxn],wss[maxn],a[maxn],rankk[maxn],height[maxn],sa[maxn];
int c0(int *r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b)
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
  else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
void sort(int *r,int *a,int *b,int n,int m)
{
  int i;
  for(i=0;i<n;i++) wv[i]=r[a[i]];
  for(i=0;i<m;i++) wss[i]=0;
  for(i=0;i<n;i++) wss[wv[i]]++;
  for(i=1;i<m;i++) wss[i]+=wss[i-1];
  for(i=n-1;i>=0;i--) b[--wss[wv[i]]]=a[i];
  return;
}
void dc3(int *r,int *sa,int n,int m)
{
  int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
  r[n]=r[n+1]=0;
  for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
  sort(r+2,wa,wb,tbc,m);
  sort(r+1,wb,wa,tbc,m);
  sort(r,wa,wb,tbc,m);
  for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
    rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
  if(p<tbc) dc3(rn,san,tbc,p);
  else for(i=0;i<tbc;i++) san[rn[i]]=i;
  for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
  if(n%3==1) wb[ta++]=n-1;
  sort(r,wb,wa,ta,m);
  for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
  for(i=0,j=0,p=0;i<ta && j<tbc;p++)
    sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
  for(;i<ta;p++) sa[p]=wa[i++];
  for(;j<tbc;p++) sa[p]=wb[j++];
  return;
}

void calheight(int *r,int *sa,int n)
{
  int i,j,k=0;
  for(i=1;i<=n;i++)rankk[sa[i]]=i;
  for(i=0;i<n;height[rankk[i++]]=k)
    for(k?k--:0,j=sa[rankk[i]-1];r[i+k]==r[j+k];k++);
}
 char str[maxn];
class Solution {
public:
    string longestDupSubstring(string S) {
       

    for(int i=0;i<S.size();i++)str[i]=S[i];
        str[S.size()]=0;
        int len,i,j,start,last;
    len = S.size();
    for (i=0;i<len;i++)
    {
      a[i] = static_cast<int>(str[i]);
    }
    a[len] = 0;
    dc3(a,sa,len+1,250);
    calheight(a,sa,len);
    start = last = 0;
    for(i=1;i<=len;i++)
    {
      if(last < height[i])
      {
        last = height[i];
        start = sa[i];
      }
    }
    vector<char>ans;
    for(i=start,j=0;j<last;j++,i++)ans.push_back(str[i]);
        string ret = string(ans.size(),'a');
        for(int i=0;i<ans.size();i++)ret[i]=ans[i];
        return ret;
     }
};
__________________________________________________________________________________________________
sample 108 ms submission
struct suffix_array {
    int n = 0;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;

    suffix_array() {}

    template<typename T_string>
    suffix_array(const T_string &str) {
        build(str);
    }

    template<typename T_string>
    void build(const T_string &str) {
        n = str.size();
        suffix.resize(n);

        for (int i = 0; i < n; i++)
            suffix[i] = i;

        bool large_alphabet = false;

        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;

        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);

            for (int i = 0; i < n; i++)
                freq[str[i]]++;

            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];

            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }

        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;

        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;

        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;

        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;

            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;

            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;

                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }

            swap(suffix, values);

            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;

            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];

                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }

            swap(rank, values);
        }

        compute_lcp(str);
    }

    template<typename T_string>
    void compute_lcp(const T_string &str) {
        lcp.assign(n, 0);
        int match = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;

            while (a < n && b < n && str[a++] == str[b++])
                match++;

            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }
};


class Solution {
public:
    string longestDupSubstring(string S) {
        suffix_array SA(S);
        int most_index = max_element(SA.lcp.begin(), SA.lcp.end()) - SA.lcp.begin();
        return S.substr(SA.suffix[most_index], SA.lcp[most_index]);
    }
};