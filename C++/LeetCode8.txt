__________________________________________________________________________________________________
4ms
#include <climits>
#include <cctype>

static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    enum SIGN { EMPTY, ERR, POS, NEG } ;
    int myAtoi(string str) {
        int64_t result = 0 ;
        SIGN numType = EMPTY ;
        
        for ( int i = 0 ; i < str.size() ; ++i ) {
            if ( issign( str.at( i ) ) ) {
                switch ( numType ) {
                    case EMPTY :
                        numType = str.at( i ) == '+' ? POS : NEG ;
                        break ;
                    case POS : case NEG : {
                        return FixResult( result ) ;
                    }   break ;
                } // switch
            } // if
            else if  ( isspace( str.at( i ) ) ) {
                switch ( numType ) {
                    case EMPTY :
                        numType = EMPTY ;
                        break ;
                    case POS : case NEG : {
                        return FixResult( result ) ;
                    }   break ;
                } // switch
            } // else if
            else if ( isdigit( str.at( i ) ) ) {
                int cDigit = str.at( i ) - '0' ;
                switch ( numType ) {
                    case EMPTY :
                        numType = POS ;
                        result = cDigit ;
                        break ;
                    case POS :
                        /*Maybe we can stop here if current result is exceed 32bit limit.*/
                        result = result * 10 ;
                        if ( result < INT_MAX - cDigit )
                            result += cDigit ;
                        else 
                            return INT_MAX ;
                        break ;
                    case NEG :
                        result = result * 10 ;
                        if ( result > INT_MIN + cDigit )
                            result -= cDigit ;
                        else 
                            return INT_MIN ;
                        break ;
                } // switch
            } // else if
            else {
                switch ( numType ) {
                    case EMPTY :
                        numType = ERR ;
                        return 0 ;
                        break ;
                    case POS : case NEG : {
                        if ( result > INT_MAX )
                            return INT_MAX ;
                        else if ( result < INT_MIN )
                            return INT_MIN ;
                        else 
                            return result ;
                    }   break ;
                } // switch
            } // else 
        } // for
        
        return FixResult( result ) ;
    }
    
private :
    bool issign( const char& c ) { return c == '+' || c == '-' ; }
    int FixResult( int64_t result ) {
        // cout << result << " " << INT_MAX << " " << INT_MIN << endl ;
        if ( result > INT_MAX )
            return INT_MAX ;
        else if ( result < INT_MIN ) {
            return INT_MIN ;
        } // else if 
        else 
            return result ;
    } // FixResult()
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        bool neg = false;
        long number = 0;
        while (i < str.length() && str[i] == ' ')
            i++;
        
        if (str[i] == '+' || str[i] == '-') {
            if (str[i++] == '-')
                neg = true;
            if (str[i] >= '0' && str[i] <= '9') {
                while (str[i] >= '0' && str[i] <= '9') {
                    if (number * 10 > 0x7fffffff)
                        if (neg)
                            return 0x80000000;
                        else
                            return 0x7fffffff;
                    number = number * 10 + str[i++] - '0';
                }
            } else
                return 0;
        } else if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                if (number * 10 > 0x7fffffff)
                    if (neg)
                            return 0x80000000;
                        else
                            return 0x7fffffff;
                number = number * 10 + str[i++] - '0';
            }
        } else
            return 0;
        if (neg) {
            if (number > 0x80000000)
                return 0x80000000;
            return -number;
        }
        if (number >= 0x80000000)
            return 0x7fffffff;
        return number;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        long int res = 0;
        bool fir = true;
        bool right = true;
        for(int i = 0; i < str.length(); i++){
            if (fir == true){
                if (str.at(i) == ' ') continue;
                else if (str.at(i) == '-') {right = false; fir = false;}
                else if (str.at(i) == '+') {fir = false;}
                else if (str.at(i) >= '0' && str.at(i) <= '9'){
                    fir = false;
                    res += str.at(i) - '0';
                }else{
                    return res;
                }
            }
            else {
                if (str.at(i) >= '0' && str.at(i) <= '9'){
                    res = res * 10;
                    res += str.at(i) - '0';
                    if (right == true && res > INT_MAX) return INT_MAX;
                    if (right == false && res*(-1) < INT_MIN) return INT_MIN;
                }else{
                    if (res == 0) return res;
                    else break;
                }
            }
        }
        if (right == true && res > INT_MAX) return INT_MAX;
        if (right == false && res*(-1) < INT_MIN) return INT_MIN;
        if (right == false) res *= -1;
        return res;
    }
};
__________________________________________________________________________________________________
8460 kb
class Solution {
public:
    int myAtoi(string str) {
         #define endl '\n'
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
        
        int i = 0, sign = 1;
        long num = 0;
        
        while (isspace(str[i]))
            i++;
        
        if (str[i] == '-' || str[i] == '+')
            if (str[i++] == '-')
                sign *= -1;
        
        while (str[i] == '0')
            i++;
        while (isdigit(str[i])) {
            num = 10 * num + str[i++] - '0';
            if(num > fabs(long(INT_MIN))) 
                break;
        }
        
        num *= sign;
        if(num < INT_MIN) return INT_MIN;
        if(num > INT_MAX) return INT_MAX;
        return num;     
    
    }
};
__________________________________________________________________________________________________
8572 kb
#define endl '\n'
class Solution {
public:
    int myAtoi(string str) {
         
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
        
        int out = 0;
        stringstream ss(str);
        ss >> out;
        return out;
    }
};
__________________________________________________________________________________________________
