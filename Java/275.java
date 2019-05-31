__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
  public int hIndex(int[] citations) {

    int start = 0, end = citations.length;

    while (start < end) {
      int mid = (end - start) / 2 + start;

      if (citations.length - mid < citations[mid]) {
        end = mid;
      } else if (citations.length - mid > citations[mid]) {
        start = mid+1;
      } else {
        return citations.length - mid;
      }
    }

    return citations.length - start;
  }
}
__________________________________________________________________________________________________
sample 39544 kb submission
class Solution {

    public int hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return 0;
        }
        int n = citations.length;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int diff = citations[mid] - (n - mid);
            if (diff >= 0) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        // ***注意最后h-index是 n-left***
        if (citations[left] - (n - left) >= 0) {
            return n-left;
        } else {
            return 0;
        }
    }
}
__________________________________________________________________________________________________
