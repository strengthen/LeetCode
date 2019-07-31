__________________________________________________________________________________________________
sample 0 ms submission
/*
 * Special cases
 * "" - differenciate "" from NULL
 * "ccc"
 * "arra"
 * "aaabaaaa"
 */

char*
longestPalindrome(char * s)
{
    char left       = '\0';
    char right      = '\0';
    char curr       = *s;
    int  curr_idx   = 0;
    int  curr_len   = 1;
    int  max_offset = 0;
    int  max_len    = 1;
    int  repeat     = 1;
    int  shift      = 1;
    int  step       = 1;
    bool next_odd   = true;
    bool jumped     = false;
    
    if (*s == '\0') {
        return s;
    }
    
    while (curr != '\0') {
        if (repeat == 1) {
            while (*(s + curr_idx + repeat) == curr) {
                repeat++;
            }
        }

        
        if (next_odd) {
            /* find palindromic substring with odd number of characters */
            curr_len = 1;
            while (shift <= curr_idx) {
                //printf("  shift: %d\n", shift);
                
                right = *(s + curr_idx + shift);
                if (right == '\0') {
                    break;
                }
            
                left = *(s + curr_idx - shift);      
                if (left != right) {
                    break;
                }
                
                shift++;
            }

            curr_len = 2 * (shift - 1) + 1;
            if (curr_len > max_len) {
                max_len = curr_len;
                max_offset = curr_idx - max_len / 2;
            }
            
        } else {
            /* find palindromic substring with even number of characters */
            while (shift < curr_idx) {
                //printf("  shift: %d\n", shift);
                right = *(s + curr_idx + shift);
                if (right == '\0') {
                    break;
                }
            
                left = *(s + curr_idx - 1 - shift);
                if (left != right) {
                    break;
                }
                
                shift++;
            }
        
            curr_len = 2 * (shift - 1) + 2;
            if (curr_len > max_len) {
                max_len = curr_len;
                max_offset = curr_idx - max_len / 2;
            }
        }

        if (repeat % 2 == 0 && !jumped) {
            next_odd = false;
        } else {
            next_odd = true;
        }

        if (repeat > 1) {
            if (jumped) {
                step = repeat;
                shift = 1;
                repeat = 1;
                jumped = false;
            } else {
                step = repeat / 2;
                shift = next_odd ? step + 1 : step;
                repeat = repeat - step;
                jumped = true;
            }
        } else {
            shift = 1;
            step = 1;
            repeat = 1;
            jumped = false;
        }

        curr_idx += step;
        curr = *(s + curr_idx);
    }
    
    *(s + max_offset + max_len) = '\0';
    return s + max_offset;
}
__________________________________________________________________________________________________
sample 4 ms submission
int manacher(char *s, char *substr)
{
  int len = strlen(s);
  /*init array */
  char *newS = malloc((len + 1) * 2 * sizeof(char));
  int *radius = calloc((len * 2 + 1), sizeof(int));
  int i, j;
  for (i = 0; s[i]; i++)
  {
    newS[2 * i + 1] = s[i];
    newS[2 * i] = '#';
  }
  newS[len * 2] = '#';
  newS[len * 2 + 1] = 0;

  int border = 0, curCenter = 0, maxCenter = 0, maxRadius = 0;
  for (i = 1; i < 2 * len + 1; i++)
  {
    if (i < border)
      radius[i] = radius[2 * curCenter - i] < (border - i) ? radius[2 * curCenter - i] : (border - i);

    while (i + radius[i] + 1 < 2 * len + 1 && i - radius[i] - 1 >= 0 && newS[i + radius[i] + 1] == newS[i - radius[i] - 1])
      ++radius[i];

    if (i + radius[i] > border)
    {
      border = i + radius[i];
      curCenter = i;
    }

    if (maxRadius < radius[i])
    {
      maxRadius = radius[i];
      maxCenter = i;
    }
  }

  for (j = 0, i = maxCenter - maxRadius; i <= maxCenter + maxRadius; i++)
  {
    if (newS[i] != '#')
      substr[j++] = newS[i];
  }

  free(newS);
  free(radius);

  return j;
}

char *longestPalindrome(char *s)
{
  if (s == NULL || strlen(s) == 0 || strlen(s) == 1)
    return s;
  char *substr = (char *)malloc(1000 * sizeof(char));
  int len = manacher(s, substr);
  substr = (char *)realloc(substr, (len + 1) * sizeof(char));
  substr[len] = 0;
  return substr;
}
__________________________________________________________________________________________________
sample 12 ms submission


char * longestPalindrome(char * s){
    int i,d,l,r,maxlen=1,len,curlen,start=0;
    if(!s || s[0]=='\0') return s;
    len=strlen(s);
    
    for(i=0;i<len && len-i>maxlen/2;i++)
    {
        l=i;r=i;
        while(r+1<len && s[r+1]==s[l]) r++;
        for(; l>=0 && r<len && s[l] == s[r]; l--,r++)
        {
            // printf("...%i %i\n",l,r);
            curlen = r-l+1;
            if(curlen>maxlen) { maxlen=curlen; start=l; }
        }
    }
    s[start+maxlen] = '\0';
    return s+start;
}

__________________________________________________________________________________________________
执行用时为 0 ms 的范例
#define MAX( a, b ) ((a) > (b) ? (a) : (b))
#define MIN( a, b ) ((a) < (b) ? (a) : (b))
#define LEN( a ) (sizeof(a) / sizeof(*a))

typedef struct Region {
    int left;
    int right;
} Region;

static void change( const char *from, char *to, char ch ) {
    int i = 0, t = 0;

    to[t++] = ch;
    for( i = 0; from[i] != '\0'; ++i ) {
        to[t++] = from[i];
        to[t++] = ch;
    }
    to[t] = '\0';
}

static Region manacher( const char *s ) {
    int len = 0, i = 0, max = INT_MIN, *r = NULL;
    char *c = NULL;
    int middle = -1, right = -1, m = -1;
    Region result = {-1, -1};

    len = strlen( s ) * 2 + 1;
    r = (int *)malloc( sizeof(int) * len );
    c = (char *)malloc( sizeof(char) * (len + 1) );
    change( s, c, '#' );
    for( i = 0; c[i] != '\0'; ++i ) {
        r[i] = right > i ? MIN( r[middle * 2 - i], right - i ) : 1;
        while( i - r[i] > -1 && i + r[i] < len ) {
            if( c[i - r[i]] == c[i + r[i]] ) {
                ++r[i];
            } else {
                break;
            }
        }
        if( i + r[i] > right ) {
            right = i + r[i];
            middle = i;
        }
        if( r[i] > max ) {
            m = i;
        }
        max = MAX( max, r[i] );
    }
    free( r );
    free( c );
    max = max - 1;       //最后匹配了一对'#'.
	result.left = (m - max + 1) / 2;
	result.right = (m + max - 1) / 2;

    return result;
}

char *longestPalindrome( char *s ) {
    Region region = {-1, -1};
    char *result = NULL;
    int r = 0;
 
    if( s == NULL || strlen( s ) <= 1 ) {
        return s;
    }
    region = manacher( s );
    result = (char *)malloc( sizeof(char) * (region.right - region.left + 2) );
	while( region.left <= region.right ) {
		result[r++] = s[region.left++];
	}
	result[r] = '\0';

    return result;
}
__________________________________________________________________________________________________
执行用时为 4 ms 的范例


int findsss(char * str_first, int *maxs, int n);
int getLengthsss(const char * str);

char * longestPalindrome(char * s)
{
    int max, index;
    index = findsss(s, &max, getLengthsss(s));
    
     char *str = (char*)malloc(max + 10);
    if(str == 0) return 0;
    
    for(int i =0; i < max; i++)
    {
        str[i] = s[index + i];
    }
    str[ max] = 0;
     return str;
    
/*  
s[index + max] = 0;
    return &s[index];
    */
}



int rightAndLeftnum(const char *lstr , const char* rstr, const char* minp, const char* maxp)
{
    do
	{
		if((lstr < minp) || (rstr > maxp)) break;
		if(*lstr != *rstr)  break;
		lstr--;
		rstr++;
	}while(1);
	return (rstr  - lstr - 1);
}

int findsss(char * str_first, int *maxs, int n)
{
//	int  n = getLengthsss(str_first);
  char *minstr= str_first;
    char* maxstr =  &str_first[n - 1];
    char* str = str_first;
    int  maxnum = 1;
	char *dstr = str;
	int i ;
if (n < 3)
    {
		 if(n == 0)
		 {
            *maxs = 0;
            return 0;
		 }
		 if(n == 1)
		 {
            *maxs = 1;
            return 0;
		 }
       if(*str == *(str + 1))
        {
            *maxs = 2;
            return 0;
        }
        else
        {
            *maxs = 1;
            return 0;
        }
    }
    if(*str != *(str + 1))str++;
    for(; str  <=  maxstr; )
	{
        
		if(*str == *(str+1))
		{
			i  = 2;
            n = 0;
			do
			{
				if (*str != str[i]) break;
				i++;
			}while(1);
			n = rightAndLeftnum(str -1, str + i,minstr, maxstr) + n;
			if(n > maxnum)
			{
				maxnum = n;
				dstr =  str + i/2 - n/2;
			}
			str = str + i;
		}
		else
		{
			if(*(str-1) == *(str+1))
			{
				n = rightAndLeftnum(str -1, str + 1,minstr, maxstr);
				if(n > maxnum)
				{
					maxnum = n;
					dstr =  str  - n/2;
				}
			}
			str++;
		}
	}
    *maxs = maxnum;
//	printf("maxnum:%d\n", maxnum);
//	printf("index:%d\n", dstr - str_first);
	return dstr - str_first;
}

int getLengthsss(const char * str)
{
    int length = 0;
    while(1)
    {
        if(str[length] == 0)break;
        length++;
    }
//	printf("length:%d\n", length);
    return length;
}
 
__________________________________________________________________________________________________
执行用时为 8 ms 的范例
char * longestPalindrome(char * s){
    int len = 0;
    while(*(s+len)) len++;
    if(len < 2)
    {
        char *p;
        if(len == 1)
        {
            p = (char *)malloc(2);
            *p = *s;
            *(p+1) = '\0';
        }
        else
        {
            p = (char *) malloc(1);
            *p = '\0';
        }
        return p;
    }
    int alen = 2*len+2;
    char str[alen];
    int i,j = 1;
    for(i = 0; i < len+1; i ++)
    {
        str[2*i] = '#';
        if(i== len)
            str[2*i+1] = '\0';
        else
            str[2*i+1] = *(s+i);
    }

    int start = len;
    int t = start;
    while(*(str+t+j) && (t-j)>=0 && *(str+t+j)==*(str+t-j)) j++; j--;
    int rlen = j;

    for (i = 1; i < len; i ++)
    {
        t = len+i;
        if(t+rlen >= alen ) break;
        j = 1;
        while(*(str+t+j) && (t-j)>=0 && *(str+t+j)==*(str+t-j)) j++; j--;
        if(j>rlen)
        {
            start = t;
            rlen = j;
        }
        t = len-i;
        if(t-rlen<0)
            break;
        j = 1;
        while(*(str+t+j) && (t-j)>=0 && *(str+t+j)==*(str+t-j)) j++; j--;
        if(j>rlen)
        {
            start = t;
            rlen = j;
        }
    }
    
    j = 0;
    for(i = start-rlen; i <= rlen+start; i++)
        if(*(str+i) != '#')
            j++;
    char *ret = (char*)malloc(j+1);
    char *p = ret;
    for(i = start-rlen; i <= rlen+start; i++)
        if(*(str+i) != '#')
            *p++ = *(str+i);
    *p = '\0';

    return ret;
}
