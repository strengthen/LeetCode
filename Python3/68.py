__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        n = len(words)
        if n == 0:
            return []
        res = []
        cur, num_letters = [], 0
        for w in words:
            if len(cur) + len(w) + num_letters > maxWidth:
                if len(cur) == 1:
                    res.append(cur[0] + ' '*(maxWidth - num_letters))
                else:
                    num_space = maxWidth - num_letters
                    gap, remain_gap = divmod(num_space, len(cur) - 1)
                    for i in range(remain_gap):
                        cur[i] += ' '
                    res.append((' '*gap).join(cur))
                cur, num_letters = [], 0
            cur += [w]
            num_letters += len(w)
        res.append(' '.join(cur) + ' '*(maxWidth - num_letters - len(cur) + 1))
        return res        
__________________________________________________________________________________________________
sample 13064 kb submission
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        curLine = [];
        curLineCharacterLength = 0;
        
        lines = [];
        output = [];
        
        for word in words:
            if len(curLine) == 0:
                curLine.append(word);
                curLineCharacterLength = len(word);
            else:
                if curLineCharacterLength + len(word) + 1 <= maxWidth:
                    curLine.append(" " + word);
                    curLineCharacterLength += len(word) + 1;
                else:
                    lines.append(curLine);
                    curLine = [word];
                    curLineCharacterLength = len(word);
        if len(curLine) > 0:
            lines.append(curLine);
                    
        for i in range(len(lines)):
            line = lines[i];
            if i < len(lines) - 1: #not last line
                lineWordLength = 0;
                for word in line:
                    lineWordLength += len(word);
                remainingSpace = maxWidth - lineWordLength;
                remainingSpacePer = remainingSpace//(len(line) - 1) if len(line)-1 > 0 else remainingSpace;
                remainingPercentSpace = remainingSpace % (len(line) - 1) if len(line)-1 > 0 else 0;
                
                lineString = "";
                for j in range(len(line)):
                    word = line[j];
                    lineString += word;
                    if j < len(line) - 1 or len(line) == 1:
                        lineString += "".join(remainingSpacePer * [" "]);
                    if j < remainingPercentSpace:
                        lineString += " ";
                output.append(lineString);
                    
            else: #last line, handle differently
                lineWordLength = 0;
                for word in line:
                    lineWordLength += len(word);
                remainingSpace = maxWidth - lineWordLength;
                
                lineString = "".join(line) + "".join(remainingSpace * [" "]);
                output.append(lineString);
            
        return output;
__________________________________________________________________________________________________
