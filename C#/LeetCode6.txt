__________________________________________________________________________________________________
92ms
public class Solution {
    public string Convert(string s, int numRows) {
        if(numRows == 1 || s.Length <= numRows)
            return s;
        
        char[] retArr = new char[s.Length];
        int index = 0;
        int cycleLen = 2 * numRows - 2;
        for(int i =0;i< numRows; i++)
        {    
            for(int j =0; j + i < s.Length; j+= cycleLen)
            {
                retArr[index++] = s[j + i];
                if(i != 0 && i != numRows-1 && j + cycleLen - i < s.Length)
                    retArr[index++] = s[j + cycleLen -i];
            }
        }
           
        return new string(retArr);
    }
}
__________________________________________________________________________________________________
96ms
public class Solution
{
    public string Convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        int l = s.Length;
        StringBuilder sb = new StringBuilder();
        int p = 0;
        while (p < l)
        {
            sb.Append(s[p]);
            p += numRows * 2 - 2;
        }
        for (int i = 1; i < numRows - 1; i++)
        {
            int p1 = i, p2 = numRows * 2 - 2 - i;
            while (p1 < l)
            {
                sb.Append(s[p1]);
                if (p2 < l)
                    sb.Append(s[p2]);
                p1 += numRows * 2 - 2;
                p2 += numRows * 2 - 2;
            }
        }
        p = numRows - 1;
        while (p < l)
        {
            sb.Append(s[p]);
            p += numRows * 2 - 2;
        }
        return sb.ToString();
    }
}
__________________________________________________________________________________________________
100ms
public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) return s;

        List<StringBuilder> rows = new List<StringBuilder>();
        for (int i = 0; i < Math.Min(numRows, s.Length); i++)
            rows.Add(new StringBuilder());

        int curRow = 0;
        bool goingDown = false;

        foreach (char c in s) {
            rows[curRow].Append(c);
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        StringBuilder ret = new StringBuilder();
        foreach (StringBuilder row in rows) ret.Append(row);
        return ret.ToString();
    }
}
__________________________________________________________________________________________________
24092 kb
public class Solution {
    public string Convert(string s, int numRows) {
        string[] rows=new string[numRows];
        for(int i=0;i<numRows;i++){
            rows[i]=String.Empty;
        }
        int row=0;
        int inc=1;
        for(int i=0;i<s?.Length;i++){
            rows[row]+=s[i];
            if(numRows>1){
                row+=inc;
                if(row>numRows-2){
                    inc=-1;
                }
                else if(row==0){
                    inc=1;
                }
            }
        }

        return String.Concat(rows);
    }
}
__________________________________________________________________________________________________
24120 kb
public class Solution {
    public string Convert(string s, int numRows) {
        if (s == null || numRows < 1)
                return null;

            int size = s.Length;

            if (size < 3 || numRows == 1)
                return s;

            string result = "";
            int index = 0;
            int pillarCount = (size / numRows) + 1;
            var pillars = new int?[pillarCount];

            for (int i = 0; i < pillarCount; i++)
                pillars[i] = i * (numRows - 1);

            for (int row = 0; row < numRows; row++)
            {
                foreach (int? col in pillars)
                {
                    index = (int)col * 2 + row;
                    if (col != null)
                    {
                        int prevIndex = index - (row * 2);

                        if (col > 0 && row > 0 && row < numRows - 1 && prevIndex < size)
                            result = result + s[prevIndex];

                        if (index < size)
                            result = result + s[index];
                    }
                }
            }
        
        return result;
    }
}
__________________________________________________________________________________________________
