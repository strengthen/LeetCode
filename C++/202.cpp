__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1){
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if(st.find(n) != st.end()){
                break;
            }
            st.insert(n);
        }
        return n == 1;
    }
};
__________________________________________________________________________________________________
sample 7876 kb submission
class Solution {
public:
    int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
};
__________________________________________________________________________________________________
