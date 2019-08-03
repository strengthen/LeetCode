__________________________________________________________________________________________________
sample 11 ms submission
class Solution {
    public int oddEvenJumps(int[] A) {
        int len = A.length, res = 1;
        int[] odd = new int[len];
        int[] even = new int[len];
        int[] sk  = new int[len];
        int ptr  =0;
        int[] sortI = new int[len];
        int min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        sortI[len-1]=len-1;
        for(int i=0;i<len;i++){
          odd[i]  = even[i] = -1;
          min = Math.min(A[i],min);  
          max = Math.max(A[i],max);  
        }
        int[] bucketcnt = new int[max-min+1];
        int[] st = new int[max-min+1];
        int[] reversest = new int[max-min+1];
        for(int a:A){
           bucketcnt[a-min]++; 
        }
        //odd 
        int curi = 0; 
        //Arrays.sort(sortI, (i1,i2)->Integer.compare(A[i1],A[i2]));
        //st=0;
        for(int i=0;i<max-min;){
           st[i+1] = st[i] + bucketcnt[i++];
        }
        for(int i=0;i<len;i++){
           sortI[st[A[i]-min]++] = i; 
        }
        odd[sortI[len-1]] = -1;
        sk[ptr++]=sortI[len-1];
        for(int i=len-2;i>=0;i--){
           curi = sortI[i]; 
           while(ptr!=0&&curi>sk[ptr-1]){
               ptr--;
           } 
           odd[curi] = ptr==0?-1:sk[ptr-1];    
           sk[ptr++]=sortI[i];
        }
        //even
        //sk.clear();
        ptr=0;
        //Arrays.sort(sortI, (i2,i1)->Integer.compare(A[i1],A[i2]));
        for(int i=0;i<len;i++){
           sortI[len-(st[A[i]-min]--)] = i; 
        }
        even[sortI[len-1]] = -1;
        sk[ptr++]=sortI[len-1];
        for(int i=len-2;i>=0;i--){
           curi = sortI[i]; 
           while(ptr!=0&&curi>sk[ptr-1]){
               ptr--;
           } 
           even[curi] = ptr==0?-1:sk[ptr-1];    
           sk[ptr++]=sortI[i];
        }
        odd[len-1]=len-1;
        even[len-1]=len-1;
        for(int i=len-2;i>=0;i--){
           if(even[i]!=-1) 
            even[i] = odd[even[i]]; 
           if(odd[i]!=-1&&(odd[i]=even[odd[i]])==len-1) 
               res++; 
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 39180 kb submission
class Solution {
    public int oddEvenJumps(int[] A) {
        // with stack;
        int n = A.length;
        int[][] pair = new int[n][2];
        for (int i = 0; i < n; i++) {
            pair[i] = new int[]{A[i], i};
        }
        
        Arrays.sort(pair, (p1, p2) -> p1[0] == p2[0] ? p1[1] - p2[1] : p1[0] - p2[0]);
        
        Stack<Integer> stack = new Stack<>();
        int[] higherIndex = new int[n];
        Arrays.fill(higherIndex, -1);
        
        // higher
        for (int i = 0; i < n; i++) {
            int val = pair[i][0];
            int index = pair[i][1];
            
            // System.out.print("," + Arrays.toString(pair[i]));
            while (!stack.isEmpty() && stack.peek() < index) {
                higherIndex[stack.pop()] = index;
            }
            
            stack.push(index);
        }
        // System.out.println("higher:"+ Arrays.toString(higherIndex));
        
        stack.clear();
        Arrays.sort(pair, (p1, p2) -> p1[0] == p2[0] ? p1[1] - p2[1] : p2[0] - p1[0]);
        
        // smaller
        int[] lowerIndex = new int[n];
        Arrays.fill(lowerIndex, -1);
        for (int i = 0; i < n; i++) {
            
            int val = pair[i][0];
            int index = pair[i][1];
            // System.out.print("," + val);
            while (!stack.isEmpty() && stack.peek() < index) {
                lowerIndex[stack.pop()] = index;
            }
            
            stack.push(index);
        }
        
        // System.out.println(Arrays.toString(higherIndex) + ": " + Arrays.toString(lowerIndex));
        boolean[] odd = new boolean[n];
        boolean[] even = new boolean[n];
        // last element should be done.
        odd[n - 1] = true;
        even[n - 1] = true;
        int totalValidJump = 1;
        
        for (int i = n - 2; i >= 0; i--) {
            int lower = lowerIndex[i];
            int higher = higherIndex[i];
            if (lower != -1) {
                even[i] = odd[lower];
            }
            if (higher != -1) {
                odd[i] = even[higher];
            }
            
            if (odd[i]) {
                totalValidJump++;
            }
        }
        
        return totalValidJump;
    }
}
__________________________________________________________________________________________________
