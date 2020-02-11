__________________________________________________________________________________________________
sample 0 ms submission
bool isMatch_helper(char *cachedResult, int sLen, int pLen, char *originS,
    char *originP, char * s, char * p) {
    int sOffset = s - originS;
    int pOffset = p - originP;

    int index = sOffset * pLen + pOffset;

    /*
    printf("cachedResult sLen:%d pLen:%d sOffset:%d pOffset:%d index:%d\n",
           sLen, pLen, sOffset, pOffset, index);
    */

    if (cachedResult[index] != -1) {
        return cachedResult[index];
    }

    // printf("s:%s p:%s\n", s, p);
    if (!*s && !*p) {
        cachedResult[index] = true;
        return cachedResult[index];
    }
    if (!*p && *s) {
        cachedResult[index] = false;
        return cachedResult[index];
    }

    if (!*s) {
        if (*(p+1) == '*') {
            cachedResult[index] = isMatch_helper(cachedResult, sLen, pLen, originS, originP, s, p+2);
            return cachedResult[index];
        }
        else {
            cachedResult[index] = false;
            return cachedResult[index];
        }
    }

    if (*(p+1) == '*') {
        if (*s == *p || *p == '.') {
            cachedResult[index] = (isMatch_helper(cachedResult, sLen, pLen, originS, originP, s, p+2) ||
                isMatch_helper(cachedResult, sLen, pLen, originS, originP, s+1, p));
            return cachedResult[index];
        } else {
            cachedResult[index] = (isMatch_helper(cachedResult, sLen, pLen, originS, originP, s, p+2));
            return cachedResult[index];
        }

    } else {
        if (*s == *p || *p == '.') {
            cachedResult[index] = (isMatch_helper(cachedResult, sLen, pLen, originS, originP, s+1, p+1));
            return cachedResult[index];
        }
    }
    cachedResult[index] = false;
    return cachedResult[index];
}

bool isMatch(char * s, char * p) {
    char *cachedResult;
    int sLen = strlen(s)+1;
    int pLen = strlen(p)+1;
    int aSize = sLen * pLen;
    // printf("sLen:%d pLen:%d aSize:%d", sLen, pLen, aSize);

    // printf("Allocating memory of size:%d\n", aSize);
    cachedResult = (char *) malloc(sizeof(char) * aSize);
    memset(cachedResult, -1, aSize);
    // printf("After initializing cachedResult\n");
    bool result = isMatch_helper(cachedResult, sLen, pLen, s, p, s, p);
    free(cachedResult);
    return result;
}
__________________________________________________________________________________________________
sample 4 ms submission
bool isMatch(char *s, char *p){
    int i;

    int ls = strlen(s);
    int lp = strlen(p);
    bool* m = malloc((ls + 1) * sizeof(bool));

    // init
    m[0] = true;
    for (i = 1; i <= ls; i++) {
        m[i] = false;
    }

    int ip;
    for (ip = 0; ip < lp; ip++) {
        if (ip + 1 < lp && p[ip + 1] == '*') {
            // do nothing
        }
        else if (p[ip] == '*') {
            char c = p[ip - 1];
            for (i = 1; i <= ls; i++) {
                m[i] = m[i] || (m[i - 1] && (s[i - 1] == c || c == '.'));
            }
        }
        else {
            char c = p[ip];
            for (i = ls; i > 0; i--) {
                m[i] = m[i - 1] && (s[i - 1] == c || c == '.');
            }
            m[0] = false;
        }
    }

    bool ret = m[ls];
    free(m);
    return ret;
}
__________________________________________________________________________________________________
sample 6524 kb submission
bool isMatch(char* s, char* p) {
    if (*p == '\0') return *s == '\0';
    if (*(p + 1) != '*') {
        return (*p == *s || (*p == '.' && *s != '\0')) 
            && isMatch(s + 1, p + 1);
    }
    else {
        while (*p == *s || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p + 2))
                return true;
            ++s;
        }
        return isMatch(s, p + 2);
    }
}
__________________________________________________________________________________________________
sample 6592 kb submission
bool matchFirstChar(const char *t, const char *p) {
    if (*t == *p || *p == '.' && *t != '\0') return true;
    else return false;
}

bool isMatch(char *t, char *p) {
    if (*p == '\0') return *t == '\0';

    if (*(p+1) != '*') {
        if (matchFirstChar(t, p)) return isMatch(t+1, p+1);
        else return false;
    }
    else {
        if (isMatch(t, p+2)) return true;
        // else
        while (matchFirstChar(t, p)) {
            if (isMatch(t+1, p+2)) return true;
            ++t;
        }
        return false;
    }
}

__________________________________________________________________________________________________
sample 6604 kb submission
bool isMatch(char* s, char* p)
{
    char *prev, *cur;
    int first_match;
    int len;

    len = strlen(p);

    if (*p == '\0')
    {
        if (*s != '\0')
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (*s == '\0')
    {
        if (len >= 2 && *(p + 1) == '*')
        {
            return isMatch(s, p + 2);
        }
        
        return false;
    }

    if (*p == '.' || *p == *s)
    {
        first_match = true;
    }
    else
    {
        first_match = false;
    }

    if (len >= 2 && *(p + 1) == '*')
    {
        return isMatch(s, p + 2) || (first_match && isMatch(s + 1, p));
    }
    else
    {
        return first_match && isMatch(s + 1, p + 1);
    }
}
__________________________________________________________________________________________________
