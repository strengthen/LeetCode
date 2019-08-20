__________________________________________________________________________________________________
sample 28 ms submission
def isValid(s):
    for c in s:
        if ord(c)>ord('Z') or ord(c)<ord('A'):
            return False
    return True
    
class Solution:
    def isValid(self, code: str) -> bool:
        if len(code)==0:
            return False
        if code[0]!='<':
            return False
        ind=0
        stack=[]                
        while ind<len(code):
            if ind+9<=len(code) and code[ind:ind+9]=='<![CDATA[':
                if len(stack)==0:           return False
                while code[ind:ind+3]!=']]>':
                    ind+=1
                    if ind==len(code)-2:    return False
                ind+=3
            elif code[ind:ind+2]=='</':
                cs=''                    
                while code[ind]!='>':
                    cs+=code[ind]
                    ind+=1
                    if ind==len(code):      return False                    
                ind+=1
                cs=cs[2:]
                if len(stack)==0 or stack[-1]!=cs:
                    return False
                stack.pop(-1)
                if len(stack)==0 and ind!=len(code):
                    return False
            elif code[ind]=='<':
                stack.append('')
                while code[ind]!='>':
                    stack[-1]+=code[ind]
                    ind+=1
                    if ind==len(code):      return False                    
                ind+=1
                stack[-1]=stack[-1][1:]
                ss=stack[-1]
                if not isValid(ss) or len(ss)<1 or len(ss)>9:
                    return False
            else:
                ind+=1
        return True if len(stack)==0 else False
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def isValid(self, code: str) -> bool:
        tags=[]
        if code[0]!='<' or len(code)<=2:
            print('invalid initial')
            return False
        cdata=False
        tag='<'
        rtag=''
        i=1
        while i<len(code):
            c=code[i]
            if not tag and not tags:
                print('root tag closed')
                return False
            if cdata:
                if code[i-2:i+1]==']]>':
                    cdata=False
                i+=1
                if i==len(code):
                    print('unclosed cdata')
                    return False
            elif tag:
                if code[i]=='>':
                    if tag=='<':
                        print('empty tag')
                        return False
                    tags.append(tag[1:])
                    tag=''
                elif code[i]=='!' and tag=='<':
                    if i<=len(code)-11 and code[i:i+8]=='![CDATA[':
                        i+=8
                        cdata=True
                        tag=''
                        continue
                    else:
                        print('invalid cdata header')
                        print(code[i:i+8])
                        return False
                elif code[i]=='/' and tag=='<':
                    tag=''
                    rtag='<'
                elif ord(code[i])>90 or ord(code[i])<65 or len(tag)>=10:
                    print('invalid tag name')
                    return False
                else:
                    tag+=code[i]
                i+=1
            elif rtag:
                if code[i]=='>':
                    if not tags:
                        print('empty tags')
                        return False
                    otag=tags.pop()
                    if otag!=rtag[1:]:
                        print('unmatched tag at'+str(i))
                        print(otag,rtag[1:])
                        return False
                    rtag=''
                elif ord(code[i])>90 or ord(code[i])<65 or len(rtag)>=10:
                    print('invalid reversed tag name')
                    return False
                else:
                    rtag+=code[i]
                i+=1     
            elif code[i]=='<':
                tag='<'
                i+=1
            else:
                i+=1
        return not tags
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def isValid(self, code: str) -> bool:
        stack = []
        i = 0
        while i < len(code):
            if i > 0 and not stack:
                return False # rule 1
            elif code.startswith('<![CDATA[', i):
                j = i + 9
                k = code.find(']]>', j)
                if k < 0:
                    return False
                i = k + 3
            elif code.startswith('</', i):
                j = i + 2
                k = code.find('>', j)
                if k < 0 or not (0 < k - j < 10) or any(not c.isupper() for c in code[j:k]):
                    return False
                if not stack or (stack.pop() != code[j:k]):
                    return False
                i = k + 1
            elif code.startswith('<', i):
                j = i + 1
                k = code.find('>', j)
                if k < 0 or not (0 < k - j < 10) or any(not c.isupper() for c in code[j:k]):
                    return False
                stack.append(code[j:k])
                i = k + 1
            else:
                i += 1
        return not stack