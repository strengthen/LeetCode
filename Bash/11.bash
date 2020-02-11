__________________________________________________________________________________________________
sample 4 ms submission
int maxArea(int* height, int heightSize) {
    int front = 0;
    int tail = heightSize - 1;
    int maxSize = 0;
    int currentSize;
    while(front < tail) {
        currentSize =  height[front] < height[tail] ? (tail - front) * height[front] : (tail - front) * height[tail];
        if (maxSize < currentSize)
            maxSize = currentSize;
        if (height[front] < height[tail])
            front++;
        else 
            tail--;
    }
    return maxSize;
}
__________________________________________________________________________________________________
sample 8 ms submission

#define min(x,y)         (x < y?x:y)
int maxArea(int* height, int heightSize){
    int answer = 0;
    int l = 0, r = heightSize;
    while(l < r){
        if(min(height[l], height[r-1]) * (r - l - 1) > answer){
            answer = min(height[l], height[r-1]) * (r - l - 1);
        }
        if(height[l] > height[r-1])
            r--;
        else
            l++;
    }
    return answer;
}

__________________________________________________________________________________________________
sample 7492 kb submission
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int maxArea(int* height, int heightSize) {
    
    int start = 0;
    int end = heightSize - 1; 
    int maxVolume = 0;
    if (heightSize <= 1)
    {
        return 0;
    }
    while (start < end)
    {
        int yoyoheight = min(height[start], height[end]);
        int width = end - start;
        int volume = yoyoheight*width;
        if (volume >= maxVolume)
        {
            maxVolume = volume;
        }
        
        if(yoyoheight == height[start])
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return maxVolume;
    
}
————————————————————————————————————————————————————————————————
sample 7500 kb submission
int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int maxArea(int* height, int heightSize) {
    int w, h, left = 0, right = heightSize - 1;
    int max = 0;
    
    while(left < right) {
        w = right - left;
        h = height[right] > height[left] ? height[left] : height[right];
        if (w*h > max) {
            max = w*h;
        }
        if (height[left] > height[right]) {
            right--;
        } else {
            left++;
        }
    }
    return max;
}
