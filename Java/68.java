__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
/**
Solution: 
//1. 首先要做的就是确定每一行能放下的单词数，这个不难，就是比较n个单词的长度和加上n - 1个空格的长度跟给定的长度L来比较即可
//2. 找到了一行能放下的单词个数，然后计算出这一行存在的空格的个数，是用给定的长度L减去这一行所有单词的长度和。
//3. 得到了空格的个数之后，就要在每个单词后面插入这些空格，这里有两种情况，比如某一行有两个单词"to" 和 "a"，给定长度L为6
//4. 如果这行不是最后一行，那么应该输出"to   a"，如果是最后一行，则应该输出 "to a  "，所以这里需要分情况讨论，最后一行的处理方法和其他行之间略有不同。
//5. 最后一个难点就是，如果一行有三个单词，这时候中间有两个空，如果空格数不是2的倍数，那么左边的空间里要比右边的空间里多加入一个空格，那么我们只需要用总的空格数除以空间  个数, 能除尽最好，说明能平均分配，除不尽的话就多加个空格放在左边的空间里".
**/
    
    //Solution: two pointers -- starting from index 0, cur, next pointers that point to the start indexes of word in words array that are the first word in current and next lines.
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<String>();
        if(words == null || words.length == 0 || maxWidth <= 0) {
            return result;
        }
        
        int cur = 0;
        while(cur < words.length) {
            //step1 -- 确定每一行能放下的单词数，这个不难，就是比较n个单词的长度和加上n - 1个空格的长度跟给定的长度L来比较即可
            int len = words[cur].length() + 1; //total length of chosen words. +1 : one whitespace 
            int next = cur + 1; //points to next word
            
            //get the list of words[cur, next) that can be put into current line with maxWidth limitation.
            while(next < words.length && len + words[next].length() <= maxWidth) {
                len = len + words[next].length() + 1; //+1: whitespace 
                next = next+1; //next points to next word
            }
            
            //till now, words[cur, next-1] can be fit into current line; NOTE: next points to the index of the first word in next line.
            //check how many words are there for current line.
            int count = (next-1)-cur+1;  //#of words in current line == (next-1) - cur + 1
            
            StringBuilder sb = new StringBuilder();
            //check if current line is the last line or current line has only one word?
            if(next == words.length /*Last Line*/ || count == 1/*only one word in current line*/) {
                //Append words[cur, next-1] to sb
                for(int i = cur; i <= next-1; i++) {
                    sb.append(words[i]);
                    if(sb.length() < maxWidth) {
                        sb.append(" ");
                    }
                }
                
                for(int i = sb.length(); i < maxWidth; i++) {
                    sb.append(" ");
                }
            } else { //not last line && current line has >= words
                //total len of these words
                len = len - count; //calculate total length of words -- not include " ".
                int spaces = (maxWidth - len)/(count-1); //normal #of spaces each word
                int mod = maxWidth - len - spaces * (count-1);               
                for(int i = cur; i < next-1; i++) {
                    sb.append(words[i]);
                    for(int j = 0; j < spaces; j++) {
                        sb.append(" ");
                    }
                    
                    if((i-cur) < mod) {
                        sb.append(" ");
                    }
                }
                sb.append(words[next-1]);
            }
            
            result.add(sb.toString());
            cur = next; //move cur to next -- the index of first word in next line.
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
sample 34316 kb submission
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int wordNums = 0, currentLen = 0, res = 0, mod = 0, currentIndex = 0;
        List<String> result = new ArrayList<>();
        while (currentIndex < words.length) {
            currentLen += words[currentIndex].length();
            if (currentLen > maxWidth) {
                StringBuilder line = new StringBuilder();
                int spaceLen = (maxWidth - currentLen + words[currentIndex].length() + wordNums);
                res = wordNums - 1 == 0 ? 0 : spaceLen / (wordNums - 1);
                mod = wordNums - 1 == 0 ? spaceLen : spaceLen % (wordNums - 1);
                for (int i = currentIndex - wordNums; i < currentIndex - 1; i++) {
                    line.append(words[i]);
                    int spaceNum = (res + (mod-- > 0 ? 1 : 0));
                    for (int j = 0; j < spaceNum; j++) {
                        line.append(" ");
                    }
                }
                line.append(words[currentIndex - 1]);
                for (int i  = 0; i < mod; i++) {
                    line.append(" ");
                }
                result.add(line.toString());
                currentLen = 0;
                wordNums = 0;
            } else {
                wordNums++;
                currentLen++;
                currentIndex++;
            }
        }
        StringBuilder lastLine = new StringBuilder();
        for (int i = currentIndex - wordNums; i < currentIndex - 1; i++) {
            lastLine.append(words[i]);
            lastLine.append(" ");
        }
        lastLine.append(words[currentIndex - 1]);
        for (int i = 0; i < maxWidth - currentLen + 1; i++) {
            lastLine.append(" ");
        }
        result.add(lastLine.toString());
        return result;
    }
}
__________________________________________________________________________________________________
