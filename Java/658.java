__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        return findClosestElements(arr, k, x, 0, arr.length - k);
    }

    private List<Integer> findClosestElements(int[] arr, int k, int x, int left, int right) {
        if (left == right) {
            List<Integer> result = new ArrayList<Integer>();
            for (int i = left; i < left + k; i++)
                result.add(arr[i]);
            return result;
        }

        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x)
            return findClosestElements(arr, k, x, mid + 1, right);

        return findClosestElements(arr, k, x, left, mid);
    }
}
__________________________________________________________________________________________________
sample 37284 kb submission
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int low = 0; 
        int high = arr.length - k; 
        while(low < high){
            int mid = (low + high) / 2; 
            if(x - arr[mid] > arr[mid + k] - x){
                low = mid + 1; 
            }
            else{
                high = mid; 
            }
        }
        return Arrays.stream(arr, low, low + k).boxed().collect(Collectors.toList());         
    }
}
__________________________________________________________________________________________________
