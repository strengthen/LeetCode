__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int lenN=name.length(), lenT=typed.length();
        int start=0;
        for(int i=0; i<lenT; i++) {
            if(typed.charAt(i)==name.charAt(start)) {
                start++;
                if(start==lenN) return true;
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 35400 kb submission
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int typedwrong=0;
        if(name.charAt(0)!=typed.charAt(0))
            return false;
        if(name.charAt(name.length()-1)!=typed.charAt(typed.length()-1))
            return false;
        if(name.equals(typed))
            return true;
        else
        {
            if(name.length()>=typed.length())
                return false;
            else
            {
                for(int i=0;i<name.length();i++)
                {
                    if(typed.length()<=(i+typedwrong))
                        return false;
                    if(name.charAt(i)==typed.charAt(i+typedwrong))
                        continue;
                    else if(name.charAt(i)!=typed.charAt(i+typedwrong))
                    {
                        if(typed.charAt(i+typedwrong)==typed.charAt(i+typedwrong-1))
                        {
                            typedwrong++;
                            i--;
                        }
                        else return false;
                    }
                }
                return true;
            }
        }
    }
}
__________________________________________________________________________________________________
