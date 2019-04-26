__________________________________________________________________________________________________
sample 8 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string originalDigits(string s) {
        int c[256];
        memset(c, 0, sizeof(c));
        for (auto x:s) {
            c[x] ++;
        }
        
        int d[10];
        memset(d, 0, sizeof(d));
        d[0] = c['z'];
        d[6] = c['x'];
        d[8] = c['g'];
        d[4] = c['u'];
        d[3] = c['h'] - d[8];
        d[2] = c['t'] - d[8] - d[3];
        d[1] = c['o'] - d[0] - d[2] - d[4];
        d[5] = c['f'] - d[4];
        d[9] = c['i'] - d[8] - d[6] - d[5];
        d[7] = c['s'] - d[6];
        string ret = "";
        for (int i = 0; i < 10; i++) {
            ret += string (d[i], '0' + i);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 10452 kb submission
#define processDigitCount(c,i) if( c>0 ) { memset( DI, i, c), DI += c; }

class Solution {
public:
    string originalDigits(const string &s) {
        unsigned int letter['a'+26] = {0};
        for( auto c : s)
            ++letter[c];
        
        unsigned char buffer[16668] = "";
        unsigned char *__restrict__ DI = buffer;

        if(letter['z']>0) memset( buffer, '0', letter['z']), DI+=letter['z'];
        letter['o'] -= letter['z'] +letter['w'] +letter['u'];
        processDigitCount( letter['o'], '1');
        processDigitCount( letter['w'], '2');
        letter['h'] -= letter['g'];
        processDigitCount( letter['h'], '3');
        processDigitCount( letter['u'], '4');
        letter['f'] -= letter['u'];
        processDigitCount( letter['f'], '5');
        processDigitCount( letter['x'], '6');
        letter['s'] -= letter['x'];
        processDigitCount( letter['s'], '7');
        processDigitCount( letter['g'], '8');
        letter['i'] -= letter['f'] +letter['x'] +letter['g'];
        processDigitCount( letter['i'], '9');
        *DI = '\0';
        
        return string(buffer, DI);
    }
};
__________________________________________________________________________________________________
