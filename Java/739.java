__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        
    int[] stack = new int[temperatures.length];
    int top = -1;
    int[] ret = new int[temperatures.length];
    for(int i = 0; i < temperatures.length; i++) {
        while(top > -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            ret[idx] = i - idx;
        }
        stack[++top] = i;
    }
    return ret;
    }
}
__________________________________________________________________________________________________
sample 40220 kb submission
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Queue<int[]> queue = new PriorityQueue<>((s1,s2)->{return s1[0]-s2[0];});
        for(int i=0;i<T.length;i++){
            if(queue.size()>0){
                while(queue.size()>0){
                    if(queue.peek()[0]<T[i]){
                        int[] temp = queue.remove();
                        ans[temp[1]] = i-temp[1];
                    }
                    else{break;}
                }
            }
            if(i!=T.length-1){
                if(T[i]<T[i+1]){ans[i]=1;}
                else{
                    int[] element = {T[i],i};
                    queue.add(element);
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
