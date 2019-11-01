__________________________________________________________________________________________________
sample 1 Dynamic Programming  Runtime: 88 ms Memory Usage: 41.6 MB
/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    if(matrix == null || matrix.length == 0) return;
    this.dp = [];
    let m = matrix.length, n = matrix[0].length;
    for(let i = 0; i <= m; i++) {
        this.dp[i] = new Array(n + 1).fill(0)
    }
    for(let i = 1; i <= m; i++) {
        for(let j = 1; j <= n; j++) {
            this.dp[i][j] = this.dp[i - 1][j] + this.dp[i][j - 1] + matrix[i - 1][j - 1] - this.dp[i - 1][j - 1];
        }
    }
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    return this.dp[row2 + 1][col2 + 1] - this.dp[row1][col2 + 1] - this.dp[row2 + 1][col1] + this.dp[row1][col1];
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
__________________________________________________________________________________________________

__________________________________________________________________________________________________
