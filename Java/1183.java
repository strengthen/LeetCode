__________________________________________________________________________________________________
class Solution {
    public static int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int nw = width / sideLength;
    int nh = height / sideLength;
    int rw = width % sideLength;
    int rh = height % sideLength;

    // Split the matrix into four kind of regions:
    //  1. nw * nh sideLength * sideLength squares
    //  2. one rw * rh region
    //  3. nh vertical regions of rw * sideLength
    //  4. nw horizontal regions of rh * sideLength
    int m = Math.min(rw * rh, maxOnes);
    int output = nw * nh * maxOnes + m;
    // Overlap one vertical and one horizontal region to have a L-shape region
    // There will be n such L-shape region with duplicate upper left rw * rh corner.
	int n = Math.min(nw, nh);
    int area = ((rw + rh) * sideLength - rw * rh);
    output += n * (Math.min(maxOnes, area) + m);

    // Include the extra horizontal or vertical regions if any
    if (nw > nh) {
      output += (nw-nh) * Math.min(maxOnes, rh * sideLength);
    } else if (nw < nh) {
      output += (nh-nw) * Math.min(maxOnes, rw * sideLength);
    }
    return output;
  }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
