__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean canTransform(String start, String end) {
        // https://www.cnblogs.com/grandyang/p/9001474.html
        char[] arr1 = start.toCharArray();
        char[] arr2 = end.toCharArray();
        int len = arr1.length, i = 0, j = 0;
        while(i < len && j < len) {
            while(i < len && arr1[i] == 'X')   i++;
            while(j < len && arr2[j] == 'X')   j++;
            if((i < len) ^ (j < len))   return false;
            if(i < len && j < len) {
                if(arr1[i] != arr2[j])  return false;
                if(arr1[i] == 'L' && i < j) return false;
                if(arr1[i] == 'R' && i > j) return false;
                i++;
                j++;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 37240 kb submission
class Solution {
    public boolean canTransform(String start, String end) {
        int i = 0, j = 0;
        int length = start.length();
        
        while(i < length && j < length)
        {
            while(i < length && start.charAt(i) == 'X') i++;
            while(j < length && end.charAt(j) == 'X') j++;
            if((i == length) && (j == length))
                return true;
            if((i < length) ^ (j < length))
                return false;
            char c1 = start.charAt(i);
            char c2 = end.charAt(j);
            if((c1 != c2) || (c1 == 'R') && (i>j) || (c2 == 'L') && (i<j))
                return false;
            i++;
            j++;
        }
        return true;
    }
}
__________________________________________________________________________________________________
