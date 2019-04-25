__________________________________________________________________________________________________
sample 8 ms submission
auto gucciGang = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
class Solution {
    
public:
    
    int lastRemaining(int n) {
        if (n==1) return 1;
        if (n==2 || n==3) return 2;
        if (n%4 == 0 || n%4 == 1) return 4*lastRemaining(n/4) -2;
        else return 4*lastRemaining(n/4);
        
    }
};
__________________________________________________________________________________________________
sample 27124 kb submission
class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return (n / 2 - lastRemaining(n/2) + 1) * 2;
    }
};
__________________________________________________________________________________________________
