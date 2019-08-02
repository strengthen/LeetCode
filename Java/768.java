__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
       public int maxChunksToSorted(int[] arr) {
        if(arr==null || arr.length==0) return 0;
        int[] data = new int[arr.length+1];
        data[1]=arr[0];
        int ans=1;
        for(int i=1; i<arr.length; i++){
           if(arr[i]>=data[ans]){
               data[++ans]=arr[i]; continue;
           }
           int top= data[ans--];
           while(ans>0 && arr[i]<data[ans]) ans--;
           data[++ans]=top;
        }
        return ans;
    }  
}
__________________________________________________________________________________________________
sample 37732 kb submission
class Solution {
    public int maxChunksToSorted(int[] arr) {
        
        int chunkCount = 0;

        int[] sortedArray = new int[arr.length];
        for (int i=0; i<arr.length; i++) {
            sortedArray[i] = arr[i];
        }

        Arrays.sort(sortedArray);

        int newPositions[] = new int[arr.length];

        for (int i=0; i<sortedArray.length; i++) {
            for (int j=0; i<arr.length; j++) {
                if (arr[j]==sortedArray[i]) {
                    newPositions[j] = i;
                    if (arr[j] == 0) {
                        arr[j] = Integer.MIN_VALUE;
                    } else {
                        arr[j] *= -1;
                    }
                    break;
                }
            }
        }


        for (int i=0; i<arr.length; i++) {
            if (arr[i] == Integer.MIN_VALUE) {
                arr[i] = 0;
            } else {
                arr[i] *= -1;
            }
        }




        int max = Integer.MIN_VALUE;
        for (int i=0; i<newPositions.length; i++) {
            if (newPositions[i] > max) {
                max = newPositions[i];
            }
            if (max == i) {
                chunkCount++;
            }
        }
        return chunkCount;
    }
}
__________________________________________________________________________________________________
