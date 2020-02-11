__________________________________________________________________________________________________
sample 0 ms submission


bool isPalindrome(int x){
    if(x < 0 || (x % 10 == 0 && x != 0))return false;
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber/10; 
}

__________________________________________________________________________________________________
sample 4 ms submission


bool isPalindrome(int x){
    
    int input = x;
    bool sign = ((x > 0) ? true : false);
    int output = false;
    
    if (sign == true)
    {
        double reverse = 0;
        
        while(x != 0)
        {
            reverse = reverse * 10 + (x % 10);
            x = x / 10;
        }
        
        if (reverse == input)
        {
            output = true;
        }
    }
    else if (input == 0)
    {
        output = true;
    }
    else
    {
        // do nothing
    }
    
    return output;

}

__________________________________________________________________________________________________
sample 6916 kb submission
bool isPalindrome(int x) {
    int num,j,sum,i,t,temp;
    num = 0;
    sum = 0;
    t=x;
    j=x;
    if(x<0 || x > INT_MAX)
        return 0;
    if(x==0)
        return 1;
    while(j)
    {
        sum++;
        j/=10;
    }
    for(i=0;i<sum;i++)
    {
        temp = x % 10;
        if(num > INT_MAX/10) return 0;
        num = num * 10 + temp;
        
        x/=10;
    }
    if(t==num)
        return 1;
    else
        return 0;
}
__________________________________________________________________________________________________
执行用时为 0 ms 的范例

int numlen(int x);
bool isPalindrome(int x){
    if(x<0) return 0;
    int i=-1,j=0;
    int len=numlen(x);
    int arr[99];
    //int* arr=(int*)malloc(sizeof(int)*(len));//？？为什么不行
    //address杀菌剂:pc地址0x0000004017fa bp 0x7ffe9eba9f20 sp 0x7ffe9eba9f18上的堆缓冲区溢出
    while(x)
    {
        arr[++i]=x%10;
        x/=10;
    }
    while(j<i)
    {
        if(arr[j]==arr[i])
        {
            j++;
            i--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int numlen(int x){
    int len=0;
    while(x)
    {
        len++;
        x/=10;
    }
    return len;
}

__________________________________________________________________________________________________
执行用时为 4 ms 的范例


bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    
    int xTmp = x;
    int pop;
    int reverse = 0;
    while (xTmp != 0) {
        pop = xTmp %10;
        xTmp /=10;
        if (reverse > INT_MAX/10 || (reverse == INT_MAX/10 && pop > 7)) {
            return false;
        }
        reverse = reverse * 10 + pop;
    }

    if (reverse == x) {
        return true;
    }
    
    return false;
}

__________________________________________________________________________________________________
执行用时为 8 ms 的范例


bool isPalindrome(long x){
    long t,y = 0;
    t = x;
    if(x<0)
        return false;
    while(t)
    {
        y = y*10+t%10;
        t = t/10;
    }
    if(y == x)
        return true;
    else
        return false;
}
