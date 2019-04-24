__________________________________________________________________________________________________
sample 8 ms submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int s1 = (C - A) * (D - B);
		int s2 = (G - E) * (H - F);
		if (A >= G || E >= C || B >= H || F >= D) { return s1 + s2; }
		else { return s1 - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)) + s2; }
	}
};
__________________________________________________________________________________________________
sample 7980 kb submission
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const long areaA = max((long)C - (long)A, 0L) * max((long)D - (long)B, 0L);
        const long areaB = max((long)G - (long)E, 0L) * max((long)H - (long)F, 0L);

        const int xBegin = max(A, E), xEnd = min(C, G);
        const int yBegin = max(B, F), yEnd = min(D, H);
        const int commonArea = (xBegin < xEnd && yBegin < yEnd) ?
            (xEnd - xBegin) * (yEnd - yBegin) : 0;
        return areaA + areaB - commonArea;
    }
};
__________________________________________________________________________________________________
