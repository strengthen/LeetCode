__________________________________________________________________________________________________
sample 0 ms submission


char * intToRoman(int n){
    int i=0,j=0;
char *temp[4][10]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                   {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                   {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                   {"","M","MM","MMM","MMMM"}};
char*res=(char*)calloc(100,sizeof(char));
char *ret=temp[3][n/1000];
    
    while(*ret!='\0')
    {
res[i++]=*ret;
        ret++;
    }

 ret=temp[2][(n/100)%10];
    
    while(*ret!='\0')
    {
res[i++]=*ret;
        ret++;
    }
    ret=temp[1][n/10%10];
    
    while(*ret!='\0')
    {
res[i++]=*ret;
        ret++;
    }
    ret=temp[0][n%10];
    
    while(*ret!='\0')
    {
res[i++]=*ret;
        ret++;
    }              
    res[i]='\0';
return res; 
}
__________________________________________________________________________________________________
sample 4 ms submission
/* Test shows that 0 & negatives should give empty string */

#define N_CASES 13
static const int  n[N_CASES] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; /* Bases */
static const char c[N_CASES] = "MMDDCCLLXXVVI"; /* Main characters */
static const char m[N_CASES] = "0C0C0X0X0I0I0"; /* Modifiers */

char* intToRoman(int num) {
    char* r = (char*)malloc(20); /* Longest: MMMDCCCLXXXVIII */
    size_t i = 0;
    size_t nc = 0;
    
    while (num > 0) {
        //printf("N %d I %zu C %zu\n", num, i, nc);
        while (num < n[nc]) {
            //printf("C %zu\n", nc);
            nc ++;
        }
        
        num -= n[nc];
        //printf("N %d\n", num);
        if (m[nc] != '0') {
            r[i] = m[nc],
            //printf("PAD %c\n", m[nc]);
            i ++;
            //printf("I %zu\n", i);
        }
        r[i] = c[nc],
        //printf("PAD %c\n", c[nc]);
        i ++;
        //printf("I %zu\n", i);
    }
    
    r[i] = '\0';
    return r;
}

__________________________________________________________________________________________________
sample 8 ms submission
typedef struct dataInfo
{
    int val;
    char sym;
}DATA;

char * intToRoman(int num)
{
    DATA d[7] = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    
    char *ret = calloc(30, sizeof(char));
    int ctr = 0;
    for (int x = 6; x >= 0; x--)
    {
        int tmp = num/d[x].val;
        num %= d[x].val;
        
        if (x > 0 && tmp == 1 && (num/d[x-1].val == 4)) // 9 case
        {
            ret[ctr] = d[x-1].sym;
            ret[ctr+1] = d[x+1].sym;
            ctr += 2;
            num %= d[x-1].val;
            continue;
        }
        if (tmp == 4) // 4 case
        {
            ret[ctr] = d[x].sym;
            ret[ctr+1] = d[x+1].sym;
            ctr += 2;
            num %= d[x].val;
            continue;
        }
        while (tmp > 0)
        {
            ret[ctr] = d[x].sym;
            ctr++;
            tmp--;
        }
    }
    return ret;
}

__________________________________________________________________________________________________
sample 6832 kb submission

#define MAX_LEN 15

char* intToRoman(int num) {
    char *result = malloc(sizeof(char) * MAX_LEN + 1);
    size_t res_idx = 0;
    
    while (num > 0) {
        if (num >= 1000) {
            result[res_idx++] = 'M';
            num -= 1000;
        }
        else if (num >= 900) {
            result[res_idx++] = 'C';
            result[res_idx++] = 'M';
            num -= 900; 
        }
        else if (num >= 500) {
            result[res_idx++] = 'D';
            num -= 500;
        }
        else if (num >= 400) {
            result[res_idx++] = 'C';
            result[res_idx++] = 'D';
            num -= 400;
        }
        else if (num >= 100) {
            result[res_idx++] = 'C';
            num -= 100;
        }
        else if (num >= 90) {
            result[res_idx++] = 'X';
            result[res_idx++] = 'C';
            num -= 90;
        }
        else if (num >= 50) {
            result[res_idx++] = 'L';
            num -= 50;
        }
        else if (num >= 40) {
            result[res_idx++] = 'X';
            result[res_idx++] = 'L';
            num -= 40;
        }
        else if (num >= 10) {
            result[res_idx++] = 'X';
            num -= 10;
        }
        else if (num >= 9) {
            result[res_idx++] = 'I';
            result[res_idx++] = 'X';
            num -= 9;
        }
        else if (num >= 5) {
            result[res_idx++] = 'V';
            num -= 5;
        }
        else if (num == 4) {
            result[res_idx++] = 'I';
            result[res_idx++] = 'V';
            num -= 4;
        }
        else {
            result[res_idx++] = 'I';
            num--;
        }
    }
    
    result[res_idx] = '\0';
    
    return result;
}
__________________________________________________________________________________________________
sample 6912 kb submission
char* intToRoman(int num) {
    int p=0;
    char *out;
    out=(char *)malloc(16*sizeof(char));
    while(num>999){
        num-=1000;
        out[p]='M';
        ++p;
    }
    if(num>899){
        num-=900;
        out[p]='C';
        ++p;
        out[p]='M';
        ++p;
    }
    if(num>499){
        num-=500;
        out[p]='D';
        ++p;
    }
    if(num>399){
        num-=400;
        out[p]='C';
        ++p;
        out[p]='D';
        ++p;
    }
    while(num>99){
        num-=100;
        out[p]='C';
        ++p;
    }
    if(num>89){
        num-=90;
        out[p]='X';
        ++p;
        out[p]='C';
        ++p;
    }
    if(num>49){
        num-=50;
        out[p]='L';
        ++p;
    }
    if(num>39){
        num-=40;
        out[p]='X';
        ++p;
        out[p]='L';
        ++p;
    }
    while(num>9){
        num-=10;
        out[p]='X';
        ++p;
    }
    if(num>8){
        num-=9;
        out[p]='I';
        ++p;
        out[p]='X';
        ++p;
    }
    if(num>4){
        num-=5;
        out[p]='V';
        ++p;
    }
    if(num>3){
        num-=4;
        out[p]='I';
        ++p;
        out[p]='V';
        ++p;
    }
    while(num){
        num--;
        out[p]='I';
        ++p;
    }
    out[p]='\0';
    return out;
}
__________________________________________________________________________________________________
sample 6924 kb submission
char* intToRoman(int num)
{
    char *output;
    char s[1024];
    int digital = 1000;
    int i;
    int len;

    memset(s, 0, sizeof(s));
    i = 0;

    while (num)
    {
        if (num >= 1000)
        {
            s[i] = 'M';
            i++;
            num = num - 1000;
            continue;
        }

        if (num >= 900)
        {
            s[i] = 'C';
            i++;
            s[i] = 'M';
            i++;
            num = num - 900;
            continue;
        }

        if (num >= 500)
        {
            s[i] = 'D';
            i++;
            num = num - 500;
            continue;
        }

        if (num >= 400)
        {
            s[i] = 'C';
            i++;
            s[i] = 'D';
            i++;
            num = num - 400;
            continue;
        }

        if (num >= 100)
        {
            s[i] = 'C';
            i++;
            num = num - 100;
            continue;
        }

        if (num >= 90)
        {
            s[i] = 'X';
            i++;
            s[i] = 'C';
            i++;
            num = num - 90;
            continue;
        }

        if (num >= 50)
        {
            s[i] = 'L';
            i++;
            num = num - 50;
            continue;
        }

        if (num >= 40)
        {
            s[i] = 'X';
            i++;
            s[i] = 'L';
            i++;
            num = num - 40;
            continue;
        }

        if (num >= 10)
        {
            s[i] = 'X';
            i++;
            num = num - 10;
            continue;
        }

        if (num >= 9)
        {
            s[i] = 'I';
            i++;
            s[i] = 'X';
            i++;
            num = num - 9;
            continue;
        }

        if (num >= 5)
        {
            s[i] = 'V';
            i++;
            num = num - 5;
            continue;
        }

        if (num >= 4)
        {
            s[i] = 'I';
            i++;
            s[i] = 'V';
            i++;
            num = num - 4;
            continue;
        }

        if (num >= 1)
        {
            s[i] = 'I';
            i++;
            num = num - 1;
            continue;
        }

    }

    len = strlen(s) + 1;
    output = (char *)malloc(len);
    memset(output, 0, len);
    memcpy(output, s, len - 1);


    return output;
}