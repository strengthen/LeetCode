__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int nthUglyNumber(int n) {
        
    static vector<int> v(1,1);
        
    static int t=0,th=0,f=0;
        
    if(v.size() > n)
        return v[n-1];
        
    while(v.size() < n)
    {
        v.push_back(min(v[t] * 2, min(v[th] * 3, v[f] * 5)));
        if (v.back() == v[t] * 2) ++t;
        if (v.back() == v[th] * 3) ++th;
        if (v.back() == v[f] * 5) ++f;
    }
    return v.back();
        
    }
};
__________________________________________________________________________________________________
sample 8040 kb submission
class Solution {
public:
    int nthUglyNumber(int n) {
        
        int i2=0,i3=0,i5=0;
        int ugly[n];
        ugly[0]=1;
        int u2=2;
        int u3=3;
        int u5=5;
        int i,next_ugly=1;
        for( i=1;i<n;i++)
        {            
            next_ugly=min(u2,min(u3,u5));
            ugly[i]=next_ugly;
            
            if(ugly[i]==u2)
            {       
                i2++;
                u2=ugly[i2]*2;
            }
            if(ugly[i]==u3)
            {
                i3++;
                u3=ugly[i3]*3;
            }
            if(ugly[i]==u5)
            {
                i5++;
                u5=ugly[i5]*5;
            }            
        }        
        return next_ugly;        
    }
};
__________________________________________________________________________________________________
