__________________________________________________________________________________________________
sample 0 ms submission
int myAtoi(char* str) {
    
char* p = str;
while (*p != '\0' && *p == ' ') ++p;

 int sign = 1;
 if (*p == '-') {
     ++p;
     sign = -1;
 } else if (*p == '+') {
     ++p;
 }
 
 int res = 0;
 while (*p != '\0') {
     if (*p < '0' || *p > '9') break;
     
     int d = *p - '0';
     // check overflow
     if (res > (INT_MAX-d)/10) return sign > 0 ? INT_MAX : INT_MIN;
     
     res = res*10 + d;
     ++p;
 }
 return sign*res;    
 }
__________________________________________________________________________________________________
sample 4 ms submission


int myAtoi(char * str){
    long int number = 0;
    int negative = 0;
    char c;
    if(!str)
        return number;
    while((c=*str++)!= '\0')
    {
        if (c == ' ' && number == 0 && negative == 0)
            continue;
        else if(c == '-' && number == 0 && negative == 0)
        {
            negative=-1;
        }
        else if(c == '+' && number == 0 && negative == 0)
        {
            negative=1;
            continue;
        }
        else if(c >= '0' && c <= '9')
        {
            if(negative == 0)
                negative = 1;
            number = number*10 + (c - '0');
            if(number > INT_MAX && negative == 1)
                return INT_MAX;
            if(number > INT_MAX && negative == -1)
                return INT_MIN;
        }
        else
        {
            break;
        }
    }
    if (number != 0 && negative == -1)
    {
        number *= negative;
    }
    return number;
}

__________________________________________________________________________________________________
sample 6576 kb submission
int myAtoi(char* str) {
    long ans=0;
    bool sign=true; //true is positive
    if(!str) return ans;
    int i = 0;
    while(str[i] == ' '){
        ++i;
    }
    if(str[i] == '+' || str[i] == '-'){
        sign = (str[i] == '+');
        ++i;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        ans*=10;
        ans+= (str[i] - '0');
        if(sign && ans > INT_MAX) return INT_MAX;
        if(!sign && -ans < INT_MIN) return INT_MIN;
        ++i;
    }
    return sign ? (int) ans : (int) -ans;
}
__________________________________________________________________________________________________
sample 6612 kb submission
int myAtoi(char* str) {
  while (*str == ' ') {
    ++str;
  }
  int sgn = 1;
  if (*str == '+') {
    ++str;
  } else if (*str == '-') {
    ++str;
    sgn = -1;
  }
  
  long long int cum = 0;
  bool ok = false;
  while('0'<=*str && *str <='9') {
    cum = 10*cum + sgn*(*str-'0');
    ++str;
    ok = true;
    if (cum > INT_MAX) return INT_MAX;
    if (cum < INT_MIN) return INT_MIN;
  }
  if (!ok) return 0;
  //if (!pos) cum = -cum;
  //if (cum > INT_MAX) return INT_MAX;
  //if (cum < INT_MIN) return INT_MIN;
  return cum;
}
__________________________________________________________________________________________________
sample 6616 kb submission
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>


int myAtoi(const char* s) {
    register unsigned long ret = 0;
    _Bool neg = false;
    if ( __builtin_expect ( (NULL == s), 0 ) )
        return 0;
    while(  __builtin_isspace(*s) )
        ++s;
    if( *s == '-') {
       ++s;
       neg = true;
    } else if(*s == '+')
       ++s;
    while( '\0' != *s && __builtin_expect ( __builtin_isdigit(*s), 1 ) ) {
          ret = (ret * 10) + (*s - '0');
          if ( __builtin_expect ( ( INT_MAX < ret), 0 ) )
             return neg ? INT_MIN : INT_MAX;
          ++s;
    }
    return neg ? - (int)ret : (int)ret;
}
__________________________________________________________________________________________________
sample 6628 kb submission
#include <ctype.h>
#include <limits.h>

int myAtoi(char* str) {
    char *s = str;
    while (*s == ' ') s++;
    
    int sign = 1;
    if (*s == '+') s++;
    else if (*s == '-') {
        s++;
        sign = -1;
    }

    long n = 0;
    while ('0' <= *s && *s <= '9') {
        int oldn = n;
        n = n*10 + *s++ - '0';
        if (n*sign > INT_MAX) return INT_MAX;
        else if (n*sign < INT_MIN) return INT_MIN;
    }
    
    return (int)(n*sign);
    //return n*sign;    //much slower than int(n*sign), why?
}

int myAtoi2(char* str) {
    
    int num  = 0;
    int sign = 1;
    
    while(*str==' ') str++;
    
    if(*str=='-') {
        sign=-1;
        str++;
    }
    else if(*str=='+') {
        str++;
    }
    
    while(*str>='0' && *str<='9') {
        int sum = num*10 + *str-'0';
        if(sum/10!=num)
            if(sign==-1)
                return INT_MIN;
            else
                return INT_MAX;
        num = sum;
        str++;
    }
    
    return num*sign;
}