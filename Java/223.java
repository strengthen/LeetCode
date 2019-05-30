__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int right = Math.min(C, G);
        int left = Math.max(A, E);
        
        int top = Math.min(D, H);
        int bottom = Math.max(B, F);
        
        int area = (right - left) * (top - bottom);
        
        int total = (C - A) * (D - B) + (G - E) * (H - F);
        if (!(A >= G ||
          B >= H ||
          C <= E || 
          D <= F)) total -= area;
        return total;
        // return area > 0 ? area : 0;
    }
}
__________________________________________________________________________________________________
sample 33948 kb submission
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C-A) * (D-B);
        int areaB = (G-E) * (H-F);
        int left = Math.max(A,E);
        int bottom = Math.max(F,B);
        int right = Math.min(G,C);
        int top = Math.min(D,H);
        int overlap = 0;
        if(right > left && top > bottom)
            overlap = (right - left) * (top - bottom);
        return areaA + areaB - overlap;
    }
}
__________________________________________________________________________________________________
