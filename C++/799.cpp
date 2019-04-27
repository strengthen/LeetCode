__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0) return poured < 1.0 ? poured : 1.0; 
        int queryId = query_row * (query_row + 1) / 2 + query_glass + 1;
        vector<double> currentRow = {(double)poured};
        int count = 1;
        double retVal;
        while (count <= queryId) {
            double newHead = 0;
            double newTail = 0;
            if (currentRow.front() > 1.0) newHead = (currentRow.front() - 1.0) / 2;
            if (currentRow.back() > 1.0) newTail = (currentRow.back() - 1.0) / 2;
            double a = currentRow[0];
            double b;
            for (int i = 0; i < currentRow.size() - 1; ++i) {
                b = currentRow[i + 1];
                currentRow[i + 1] = 0;
                if (a > 1.0) currentRow[i + 1] += (a - 1.0) / 2;
                if (b > 1.0) currentRow[i + 1] += (b - 1.0) / 2;
                a = b;
            }
            currentRow.front() = newHead;
            currentRow.push_back(newTail);
            if (count + currentRow.size() >= queryId) {
                retVal = currentRow[queryId - count - 1] > 1.0 ? 1.0 : currentRow[queryId - count - 1];
                break;
            }
            count += currentRow.size();
        }
        return retVal;
    }
};
__________________________________________________________________________________________________
sample 10136 kb submission
class Solution {
public:
    // O(n ^ 2) space
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};            // query_row and query_glass belong to [0,99]
        result[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i+1][j] += (result[i][j] - 1) / 2;
                    result[i+1][j+1] += (result[i][j] - 1) / 2;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};
__________________________________________________________________________________________________
