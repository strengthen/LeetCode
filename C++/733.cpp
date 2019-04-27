__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int newColor,int color){
         if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) dfs(image, r-1, c, newColor, color);
            if (c >= 1) dfs(image, r, c-1, newColor, color);
            if (r+1 < image.size()) dfs(image, r+1, c, newColor, color);
            if (c+1 < image[0].size()) dfs(image, r, c+1, newColor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, newColor, color);
        return image;
    }
};
__________________________________________________________________________________________________
sample 10176 kb submission
int t = []{ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int basecolor = image[sr][sc];
        image[sr][sc] = newColor;
        setcolor(image,sr,sc,basecolor,newColor);
        return image;
    }
    void setcolor(vector<vector<int>>& image,int sr,int sc, int basecolor,int newColor)
    {
        if(basecolor == newColor)
        {
            return;
        }
        if(sr-1 >= 0 && image[sr-1][sc] == basecolor) //Up
        {
            image[sr-1][sc] = newColor;
            setcolor(image,sr-1,sc,basecolor,newColor); 
        }
        if(sr+1 < image.size() && image[sr+1][sc] == basecolor) //Down
        {
            image[sr+1][sc] = newColor;
            setcolor(image,sr+1,sc,basecolor,newColor); 
        }
        if(sc-1 >= 0 && image[sr][sc-1] == basecolor) //Left
        {
            image[sr][sc-1] = newColor;
            setcolor(image,sr,sc-1,basecolor,newColor); 
        }
        if(sc+1 < image[0].size() && image[sr][sc+1] == basecolor) //Right
        {
            image[sr][sc+1] = newColor;
            setcolor(image,sr,sc+1,basecolor,newColor); 
        }
    }
};
__________________________________________________________________________________________________
