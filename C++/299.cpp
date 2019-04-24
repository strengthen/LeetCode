__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size())
            return "0A0B";
        
        int a = 0;
        int b = 0;
        vector<pair<int, int>> v(10, {0, 0});
        for (int i = 0; i < guess.size(); i++)
        {
            if (secret[i] == guess[i])
                a++;
            else
            {
                v[guess[i] - '0'].first++;
                v[secret[i] - '0'].second++;
            }
        }
        
        for (pair<int, int> c : v)
        {
            b += min(c.first, c.second);
        }
        
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
__________________________________________________________________________________________________
sample 8492 kb submission
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> f(10, 0);
        vector<int> g(10, 0);
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
                bulls++;
            else
            {
                f[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++)
            cows += min(f[i], g[i]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
__________________________________________________________________________________________________
