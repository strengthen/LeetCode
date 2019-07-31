__________________________________________________________________________________________________
sample 0 ms submission

//diff = rows + rows - 2
//row - 1,0  = row - 1
//row - 2, 1  = row - 1
//row - 3, 2
char * convert(char * s, int numRows){
    if(NULL == s){
        return NULL;
    }
    if(numRows <= 1){
        return s;
    }
    
    int size = strlen(s);
    char *ret = malloc(sizeof(char) * (strlen(s) + 1));
    memset(ret, 0x00, sizeof(char) * (strlen(s) + 1));
    int idx = 0;
    int i = 0, j = 0;
    int circle = 2 * numRows - 2;
    for(i = 0; i < numRows; i++){
        j = i;
        while(j < size){
            ret[idx++] = s[j];
            
            j = j + circle;
            if(i != 0 && i != numRows - 1){
                j = j - i * 2;
                if(j < size){
                    ret[idx++] = s[j];
                }
                j = j + i * 2;
            }
        }
    }
    //printf("%s\n",ret);
    
    return ret;
}
__________________________________________________________________________________________________
sample 4 ms submission


char * convert(char * s, int numRows){

    int strLen = strlen(s), counter = 0;//counter计数器，记录目标字符串的当前下标
    char *ret = malloc((strLen+1)*(sizeof(char)));
    if(numRows == 1 || numRows >= strLen) //特殊情况，不需要转化
	{
        return s;
	}
    else 
	{
        for(int i = 1; i <= numRows; i++) 
		{
            for(int j = i; j <= strLen; j += 2*numRows-2) //奇数列的原下标每次递增2*numRows-2
			{
                ret[counter++] = s[j-1];
                if(1 != i &&  i != numRows && j+2*(numRows-i) <= strLen) //当不是第一行与最后一行时，需要计算偶数列的下标
				{
                    ret[counter++] = s[j+2*(numRows-i)-1];
				}
			}
		}
	}
    ret[strLen] = '\0';
    return ret;
}
__________________________________________________________________________________________________
sample 8 ms submission
#include <string.h>
#include <math.h>

char * convert(char * s, int numRows){
    int size = strlen(s);
    if(size <= numRows|| numRows < 2){
        return s;
    }
    
    char *result = malloc(size+1);
    int recycle = 2*numRows - 2;
    int n = 0;//index of result string
     
    for(int row = 0; row < numRows; row++){
        for(int i = 0; i < size +numRows; i+= recycle){
            if(row != numRows-1 && i-row >= 0 && i-row < size){
                result[n++] = s[i-row];
            }
            if(row != 0 && i+row < size && i-row < size){
                result[n++] = s[i+row];
            }
        }
    }
    result[n++] = '\0';
    return result;
}

__________________________________________________________________________________________________
执行用时为 0 ms 的范例


char * convert(char * s, int numRows){

	int len = strlen(s);
    if(numRows==1) return s;
	char *ret = calloc(len + 1, sizeof(char));
	int step = numRows * 2 - 2;
	int i = 0;
	int j = 0;
	for (int row = 0; row < numRows; row++)
	{
        int flag = 1;
		j = row;
		
		while (j < len)
		{
			ret[i++] = s[j];
			if (row == 0 || row == numRows - 1)
			{
				j += step;
			}
			else
			{
				if (flag) 
				{
					flag = 0;
					j += step - 2 * row;
				}
				else
				{
					flag = 1;
					j += 2 * row;
				}
			}
		
        }
    }
	return ret;
}
__________________________________________________________________________________________________
执行用时为 4 ms 的范例


char * convert(char * s, int numRows){
    int len=0,i=0,j=0,x=0;
    len = strlen(s);
    char *a;
    a=(char *)malloc(sizeof(char)*len+1);
    memset(a,0,len+1);
    if(len <= 1|| numRows <=1)
        return s;
    //行数numrows
    //列数
    int lie = len/(numRows*2-2);
    //列个数
    int lienum =numRows*2-2;
    
	for(int i=0;i<numRows;i++){
		for(int j=0;j+i<len;j+=lienum){
			a[x++]=s[i+j];
			if(i!=0&&i!=(numRows-1)&&(j+lienum-i)<len) a[x++]=s[lienum+j-i];
		}
	} 
	return a;
}
__________________________________________________________________________________________________
执行用时为 8 ms 的范例

char * convert(char * s, int numRows){
	if(s==NULL) return s;
	if(numRows==1) return s; 
	int len=strlen(s);
	int cyclelen=2*numRows-2;
	char *ret=(char *)calloc(len+1,sizeof(char));
	int  k=0;
	for(int i=0;i<numRows;i++){
		for(int j=0;j+i<len;j+=cyclelen){
			//int k=0;
			ret[k++]=s[i+j];
			if(i!=0&&i!=(numRows-1)&&(j+cyclelen-i)<len) ret[k++]=s[cyclelen+j-i];
		}
	} 
	return ret;
}
