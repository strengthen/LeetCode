__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        stack<int> len;
        stack<string> tapes;
        string t = "";
        int k = 0;
        --K;
        for (char c: S) {
            if (isalpha(c)) {
                if (++k == K + 1)
                    return string(1, c);
                t.push_back(c);
            }
            if (isdigit(c)) {
                int n = c - '0';
                if (!t.empty()){
                    tapes.push(t);
                    t.clear();
                    len.push(k);
                    cout << k << endl;
                }
                if (K / k  < n) {
                    K %= len.top();
                    while (K < (len.top() - tapes.top().size())) {
                        len.pop();
                        tapes.pop();
                        K %= len.top();
                    }
                    cout << K - (len.top() - tapes.top().size()) << endl;
                    cout << tapes.top() << endl;
                    return string(1, tapes.top()[K - (len.top() - tapes.top().size())]);
                } else {
                    k *= n;
                }
            }
        }
        return "";
    }
};
__________________________________________________________________________________________________
sample 8432 kb submission
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        // let string growing to the length greater than or equal to K
        long N = 0, i;
        for(i = 0; i < S.size(); i++){
            if(isdigit(S[i])){
                N *= (S[i]-'0');
            }
            else{
                N++;
            }
            if(N >= K) break;
        }
        // now back track to the digit
        while(i >= 0){
            // if current is digit, then current length N comes from a length N/(S[i]-'0')'s string repeat by S[i]-'0' times
            // we find that substring's length first: N /= (S[i]-'0')
            // K becomes K%N, note that here N is the new length
            if(isdigit(S[i])){
                N /= (S[i]-'0');
                K %= N;
            }
            else{
                // if current is alphabet
                // we know that the last char of the string must not from duplicate
                // we know we find the desired letter when K%N == 0
                // in this case either K == N, which means the length is exactly what we want
                // or K == 0, which must come from K%=N, this also means current length is exactly what we want
                // in both of the cases, we know that the last char is what we want, which is S[i]
                if(K%N == 0) break;
                N--;
            }
            i--;
        }
        return string(1, S[i]);
    }
};
__________________________________________________________________________________________________
