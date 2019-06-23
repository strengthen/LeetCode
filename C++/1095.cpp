__________________________________________________________________________________________________
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int t, MountainArray& arr) {
  auto peak = 0, r = arr.length() - 1;
  while (peak < r) {
    int m = (peak + r) / 2;
    if (arr.get(m) > arr.get(m + 1)) r = m;
    else peak = m + 1;
  }
  auto i = bSearch(arr, t, 0, peak);
  return i != -1 ? i : bSearch(arr, t, peak + 1, arr.length() - 1, false);
}
int bSearch(MountainArray& arr, int t, int l, int r, bool asc = true) {
  while (l < r) {
    int m = (l + r) / 2;
    if ((asc && arr.get(m) < t) || (!asc && arr.get(m) > t)) l = m + 1;
    else r = m;
  }
  return arr.get(l) == t ? l : -1;
}
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
