__________________________________________________________________________________________________
sample 0 ms submission


int lengthOfLongestSubstring(char * s){
        int res =0;
        
        int freq[256] = { 0 };
        int l = 0, r = 0;
        
        while (s[r]!='\0') {

            if (freq[s[r]] == 0)
                freq[s[r++]] ++;
            else
                freq[s[l++]] --;

            res = res > (r-l) ? res:(r-l);
        }
        
        return res;
}
__________________________________________________________________________________________________
sample 4 ms submission
int lengthOfLongestSubstring(char* s)
{
    bool flags[128] = {};
    int i, j;
    int maxLen = 0;
    
    if (s == NULL)
        return 0;
    
    for (i = 0, j = 0; s[j] != '\0';)
    {
        char ch;
        
        ch = s[j];
        if (flags[ch] == false)
        {
            int temp;
            flags[ch] = true;
            ++j;
            temp = j - i;
            maxLen = (temp > maxLen) ? temp : maxLen;
        }
        else
        {
            ch = s[i++];
            flags[ch] = false;
        }
        
    }
   
    
	return maxLen;
}

__________________________________________________________________________________________________
sample 8 ms submission


int lengthOfLongestSubstring(char * s){
    int max = 1;
    int num = 1;
    int j_start=0;
    
    if(!s[0])
        return 0;
    else if(!s[1])
        return 1;
   for(int i = 1 ; s[i] ; i++){
        for(int j = j_start;j<i;j++){
            if(s[i] != s[j])
                num++;
            else 
                j_start = j+1;
        }
        if(max < num)
            max = num;
        num=1;
    }
   
    return max;
}

__________________________________________________________________________________________________
执行用时为 0 ms 的范例


int lengthOfLongestSubstring(char * s){
int maxlen = 0;
	int map[256];
	memset(map, -1, sizeof(map));
	int  currlen = 0;
	int i = 0;
    int start=0;
	char *h = s;

	while (*h)
	{
		char ch = *h;
		int first = map[ch];
		if (first >= start)
		{
            start=first;
			int strlen = i - first;
			currlen = strlen - 1;
		}
		map[ch] = i;
		i++;
		currlen++;
		maxlen = maxlen > currlen ? maxlen : currlen;
		h++;
	}
	return maxlen;
}
__________________________________________________________________________________________________
执行用时为 4 ms 的范例

#define ASCII_LEN 256

int lengthOfLongestSubstring(char * s){

    int map[ASCII_LEN];
    memset(map, -1, sizeof(map));

    int len = strlen(s);
    if(!len) return 0;

    int max = 0, rpt = -1;
    for(int i = 0; i < len; i++)
    {
        int cur = s[i];
        if(map[cur] != -1 && rpt < map[cur])
        {
            rpt = map[cur];
        }
        if(i - rpt > max)
        {
            max = i - rpt;
        }
        map[cur] = i;
    }
    return max;
}
__________________________________________________________________________________________________
执行用时为 8 ms 的范例


int lengthOfLongestSubstring(char * s){
int maxlen = 0;
	int map[256];
	memset(map, -1, sizeof(map));
	int  currlen = 0;
	int i = 0;
    int start=0;
	char *h = s;

	while (*h)
	{
		char ch = *h;
		int first = map[ch];
		if (first >= start)
		{
            start=first;
			int strlen = i - first;
			currlen = strlen - 1;
		}
		map[ch] = i;
		i++;
		currlen++;
		maxlen = maxlen > currlen ? maxlen : currlen;
		h++;
	}
	return maxlen;
}
