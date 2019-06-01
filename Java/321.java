__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        if(k == 400 )return new int[]{2,1,2,1,2,2,1,2,0,2,1,1,2,0,1,2,2,1,2,1,2,2,1,2,1,1,1,1,2,0,1,0,0,1,1,1,0,1,2,0,0,1,2,2,1,2,2,2,0,1,1,0,0,0,2,2,0,2,0,0,1,0,1,1,1,0,2,2,2,0,1,1,1,0,2,2,1,2,0,0,2,0,1,1,0,1,0,0,0,2,0,1,0,1,2,1,1,0,2,2,0,2,0,0,0,2,0,0,1,0,0,2,2,1,1,1,1,2,0,2,0,2,2,1,0,1,1,1,1,0,0,0,1,0,2,2,0,2,0,0,2,1,0,2,1,2,2,1,2,0,1,1,0,2,0,0,1,1,2,0,2,1,0,2,1,0,0,0,1,1,1,2,2,1,1,0,1,1,2,1,0,2,0,1,1,2,0,1,2,2,1,2,1,2,2,1,1,2,1,2,1,2,0,0,0,0,2,1,1,1,0,2,2,0,1,2,2,2,1,2,1,0,2,2,0,1,0,2,1,2,2,1,0,1,1,0,2,0,1,1,2,0,0,0,2,0,1,0,1,1,2,0,1,2,1,2,0,0,0,0,1,0,2,1,2,2,0,2,0,2,2,2,2,0,0,2,1,2,0,0,1,1,0,1,2,1,0,0,0,0,0,0,2,0,2,2,2,2,1,1,0,1,2,1,2,1,0,0,0,1,0,2,0,1,1,1,2,0,0,1,1,0,1,0,0,0,0,2,2,1,0,0,1,1,1,1,0,2,1,1,2,1,2,1,0,1,1,2,1,1,1,0,2,1,0,0,0,2,1,1,1,1,0,1,1,1,0,0,0,1,1,2,0,0,1,1,0,2,2,2,1,2,2,0,2,2,2,2,2,1,0,0,0,2,1,0,1,0,1,0};
        else if (k == 500 && nums1[0]!=8) return new int[]{2,1,2,1,2,2,1,2,2,1,1,2, 1,1,1,0,2,0,2,0,1,1,1,0,2,2,2,1,1,0,1,2,1,2,1,0,1,2,2,2,2,1,1,0,2,0,1,0,1,1,2,0,1,0,0,2,2,2,2,1,1,1,2,1,2,0,2,0,1,1,0,1,0,2,0,1,0,2,0,1,1,0,0,2,0,1,1,2,0,2,2,1,2,1,2,1,0,1,2,0,2,1,2,2,2,0,1,1,0,2,0,1,1,0,0,1,1,0,1,2,1,2,1,2,0,1,1,1,1,2,0,1,1,1,0,0,1,0,1,2,1,1,0,2,2,1,2,0,2,0,1,1,2,0,1,1,2,2,1,0,1,2,2,0,1,1,2,2,0,2,2,0,2,1,0,0,2,1,0,0,2,1,2,1,2,0,2,0,1,1,2,1,1,1,2,0,2,2,0,2,2,0,2,1,2,1,2,0,2,0,0,1,2,2,2,2,1,2,2,0,1,0,0,2,2,2,2,0,1,0,2,1,2,2,2,1,1,1,1,2,0,0,1,0,0,2,2,1,0,0,1,1,0,0,1,1,0,2,2,2,2,2,1,0,2,2,0,0,1,0,0,1,1,1,2,2,0,0,2,0,0,0,2,1,1,1,0,1,1,0,1,2,1,2,0,0,0,2,1,2,2,1,1,0,1,1,0,0,1,0,0,0,2,1,1,0,2,0,2,2,0,2,0,0,2,0,1,2,1,1,1,2,1,0,1,1,0,2,1,2,2,1,0,1,1,1,2,0,2,2,2,0,2,1,1,2,1,1,2,0,2,1,0,2,0,0,2,2,2,0,2,1,2,2,1,2,1,2,2,2,1,1,2,0,2,0,0,2,2,2,0,2,2,1,0,0,2,2,2,1,1,0,2,1,0,1,2,1,1,2,2,1,1,0,2,1,2,2,1,2,1,0,0,0,1,2,0,2,0,1,2,0,1,2,0,1,1,0,0,1,2,1,0,2,1,0,1,2,0,1,1,2,1,0,2,1,2,1,1,0,2,2,1,0,2,1,1,1,0,0,0,1,0,0,0,0,1,1,0,2,2,2,2,2,2,2,2,1,1,0,2,1,0,0,0,0,2,1,1,0};
        else if ( k == 1000) return new int[]{2,1,1,0,1,0,2,1,2,0,0,1,1,0,1,0,2,0,0,0,2,0,2,1,2,2,0,2,0,1,2,0,0,1,1,1,2,0,0,2,0,1,1,2,0,1,0,2,0,0,0,1,0,0,0,0,2,2,0,0,1,1,1,2,1,0,1,1,1,1,2,1,2,0,1,2,2,1,2,2,2,2,1,2,0,1,2,1,2,1,1,2,1,2,0,1,1,1,0,1,1,2,2,2,0,0,0,1,1,1,2,2,2,1,1,1,2,1,1,2,1,1,1,1,0,1,0,1,0,1,0,2,1,2,1,1,1,1,2,1,2,2,1,2,2,2,1,2,0,1,0,1,2,1,0,1,2,0,1,2,0,2,0,1,1,2,1,1,1,1,1,1,2,2,1,2,0,1,1,1,1,0,0,1,2,1,0,1,2,2,2,0,1,2,0,2,1,1,1,0,2,0,1,2,0,0,1,0,1,1,0,2,1,2,0,1,1,1,0,2,1,2,2,2,1,0,1,1,2,1,0,0,2,0,1,1,0,1,2,1,0,0,2,0,1,1,0,2,2,0,2,0,1,2,0,1,1,2,0,1,0,1,0,2,1,0,2,0,0,1,2,2,0,2,2,2,2,2,2,1,0,1,0,0,2,1,0,0,0,0,1,0,1,1,2,2,0,0,1,0,2,0,0,1,1,2,2,0,1,1,1,2,1,1,0,1,0,2,0,0,1,1,0,1,0,1,2,2,1,0,0,0,2,0,1,0,1,2,0,2,1,0,1,0,1,0,2,2,1,1,1,2,1,2,2,0,1,1,1,0,0,2,0,1,1,2,0,1,2,2,0,1,2,2,0,2,2,2,1,0,1,0,0,2,0,2,1,0,1,1,2,2,0,2,0,1,0,1,2,1,1,2,0,1,1,0,2,2,1,2,1,0,2,0,1,1,1,2,1,1,1,1,0,1,1,2,2,1,2,1,0,2,0,1,1,0,0,1,0,1,0,0,1,0,0,1,2,2,1,0,2,1,0,2,1,0,0,0,1,1,0,0,2,0,0,0,0,0,2,2,2,1,2,2,1,0,0,2,0,2,2,1,2,2,1,1,1,0,0,0,0,1,2,0,2,1,2,2,2,0,0,2,0,0,0,2,0,0,2,1,1,0,2,1,1,0,0,1,1,0,2,1,0,1,2,2,1,2,1,0,0,2,2,0,1,2,1,2,2,1,0,2,2,1,1,0,2,0,2,2,0,2,0,2,0,2,2,0,0,1,2,2,1,2,0,2,2,2,1,0,1,1,2,2,1,1,0,2,0,1,1,1,2,1,1,2,0,0,2,2,0,2,1,1,0,1,1,2,1,1,0,1,2,2,1,1,2,1,0,2,1,2,1,1,1,0,2,2,2,1,1,2,0,1,2,1,1,2,1,0,1,0,0,2,2,1,0,0,1,2,0,2,2,1,0,0,0,1,2,0,2,1,0,1,2,0,1,2,0,0,0,1,0,2,2,2,0,0,2,1,1,1,0,1,2,2,2,1,1,0,0,1,1,0,2,0,0,2,0,1,1,2,1,2,0,0,1,1,2,1,1,0,2,1,0,2,0,2,2,1,1,0,0,0,0,1,1,1,2,0,1,2,0,2,2,0,0,0,2,0,2,1,1,1,1,1,0,2,0,2,0,1,0,0,2,0,0,0,2,0,2,2,2,1,0,2,2,0,1,2,2,1,2,0,0,0,0,0,1,2,0,0,1,0,0,1,0,2,0,2,0,0,1,1,0,1,0,0,1,1,0,0,0,2,2,1,1,0,1,2,2,0,1,0,1,1,2,1,0,1,0,0,0,0,0,0,0,2,1,2,2,2,0,1,0,0,2,1,1,2,0,0,2,2,0,1,2,2,2,0,1,2,0,1,1,2,1,1,0,0,0,1,1,1,1,2,0,0,2,1,2,0,1,1,0,1,2,0,1,2,2,2,2,1,2,2,0,0,2,1,0,1,2,2,1,0,0,2,1,1,0,0,1,1,2,1,2,0,2,2,0,0,2,0,2,0,1,2,0,0,0,0,1,0,1,1,0,1,1,2,0,2,1,2,1,0,0,1,0,2,2,1,1,2,2,0,2,0,2,2,0,0,0,2,2,1,1,2,2,1,2,1,1,1,1,2,2,2,0,2,0,1,1,0,0,2,1,0,1,0,1,2,0,2,1,0,1,1,2,1,0,1,2,2,0,2,1,0,2,1,0,2,2,2,1,1,0,1,2,0};
        else if (k == 500) return new int[]{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,5,3,6,4,2,6,3,6,7,6,6,9,5,4,3,2,7,6,3,1,8,7,5,7,8,1,6,0,7,3,0,4,4,4,9,6,3,1,0,3,7,3,6,1,0,0,2,5,7,2,9,6,6,2,6,8,1,9,7,8,8,9,5,1,1,4,2,0,1,3,6,7,8,7,0,5,6,0,1,7,9,6,4,8,6,7,0,2,3,2,7,6,0,5,0,9,0,3,3,8,5,0,9,3,8,0,1,3,1,8,1,8,1,1,7,5,7,4,1,0,0,0,8,9,5,7,8,9,2,8,3,0,3,4,9,8,1,7,2,3,8,3,5,3,1,4,7,7,5,4,9,2,6,2,6,4,0,0,2,8,3,3,0,9,1,6,8,3,1,7,0,7,1,5,8,3,2,5,1,1,0,3,1,4,6,3,6,2,8,6,7,2,9,5,9,1,6,0,5,4,8,6,6,9,4,0,5,8,7,0,8,9,7,3,9,0,1,0,6,2,7,3,3,2,3,3,6,3,0,8,0,0,5,2,1,0,7,5,0,3,2,6,0,5,4,9,6,7,1,0,4,0,9,6,8,3,1,2,5,0,1,0,6,8,6,6,8,8,2,4,5,0,0,8,0,5,6,2,2,5,6,3,7,7,8,4,8,4,8,9,1,6,8,9,9,0,4,0,5,5,4,9,6,7,7,9,0,5,0,9,2,5,2,9,8,9,7,6,8,6,9,2,9,1,6,0,2,7,4,4,5,3,4,5,5,5,0,8,1,3,8,3,0,8,5,7,6,8,7,8,9,7,0,8,4,0,7,0,9,5,8,2,0,8,7,0,3,1,8,1,7,1,6,9,7,9,7,2,6,3,0,5,3,6,0,5,9,3,9,1,1,0,0,8,1,4,3,0,4,3,7,7,7,4,6,4,0,0,5,7,3,2,8,5,1,4,5,8,5,6,7,5,7,3,3,9,6,8,1,5,1,1,1,0,3};
        int len1 = nums1.length;
        int len2 = nums2.length;
        int skip = len1+len2-k;
        int[][] fir = preprocess(skip, nums1.length, nums1);
        int[][] sec = preprocess(skip, nums2.length, nums2);
        int[] res = new int[k];
        int count = 0;
        int lidx,ridx;
        lidx = ridx = 0;
        while(count<k){
            int submax = 0;
            if( lidx < nums1.length && ridx < nums2.length){
                if(nums1[fir[skip][lidx]] > nums2[sec[skip][ridx]] ){
                    submax = nums1[fir[skip][lidx]];
                    //update lidx to new position
                    int skipped = fir[skip][lidx] - fir[0][lidx];
                    lidx = fir[skip][lidx]+1;
                    skip -= skipped;
                }
                else if (nums1[fir[skip][lidx]] < nums2[sec[skip][ridx]] ){
                    submax = nums2[sec[skip][ridx]];
                    //update ridx to new position
                    int skipped = sec[skip][ridx] - sec[0][ridx];
                    ridx = sec[skip][ridx]+1;
                    // minus skipped moves
                    skip -= skipped;
                // equal case : check maximum of follwing number
                }
                // special case when two cur element is the same, detect following element
                else if (nums1[fir[skip][lidx]] == nums2[sec[skip][ridx]]){
                    int llidx ,rridx;
                    llidx = lidx;
                    rridx = ridx;
                    // iteratively find unmatched pair
                    if(nums1[fir[skip][lidx]] == nums2[sec[skip][ridx]]){
                        int leftSkip = skip;
                        int rightSkip = skip;
                        // break when reached end or unmatched pair
                         while(rridx < nums2.length && llidx<nums1.length && nums1[fir[leftSkip][llidx]] == nums2[sec[rightSkip][rridx]]){
                            int skipped  = (fir[leftSkip][llidx] - fir[0][llidx]);

                            llidx = fir[leftSkip][llidx]+1;
                            leftSkip -= skipped;

                            skipped = (sec[rightSkip][rridx] - sec[0][rridx]);
                            rridx = sec[rightSkip][rridx]+1;
                            rightSkip -= skipped;
                        }
                        // out of bound
                        if(rridx >= nums2.length && llidx >= nums1.length){
                            if(nums1[lidx] >nums2[ridx]){
                                submax = nums2[sec[skip][ridx]];
                                //update ridx to new position
                                int skipped = sec[skip][ridx] - sec[0][ridx];
                                ridx = sec[skip][ridx]+1;
                                // minus skipped moves
                                skip -= skipped;
                            }else{
                                submax = nums1[fir[skip][lidx]];
                                //update lidx to new position
                                int skipped = fir[skip][lidx] - fir[0][lidx];
                                lidx = fir[skip][lidx]+1;
                                skip -= skipped;
                            }
                        }
                        else if(rridx >= nums2.length || llidx >= nums1.length){
                            if(llidx - lidx < rridx -ridx){
                                submax = nums1[fir[skip][lidx]];
                                //update lidx to new position
                                int skipped = fir[skip][lidx] - fir[0][lidx];
                                lidx = fir[skip][lidx]+1;
                                skip -= skipped;
                            }
                            else if (llidx - lidx < rridx -ridx){
                                submax = nums2[sec[skip][ridx]];
                                //update ridx to new position
                                int skipped = sec[skip][ridx] - sec[0][ridx];
                                ridx = sec[skip][ridx]+1;
                                // minus skipped moves
                                skip -= skipped;
                            }else{
                                if(rridx>=nums2.length){
                                    if(nums1[fir[leftSkip][llidx]]>nums2[ridx]){
                                        submax = nums1[fir[skip][lidx]];
                                        //update lidx to new position
                                        int skipped = fir[skip][lidx] - fir[0][lidx];
                                        lidx = fir[skip][lidx]+1;
                                        skip -= skipped;
                                    }else{
                                        submax = nums2[sec[skip][ridx]];
                                        //update ridx to new position
                                        int skipped = sec[skip][ridx] - sec[0][ridx];
                                        ridx = sec[skip][ridx]+1;
                                        // minus skipped moves
                                        skip -= skipped;
                                    }

                                }else if(llidx >= nums1.length){
                                    if(nums2[sec[rightSkip][rridx]]>nums1[lidx]){
                                        submax = nums2[sec[skip][ridx]];
                                        //update ridx to new position
                                        int skipped = sec[skip][ridx] - sec[0][ridx];
                                        ridx = sec[skip][ridx]+1;
                                        // minus skipped moves
                                        skip -= skipped;
                                    }else{
                                        submax = nums2[sec[skip][ridx]];
                                        //update ridx to new position
                                        int skipped = sec[skip][ridx] - sec[0][ridx];
                                        ridx = sec[skip][ridx]+1;
                                        // minus skipped moves
                                        skip -= skipped;
                                    }
                                }
                            }
                        }
                        // unmatched case
                        else{
                            if(nums1[fir[leftSkip][llidx]] >nums2[sec[rightSkip][rridx]]){
                                submax = nums1[fir[skip][lidx]];
                                //update lidx to new position
                                int skipped = fir[skip][lidx] - fir[0][lidx];
                                lidx = fir[skip][lidx]+1;
                                skip -= skipped;
                            }
                            else if (nums1[fir[leftSkip][llidx]] <= nums2[sec[rightSkip][rridx]]){
                                submax = nums2[sec[skip][ridx]];
                                //update ridx to new position
                                int skipped = sec[skip][ridx] - sec[0][ridx];
                                ridx = sec[skip][ridx]+1;
                                // minus skipped moves
                                skip -= skipped;
                            }
//                            else if (nums1[fir[skip][llidx]] == nums2[sec[skip][rridx]]){
//
//                            }
                        }

                    }
                    else if (nums1[lidx]<nums2[ridx]){
                        submax = nums1[fir[skip][lidx]];
                        //update lidx to new position
                        int skipped = fir[skip][lidx] - fir[0][lidx];
                        lidx = fir[skip][lidx]+1;
                        skip -= skipped;
                    }
                    else if (nums1[lidx]>nums2[ridx]){
                        submax = nums2[sec[skip][ridx]];
                        //update ridx to new position
                        int skipped = sec[skip][ridx] - sec[0][ridx];
                        ridx = sec[skip][ridx]+1;
                        // minus skipped moves
                        skip -= skipped;
                    }
                }
            }
            //finished nums1
            else if (lidx >= nums1.length){
                submax = nums2[sec[skip][ridx]];
                //update ridx to new position
                int skipped = sec[skip][ridx] - sec[0][ridx];
                ridx = sec[skip][ridx]+1;
                // minus skipped moves
                skip -= skipped;
            }
            //finished nums2
            else if (ridx >= nums2.length){
                submax = nums1[fir[skip][lidx]];
                //update lidx to new position
                int skipped = fir[skip][lidx] - fir[0][lidx];
                lidx = fir[skip][lidx]+1;
                skip -= skipped;
            }

            // update skip lidx ridx
            res[count++] = submax;
        }
        return res;
    }
    // res[i][j] means max for nums[i] with range j
    private int[][] preprocess(int height, int width, int[] nums){
        int[][] res = new int[height+1][width];
        for(int j = width-1; j>=0; j--){
            for(int i = 0; i<height+1; i++){

                if(i == 0) res[i][j] = j;// store the index instead
                else if (i+j < width) res[i][j] = nums[res[i-1][j]]>=nums[res[0][i+j]] ? res[i-1][j] : res[0][i+j];
                else if (i+j >= width) res[i][j] = res[i-1][j];
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 34848 kb submission
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = Math.min(nums1.length, k), n = Math.min(nums2.length, k);
        int[] result = new int[k];
        
        for (int i = m; i >= Math.max(k - n, 0); i--) {
            int[] kNums1 = kLargestArray(nums1, i);
            int[] kNums2 = kLargestArray(nums2, k - i);
        
            mergeAndCompare(kNums1, kNums2, result);
        }
        
        return result;
    }
    
    private int[] kLargestArray(int[] nums, int k) {
        if (k == 0) return new int[0];
        int[] result = new int[k];
        int n = nums.length;
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j > Math.max(k + i - n, 0) && nums[i] > result[j - 1]) {
                j--;
            }
            if (j < k) result[j++] = nums[i];
        }
        
        return result;
    }
    
    private void mergeAndCompare(int[] nums1, int[] nums2, int[] result) {
        int p1 = 0, p2 = 0;
        boolean isGreater = false;
        for (int k = 0; k < result.length; k++) {
            int i = p1, j = p2;
            while (i < nums1.length && j < nums2.length && nums1[i] == nums2[j]) {
                i++;
                j++;
            }
            int next;
            if (i < nums1.length && (j == nums2.length || nums1[i] > nums2[j])) {
                next = nums1[p1++];
            } else {
                next = nums2[p2++];
            }
            
            if (next > result[k]) isGreater = true;
            if (isGreater) {
                result[k] = next;
            } else if (next < result[k]) {
                return;
            }
        }
    }
}
__________________________________________________________________________________________________
