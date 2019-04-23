__________________________________________________________________________________________________
2ms
class Solution {
    public String convert(String s, int nRows) {
        int length = s.length();
        if (length <= nRows || nRows == 1) return s;
        char[] chars = new char[length];
        int step = 2 * (nRows - 1);
        int count = 0;
        for (int i = 0; i < nRows; i++){
    		int interval = step - 2 * i;
    		for (int j = i; j < length; j += step){
    		   	chars[count] = s.charAt(j);
    			count++;
    			if (interval < step && interval > 0 
    && j + interval < length && count <  length){
    				chars[count] = s.charAt(j + interval);
    				count++;
    			}
    		}
    	}
        return new String(chars);  
    }
}
__________________________________________________________________________________________________
3sm
class Solution {
    public String convert(String s, int numRows) {
        if (s == null || s.length() < 2 || numRows < 2 || numRows >= s.length()) return s;
        
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        int curPos, skipDownChars, skipUpChars; 
        for (int i = 0; i < numRows; i++) { // Go by each level
            curPos = i;
            boolean goingDown = true;
            skipDownChars = 2 * (numRows - 1 - i);
            skipUpChars = 2 * i;
            while (curPos < len) {
                if (goingDown && skipDownChars > 0) {
                    sb.append(s.charAt(curPos));
                    curPos += skipDownChars;
                } else if (!goingDown && skipUpChars > 0){
                    sb.append(s.charAt(curPos));
                    curPos += skipUpChars;
                }
                goingDown = !goingDown;
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1)
            return s;
        
        StringBuilder result = new StringBuilder();
        int pos = 0;
        while (pos < s.length()) {
            result.append(s.charAt(pos));
            pos += 2 * (numRows - 1);
        }

        for (int i = 1; i < numRows - 1; i++) {
            pos = 0;
            boolean down = true;
            while (pos < s.length()) {
                if (down && pos + i < s.length())
                    result.append(s.charAt(pos + i));
                if (!down && pos + numRows - 1 - i < s.length())
                    result.append(s.charAt(pos + numRows - 1 - i));
                pos += numRows - 1;
                down = !down;
            }
        }
        
        pos = numRows - 1;
        while (pos < s.length()) {
            result.append(s.charAt(pos));
            pos += 2 * (numRows - 1);
        }
        
        return result.toString();
    }
}
__________________________________________________________________________________________________
36328 kb
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;

        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < Math.min(numRows, s.length()); i++)
            rows.add(new StringBuilder());

        int curRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows.get(curRow).append(c);
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        StringBuilder ret = new StringBuilder();
        for (StringBuilder row : rows) ret.append(row);
        return ret.toString();
    }
}
__________________________________________________________________________________________________
36572 kb 
class Solution {
    public String convert(String s, int numRows) {        
        //mathematic
        if(numRows == 1)
            return s;
        
        StringBuilder res = new StringBuilder();
        int n = s.length();
        int len = 2 * numRows - 2;
        
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; i + j < n; j += len) {
                res.append(s.charAt(i + j));
                if(i != 0 && i != numRows - 1 && i + j + 2 * (numRows - i - 1) < n)
                    res.append(s.charAt(i + j + 2 * (numRows - i - 1)));
            }
        }
        return res.toString();
    }
}
__________________________________________________________________________________________________
