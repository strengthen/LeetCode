__________________________________________________________________________________________________
sample 184 ms submission
class Solution {
    Random r;
    double radius, x_center, y_center;
    public Solution(double radius, double x_center, double y_center) {
        this.r = new Random();
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    public double[] randPoint() {
        while (true) {
            int temp1 = r.nextInt(20000);
            int temp2 = r.nextInt(20000);
            double x = temp1 > 10000? ((temp1 - 10000)/(double)(10000)) * radius + x_center : (-temp1/(double)(10000)) * radius + x_center;
            double y = temp2 > 10000? ((temp2 - 10000)/(double)(10000)) * radius + y_center : (-temp2/(double)(10000)) * radius + y_center;
            if (Math.sqrt(Math.pow((x - x_center), 2) + Math.pow((y - y_center), 2)) <= radius) {
                return new double[]{x, y}; 
            }
        }     
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
__________________________________________________________________________________________________
sample 55020 kb submission
class Solution {
    // 参考：https://zhanghuimeng.github.io/post/leetcode-478-generate-random-point-in-a-circle/
    // 中文看着就是方便。。。
    // 为什么我不能想到拒绝采样呢？？？
    // 极坐标法很神奇，但涉及数学推导，感觉不适合面试。。。

    private double radius;
    private double x_center;
    private double y_center;
    
    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    // 方法一：拒绝采样
    // 想象一个边长为 2*radius 的正方形刚好把圆形包住
    // 然后生成这个正方形内的随机点，若该随机点也落在圆形中，就返回这个点，否则重新生成随机点
    public double[] randPoint() {
        while ( true ) {
            // public static double random()
            // Returns a double value with a positive sign, greater than or equal to 0.0 and less than 1.0.
            // 但我实际上想要的是 [0, 1] 内的随机数，不是 [0, 1)，但大家都这么用就懒得抠细节了
            // 假设正方形在 x>0 & y>0 象限，即中心在 (radius, radius)，边长为 2*radius
            double x = Math.random()*radius*2;
            double y = Math.random()*radius*2;
            // 将正方形的中心移动至 (0, 0)
            x -= radius;
            y -= radius;
            // 检测点 (x, y) 是否在以 radius 为半径 (0, 0) 为圆心的圆里面
            if ( (x*x+y*y) <= (radius*radius) ) {
                // 在这个圆里面，返回 (x, y)
                // 记得把这个点映射至以 radius 为半径 (x_center, y_center) 为圆心的圆里面
                return new double[] {x + x_center, y + y_center};
            }
        }
    }
    
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
__________________________________________________________________________________________________
