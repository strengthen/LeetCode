__________________________________________________________________________________________________
sample 0 ms submission


int reverse(int x){
    long int reverse = 0;
    int sign = 1;
    
    if(x>=INT_MAX || x<=INT_MIN)
        return 0;
    
    if(x < 0)
    {
        sign = -1;
        x *= sign;
    }
    while(x)
    {
        reverse = reverse*10 + (x %10);
        x /=10;
        if(reverse > INT_MAX)
            return 0;
    }
    
    if(sign == -1)
        reverse *= sign;
    
    return reverse;
}
__________________________________________________________________________________________________
sample 4 ms submission


int reverse(int x){
    int out;
    int pop;
    while(x!=0){
        pop = x%10;
        x = x/10;
        if(out > INT_MAX/10 || (out == INT_MAX/10 && pop >7)) return 0;
        if(out < INT_MIN/10 || (out == INT_MIN/10 && pop <-7)) return 0;
        out = out*10+pop;
    }
    return out;
}

__________________________________________________________________________________________________
执行用时为 0 ms 的范例
// #define MAX  pow(2,31)-1
// #define MIN  pow(-2,31)
int reverse(int x){
    int y = 0,pop;
    while(x!=0)
    {
        pop = x%10;
        x = x/10;
        if(y>INT_MAX/10 ||(y==INT_MAX/10 && pop>7))
            return 0;
        if(y<INT_MIN/10 ||(y==INT_MIN/10 && pop<-8))
            return 0; 
        y = y*10+pop;
    }
    return y;
}

__________________________________________________________________________________________________
执行用时为 4 ms 的范例
int reverse(int x)
{
    long res = 0;
    while (x != 0)
    {
        res = 10 * res + x % 10;
        x /= 10;
    }        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
}

__________________________________________________________________________________________________
执行用时为 8 ms 的范例

int reverse(int x)
{
    int y;
    int i;
    long c=0;
    
    for(i=0;i<20;i++)
    {
        y=x%10;
        x=x/10;
        c=y+c*10;
       if( c>0x7fffffff || c<(signed int)0x180000000)
       {
           return 0;
       }
        if(x==0)
            break;
    }

 
        return c;
}

__________________________________________________________________________________________________
