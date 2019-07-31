__________________________________________________________________________________________________
sample 0 ms submission


char * longestCommonPrefix(char ** strs, int strsSize){
    char *commonprefix;
    if(strsSize == 0) 
    {
        commonprefix = "";
        return commonprefix;
    }
    else 
        commonprefix= strs[0];
    int j = 0;
    for(j = 0; j < strlen(commonprefix); j++)
    {
        for(int i = 1; i < strsSize; i++)
            if(commonprefix[j] != strs[i][j])
                goto EXIT;
    }
    EXIT:if(j == 0) {
        commonprefix = "";
        return commonprefix;
    }
    char *p = (char*)malloc(sizeof(char)*(j+1));
    for(int i = 0; i < j; i++)
        p[i] = commonprefix[i];
    p[j] = '\0';
    return p;
}

__________________________________________________________________________________________________
sample 4 ms submission

char* getCommonPrefix(char *str1, char * str2, int s) {
    int i;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len;
    if(len1 < len2)
        len = len1;
    else
        len = len2;
    char *prefix;
    prefix = malloc(len + 1);
    for(i = 0; i < len; i ++) {
        if(str1[i] != str2[i])
            break;
        prefix[i] = str1[i];       
    }
    prefix [i] = '\0';
    if(s != 1)
        free(str1);
    return prefix;

}

char * longestCommonPrefix(char ** strs, int strsSize){
    int i;
    if(strsSize == 0)
        return "";
    if(strsSize == 1)
        return strs[0];
    
    char * prefix = strs[0];
    for(i = 1; i <strsSize; i ++) {
        prefix = getCommonPrefix(prefix, strs[i], i);                     
    }
    
    
    return prefix;     

}

__________________________________________________________________________________________________
sample 6788 kb submission
char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix = "";
    if (NULL == strs || strsSize <= 0)
    {
        return prefix;
    }
    
    int i = 0;
    prefix = strs[0];
    for (i = 1; i < strsSize; i++)
    {
        int j = 0;
        while (strs[i][j] != '\0' && prefix[j] != '\0' && strs[i][j] == prefix[j])
        {
            j++;
        }
        prefix[j] = '\0';
    }
    
    return prefix;
}
__________________________________________________________________________________________________
sample 6832 kb submission
int max (int x, int y)
{
    return (x > y) ? x : y;
}

int min (int x, int y)
{
    return (x < y) ? x : y;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    
    int prefix = 0;
    bool mismatch = false;
    
    while ((mismatch == false) && (strsSize > 0))
    {
        for (int i = 0 ; i < strsSize; i++)
        {
            if (strs[i][prefix] == NULL)
            {
                mismatch = true;
                break;
            }
            
            if (strs[min(strsSize-1, i+1)][prefix] == NULL)
            {
                mismatch = true;
                break;
            }
            
            if (strs[i][prefix] != strs[min(strsSize-1, i+1)][prefix])
            {
                mismatch = true;
                break;
            }
        }
        
        if (mismatch == false) prefix++;
    }
    
    char *s = malloc(prefix+1);
    
    for (int i = 0 ; i < prefix; i++)
    {
        s[i] = strs[0][i];
    }
    
    s[prefix] = '\0';
    
    return s;
}
__________________________________________________________________________________________________
执行用时为 0 ms 的范例
/*
 * [14] 最长公共前缀
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */


char * longestCommonPrefix(char ** strs, int strsSize){
        //特殊情况
        if(strsSize==0)return "";

        char* subs=strs[0];
        short i;
        for (i = 1; i < strsSize; i++)
        {
                short j = 0;
                while (subs[j] && strs[i][j] && subs[j] == strs[i][j])
                        j++;

                subs[j]=0;
    }
    return subs;
}
__________________________________________________________________________________________________
执行用时为 4 ms 的范例


char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0)
        return "";
    if(strsSize == 1)
        return strs[0];
    int i=0,j=0;
    while(1)
    {
        if(strs[i][j] == '\0')
            break;
        if(strs[i][j] == strs[++i][j])
        {
            if(i == strsSize-1)
            {
                j++;
                i=0;
            }
        }
        else
            break;
    }
    char *res = (char *)malloc(j+1);
    res = memset(res,0,j+1) ;
    res = strncpy(res,strs[0],j);
    return res;
                                                        
}