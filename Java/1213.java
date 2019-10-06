__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int[] arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        int p1 = 0, p2 = 0, p3 = 0;
        List<Integer> re = new ArrayList<>();
        while(p1 < arr1.length && p2 < arr2.length && p3 < arr3.length) {
            int val = Math.min(arr1[p1], Math.min(arr2[p2], arr3[p3]));
            if(val == arr1[p1] && val == arr2[p2] && val == arr3[p3]) {
                re.add(val); p1++; p2++; p3++;
            }
            else if(val == arr1[p1]) p1++;
            else if(val == arr2[p2]) p2++;
            else p3++;
        }
        int[] r = new int[re.size()];
        for(int i = 0; i < r.length; i++) r[i] = re.get(i);
        return r;
    }
}
__________________________________________________________________________________________________
3ms

class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
     ArrayList<Integer> list =  new ArrayList<Integer>();   
        int i=0,j=0,k=0;
        
        while(i<arr1.length && j<arr2.length && k < arr3.length){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                list.add(arr1[i]);
                ++i;
                ++j;
                ++k;
            }else{
                int min=Math.min(arr1[i],Math.min(arr2[j],arr3[k]));
                if(arr1[i]==min)
                    ++i;
                else if(arr2[j]==min)
                    ++j;
                else
                    ++k;
            }
        }
        
        return list;
    }
}
__________________________________________________________________________________________________
sample 36 ms submission
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        int[][] arr = new int[][]{arr1, arr2, arr3};
        int[] i = {0, 0, 0};
        List<Integer> res = new ArrayList<>();
        while(isValidIndex(i, arr)) {
            int max = arr[0][i[0]] + 1;
            if(isTheSame(i, arr)) {
                res.add(arr1[i[0]]);
            } else {
                max = findMax(i, arr);
            }
            incToMax(i, arr, max);
        }

        return res.stream().mapToInt(x -> x).toArray();
    }

    private boolean isValidIndex(int[] i, int[][] arr) {
        for(int j = 0; j < i.length; j++) {
            if(i[j] >= arr[j].length) {
                return false;
            }
        }
        return true;
    }

    private boolean isTheSame(int[] i, int[][] arr) {
        for(int j = 1; j < i.length; j++) {
            if(arr[0][i[0]] != arr[j][i[j]]) {
                return false;
            }
        }

        return true;
    }

    private int findMax(int[] i, int[][] arr) {
        int max = -1;
        for(int j = 0; j < i.length; j++) {
            max = Math.max(max, arr[j][i[j]]);
        }
        return max;
    }

    private void incToMax(int[] i, int[][] arr, int max) {
        for(int j = 0; j < i.length; j++) {
            while(i[j] < arr[j].length && arr[j][i[j]] < max) {
                i[j]++;
            }
        }
    }
}
