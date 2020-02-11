__________________________________________________________________________________________________
sample 4 ms submission
/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size > nums2Size){
        int* nums;
        int numsSize;
        nums = nums1;
        nums1 = nums2;
        nums2 = nums;
        numsSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = numsSize;
    }
    int start = 0;
    int end = nums1Size;
    int max_left = 0;
    int min_right = 0;
    double median = 0.0;
    while(start <= end){
        int x = (start + end) / 2;
        int y = (nums1Size + nums2Size + 1) / 2 - x;
        if(x > 0 && nums1[x - 1] > nums2[y]){
            end = x - 1;
        }
        else if(x < nums1Size && nums1[x] < nums2[y - 1]){
            start = x + 1;
        }
        else{
            if(x == 0){
                max_left = nums2[y - 1];
            }
            else if(y == 0){
                max_left = nums1[x - 1];
            }
            else {
                max_left = nums1[x - 1] > nums2[y - 1] ? nums1[x - 1] : nums2[y - 1];
            }

            if(((nums1Size + nums2Size) % 2) == 0){
                if(x == nums1Size){
                    min_right = nums2[y];
                }
                else if(y == nums2Size) {
                    min_right = nums1[x];
                }
                else {
                    min_right = nums1[x] < nums2[y] ? nums1[x] : nums2[y];
                }
                median = (double)(min_right + max_left) / 2.0;
                break;
                    //return median;
            }
            else {
                median = (double)max_left;
                break;
                //return median;
            }
        }
    }
    return median;
}

__________________________________________________________________________________________________
sample 8 ms submission


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
        if(nums1Size + nums2Size == 1){
		if(nums1Size) return *nums1;
		else          return *nums2;
    }
    
    int isOdd = (nums1Size + nums2Size) % 2;
    int ind_med = (nums1Size + nums2Size) / 2;
    int ind_cur = 0;
    int* p1	    = nums1;
    int* p2     = nums2;
    int pre     = 0;
    int cur     = 0;
    while(ind_cur <= ind_med && p1-nums1 < nums1Size && p2-nums2 < nums2Size){
        pre = cur;
        if(*p1 < *p2){
            cur = *p1;
            ++p1;
        }else{
            cur = *p2;
            ++p2;
        }
        ++ind_cur;
    }
    if(ind_cur == ind_med) pre = cur;
    if(ind_cur <= ind_med && p1-nums1 >= nums1Size){
    	if(ind_cur != ind_med)
            pre = *(p2 + ind_med - ind_cur - 1);
        cur = *(p2 + ind_med - ind_cur);
    }
	if(ind_cur <= ind_med && p2-nums2 >= nums2Size){
    	if(ind_cur != ind_med)
            pre = *(p1 + ind_med - ind_cur - 1);
        cur = *(p1 + ind_med - ind_cur);
    }
    
    if(isOdd){
    	return cur;
    }else{
    	return (double)(pre + cur) / 2.0;
    }
}

__________________________________________________________________________________________________
sample 12 ms submission


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size + nums2Size == 1){
		if(nums1Size) return *nums1;
		else          return *nums2;
    }
    
    int isOdd = (nums1Size + nums2Size) % 2;
    int ind_med = (nums1Size + nums2Size) / 2;
    int ind_cur = 0;
    int* p1	    = nums1;
    int* p2     = nums2;
    int pre     = 0;
    int cur     = 0;
    while(ind_cur <= ind_med && p1-nums1 < nums1Size && p2-nums2 < nums2Size){
        pre = cur;
        if(*p1 < *p2){
            cur = *p1;
            ++p1;
        }else{
            cur = *p2;
            ++p2;
        }
        ++ind_cur;
    }
    if(ind_cur == ind_med) pre = cur;
    if(ind_cur <= ind_med && p1-nums1 >= nums1Size){
    	if(ind_cur != ind_med)
            pre = *(p2 + ind_med - ind_cur - 1);
        cur = *(p2 + ind_med - ind_cur);
    }
	if(ind_cur <= ind_med && p2-nums2 >= nums2Size){
    	if(ind_cur != ind_med)
            pre = *(p1 + ind_med - ind_cur - 1);
        cur = *(p1 + ind_med - ind_cur);
    }
    
    if(isOdd){
    	return cur;
    }else{
    	return (double)(pre + cur) / 2.0;
    }
}

__________________________________________________________________________________________________
执行用时为 8 ms 的范例
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int len1, int* nums2, int len2, int* nums)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(i < len1 && j < len2)
	{
		if(nums1[i] < nums2[j])
			nums[k++] = nums1[i++]; 
		else
			nums[k++] = nums2[j++];
	}
	
	while(i < len1)
		nums[k++] = nums1[i++];
	
	while(j < len2)
		nums[k++] = nums2[j++];
}

double findMedian(int* nums1, int len1, int* nums2, int len2)
{
	int len = len1 + len2;
	double med;
	int* nums = (int *)malloc(sizeof(int)/sizeof(char) * len);
	
	merge(nums1, len1, nums2, len2, nums);
	
	if(len%2 == 1)
		med = nums[len/2];
	else
		med = (double)(nums[len/2-1] + nums[len/2]) / 2;
	
	free(nums);
	
	return med;
}



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size + nums2Size;
	double med;
	int* nums = (int *)malloc(sizeof(int)/sizeof(char) * len);
	
	merge(nums1, nums1Size, nums2, nums2Size, nums);
	
	if(len%2 == 1)
		med = nums[len/2];
	else
		med = (double)(nums[len/2-1] + nums[len/2]) / 2;
	
	free(nums);
	
	return med;
}

__________________________________________________________________________________________________
执行用时为 12 ms 的范例

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size;
    int i, j, z;
    double res = 0.0;
    int *a = NULL;
    size = nums1Size + nums2Size;
    a = (int *)malloc(size * sizeof(int));
    j = 0;
    z = 0;
    for (i = 0; i < size; i++)
    {
        if (z == nums2Size)
        {
            a[i] = nums1[j++];
        }
        else if (j == nums1Size)
        {
            a[i] = nums2[z++];
        }
        else if (nums1[j] < nums2[z])
        {
            a[i] = nums1[j++];
        }
        else if (nums1[j] > nums2[z])
        {
            a[i] = nums2[z++];
        }
        else
        {
            a[i] = nums1[j++];
        }
        //printf("%d\n", a[i]);
    }
    if (size % 2 == 1)
    {
        res = a[size / 2];
        //printf("a[%d / 2] = %d\n", size, a[size/2]);
    }
    else 
    {
        res = (a[size / 2] + a[size / 2 - 1]) / 2.0;
        //printf("a[%d / 2] + a[%d / 2 - 1] / 2.0 = %f", size, size, res);
    }
    free(a);
    return res;
}

__________________________________________________________________________________________________
执行用时为 16 ms 的范例
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int k = (nums1Size + nums2Size + 1) / 2;
	int is_odd = (nums1Size + nums2Size) % 2;
	double result = 0;
	int start1 = 0;
	int start2 = 0;
	int temp1, temp2;
	
	while (k > 1 && start1 < nums1Size && start2 < nums2Size) {
		temp1 = nums1Size - start1 - 1 < k / 2 - 1? nums1Size - start1 - 1 : k / 2 - 1;
		temp2 = nums2Size - start2 - 1 < k / 2 - 1? nums2Size - start2 - 1 : k / 2 - 1;
		if (nums1[temp1 + start1] < nums2[temp2 + start2]) {
			k -= temp1 + 1;
			start1 += temp1 + 1;
		}
		else {
			k -= temp2 + 1;
			start2 += temp2 + 1;
		}		
	}
	while (k > 1 && start1 < nums1Size) {
		start1 += k - 1;
		k = 1;
	}
	while (k > 1 && start2 < nums2Size) {
		start2 += k - 1;
		k = 1;
	}
	if (is_odd) {
		if (start1 < nums1Size && start2 < nums2Size) {
			result = nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
		}
		else if (start1 < nums1Size) result = nums1[start1];
		else result = nums2[start2];
	}
	else {
		if (start1 < nums1Size && start2 < nums2Size) {
			result = nums1[start1] < nums2[start2] ? nums1[start1++] : nums2[start2++];
		}
		else if (start1 < nums1Size) result = nums1[start1++];
		else result = nums2[start2++];

		if (start1 < nums1Size && start2 < nums2Size) {
			result += nums1[start1] < nums2[start2] ? nums1[start1++] : nums2[start2++];
		}
		else if (start1 < nums1Size) result += nums1[start1++];
		else result += nums2[start2++];

		result /= 2;
	}

	return result;
}