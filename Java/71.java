__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String simplifyPath(String path) {
        if (path.length() == 0)
            return path;
        
        char[] str = new char[path.length()];
        int[] dir = new int[path.length()];
        int di = 0, si = 0;
        int point_num = 0, len = path.length();
        for (int i = 0; i < len; ++i)
        {
            char c = path.charAt(i);
            switch(c)
            {
                case '/':
                    if (si == 0)
                    {
                        str[si++] = c;
                        dir[di++] = 0;
                    }
                    else if (str[si-1] == '/')
                        ;
                    else if (str[si-1] == '.')
                    {
                        if (point_num == 1)
                            si--;
                        else if (point_num == 2)
                        {
                            if (di == 1)
                            {
                                si = dir[0] + 1;
                                di++;
                            }
                            else if (str[dir[di-2]] == '/')
                            {
                                si = dir[di-2] + 1;
                            }
                            else
                            {
                                si = dir[di-2] + 2; 
                            }
                            di--;
                        }
                        point_num = 0;
                    }
                    else
                    {
                        dir[di++] = si - 1;
                        str[si++] = c;
                    }
                    break;
                case '.':
                    str[si++] = c;
                    point_num++;
                    break;
                default:
                    point_num = 0;
                    str[si++] = c;
            }
        }
        
        if (point_num == 1)
            si--;
        else if (point_num == 2)
        {
            if (di == 1)
            {
                si = dir[0] + 1;
            }
            else if (str[dir[di-2]] == '/')
            {
                si = dir[di-2] + 1;
            }
            else
            {
                si = dir[di-2] + 2; 
            }
        }
        
        if (str[si - 1] == '/' && si != 1)
            si--;
        return new String(str, 0, si);
    }
}
__________________________________________________________________________________________________
sample 35628 kb submission
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<String>();
        String[] str = path.split("/");
        for (String ss: str) {
            String s = ss.trim();
            if (s.length() > 0) {
                if (s.equals("..")) {
                    if (!stack.isEmpty()) {
                        stack.pop();
                    }
                } else if (!s.equals(".")){
                    stack.push(s);
                }                
            }
        }
        StringBuilder strbld = new StringBuilder();
        while (!stack.isEmpty()) {
            strbld.insert(0, stack.pop());
            strbld.insert(0, "/");
        }
        if (strbld.length() == 0) {
            return "/";
        }
        return strbld.toString();
    }
}
__________________________________________________________________________________________________
