__________________________________________________________________________________________________
sample 4 ms submission
#define ll long long 
 vector<ll> storage={0,1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001,10011001,10100101,10111101,11000011,11011011,11100111,11111111,20000002,100000001,100010001,100020001,100101001,100111001,100121001,101000101,101010101,101020101,101101101,101111101,110000011,110010011,110020011,110101011,110111011,111000111,111010111,111101111,111111111,200000002,200010002};
class Solution {
private:
   
public:
    bool ispalindrome(ll a)
    {
       
        string b=to_string(a);
        string c=b;
        reverse(b.begin(),b.end());
        return b==c;
    }
    int superpalindromesInRange(string L, string R) 
    {
        int ans=0;
        ll x =stoull(L);
        ll y=stoull(R);
    //    cout<<x<<" "<<y<<endl;
        ll xx=sqrt(x);
        ll yy=sqrt(y);
        cout<<xx<<" "<<yy<<endl;
        auto l=lower_bound(storage.begin(), storage.end(),xx);
        auto r=upper_bound(storage.begin(), storage.end(),yy);
     //  cout<<*l<<" "<<*r<<endl; 
       return distance(l,r);
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long double lb = sqrtl(stol(L)), ub = sqrtl(stol(R));
        int ans = lb <= 3 && 3 <= ub;
        queue<pair<long, int>> q;
        q.push({1, 1}), q.push({2, 1});
        while (true) {
            auto p = q.front(); q.pop();
            long x = p.first, len = p.second;
            if (x > ub) break;
            long W = powl(10, (len + 1) / 2);
            if (x >= lb) ans += is_palindrome(x * x);
            long r = x % W, l = x - (len % 2 ? x % (W / 10) : r);
            if (len % 2)
                q.push({10 * l + r, len + 1});
            else
                for (int d = 0; d <= 2; d++)
                    q.push({10 * l + d * W + r, len + 1});
        }
        return ans;
    }
private:
    bool is_palindrome(long x) {
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        long left = x, right = 0;
        while (left >= right) {
            if (left == right || left / 10 == right) return true;
            right = 10 * right + (left % 10), left /= 10;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 8560 kb submission
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long l = calc(L);
        long r = calc(R);
        long l1 = sqrt(l);
        long r1 = sqrt(r);
        long n1 = pro(l1);
        long n2 = pro(r1) + 1;
        int res = 0;
        for(int i = n1; i <= n2; ++i)
        {
            long t = pow(10, (i+1)/2) - 1;
            long t1 = pow(10, (i+1)/2 - 1);
            while(t1 <= t)
            {
                long t2 = t1;
                long t3 = t1;
                if (i % 2)
                    t3 /= 10;
                while(t3)
                {
                    t2 = t2*10 + t3%10;
                    t3 /= 10;
                }
                if (t2 <= r1 && t2*t2 >= l && t2*t2 <= r && check(t2*t2))
                    res++;
                t1++;
            }
        }
        return res;
    }
    
    bool check(long m)
    {
        long n = m;
        long n1 = 0;
        while(m)
        {
            n1 = n1*10 + m%10;
            m /= 10;
        }
        return n1 == n;
    }
    
    long calc(const string &s)
    {
        long res = 0;
        for(int i = 0; i < (int)s.size(); ++i)
        {
            res = res*10 + s[i] - '0';
        }
        return res;
    }
    
    long pro(long m)
    {
        long n = 0;
        while(m)
        {
            n++;
            m/=10;
        }
        return n;
    }
};