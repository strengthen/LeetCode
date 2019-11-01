__________________________________________________________________________________________________
sample 1 Dynamic Programming  Runtime: 100 ms Memory Usage: 44.8 MB
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.sums = [];
    this.sums.push(0);
    for(let i = 1; i <= nums.length; i++) {
        this.sums[i] = nums[i - 1] + this.sums[i - 1];
    }
};

/**
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.sums[j + 1] - this.sums[i];
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(i,j)
 */
__________________________________________________________________________________________________

__________________________________________________________________________________________________
