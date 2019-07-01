__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int[] dp = new int[books.length + 1];
        
        dp[0] = 0;
        
        for (int i = 1; i <= books.length; i++) {
            int width = books[i-1][0];
            int height = books[i-1][1];
            
            dp[i] = dp[i-1] + height;
            
            for (int j = i - 1; j > 0 && width + books[j-1][0] <= shelfWidth; j--) {
                height = Math.max(height, books[j-1][1]);
                width += books[j-1][0];
                dp[i] = Math.min(dp[i], dp[j-1] + height);
            }
        }
        
        return dp[books.length];
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private int[][] memo;
    public int minHeightShelves(int[][] books, int shelf_width) {
        memo = new int[books.length + 1][shelf_width + 1];
        return minHeightShelves(books, 0, 0, shelf_width, shelf_width);
    }

    private int minHeightShelves(int[][] books, int i, int cur_height, int remain_width, int shelf_width) {
        if(i == books.length) {
            return cur_height;
        }
        if(memo[i][remain_width] != 0) return memo[i][remain_width];

        memo[i][remain_width] = cur_height + minHeightShelves(books, i + 1, books[i][1],
                shelf_width - books[i][0], shelf_width);

        if(remain_width - books[i][0] >= 0) {
            memo[i][remain_width] = Math.min(memo[i][remain_width], minHeightShelves(books, i + 1, Math.max(cur_height, books[i][1]), remain_width - books[i][0], shelf_width));
        }
        return memo[i][remain_width];
    }
}
__________________________________________________________________________________________________
