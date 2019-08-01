__________________________________________________________________________________________________
sample 0 ms submission
/*
 * @lc app=leetcode id=504 lang=java
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.07%)
 * Likes:    157
 * Dislikes: 121
 * Total Accepted:    43.5K
 * Total Submissions: 96.5K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
    public String convertToBase7(int num) {
        return Integer.toString(num,7);
    }
}

__________________________________________________________________________________________________
sample 35524 kb submission
class Solution {
    public String convertToBase7(int num) {
        StringBuilder sb = new StringBuilder();
        int v = Math.abs(num);
        sb.append(v%7);
        int n = v/7;
        while(n != 0) {
            sb.insert(0,n % 7);
            n = n / 7;
        }
        return num >= 0 ? sb.toString() : "-" + sb.toString();
    }
}
__________________________________________________________________________________________________
