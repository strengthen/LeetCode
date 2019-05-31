__________________________________________________________________________________________________
sample 10 ms submission
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        while(s<e) {
            int mid = s + (e-s)/2;
            if (isBadVersion(mid)) {
                e = mid;
            } else {
                s = mid+1;
            }
        }
        return s;         
    }
}
__________________________________________________________________________________________________
sample 34104 kb submission
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        
        while(start < end){
            int mid = start + (end - start) / 2;
            
            if(isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;
            
            if(!isBadVersion(mid))
                start = mid + 1;
            else 
                end = mid - 1;
        }
        
        return start;
    }
}
__________________________________________________________________________________________________
