__________________________________________________________________________________________________
sample 0 ms submission
int compare(const void *a, const void *b)
{
    return *(*(int **)a) - *(*(int **)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = 0, iSum = 0;
    int *ipRet = NULL;
    int **ipNums = NULL;
    if(numsSize < 2)
    {
        *returnSize = 0;
        return NULL;
    }
    ipNums = malloc(numsSize * sizeof(int *));
    for(i = 0; i < numsSize; ++i)
        ipNums[i] = &nums[i];
    
    qsort(ipNums, numsSize, sizeof(int *), compare);

    i = 0, j = numsSize - 1;
    while(i != j)
    {
        iSum = *ipNums[i] + *ipNums[j];
        if(iSum < target)
        {
            ++i;
            continue;
        }
        else if(iSum == target)
        {
            *returnSize = 2;
            ipRet = malloc(*returnSize * sizeof(int));
            ipRet[0] = ipNums[i] - nums;
            ipRet[1] = ipNums[j] - nums;
            
            free(ipNums);
            return ipRet; 
        }

        --j;
    }

    *returnSize = 0;
    free(ipNums);
    return NULL;
}
__________________________________________________________________________________________________
sample 7296 kb submission
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
        int *pret=(int*)malloc(2*sizeof(int));
    //memset(pret,0);
    
    int i=0,j=0;
    int found=0;
    
    for(i=0;i<numsSize;i++)
    {
       for(j=i+1;j<numsSize;j++)
       {
       		if(nums[i]+nums[j]==target)
       		{
       	//		printf("Here %d %d\n",nums[i],nums[j]);
       			pret[0]=i;pret[1]=j;	
       			found=1;
				break;
			}
	   }
	   if(found) break;
    }
    return pret;

}
__________________________________________________________________________________________________
执行用时为 8 ms 的范例
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct hash_node {
    int id;            /* we'll use this field as the key */
    int index;
    UT_hash_handle hh; /* makes this structure hashable */
} hash_node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *two_nums = (int *)malloc(sizeof(int)*2);
    hash_node *hash_table = NULL, *hash_item1 = NULL, *hash_item2 = NULL;
    for (int i = 0; i < numsSize; i++) {
        // 查找哈希表中是否存在满足和为target的另一个值,若存在直接返回
        int other_id = target - *(nums+i);
        HASH_FIND_INT(hash_table, &other_id, hash_item1);
        if (hash_item1) {
            two_nums[0] = hash_item1->index;
            two_nums[1] = i;
            *returnSize = 2;
            return two_nums;
        }
        // 将本次遍历的值放入哈希表,value为数组下标,key为对应数值
        hash_item2 = (hash_node *)malloc(sizeof(hash_node));
        hash_item2->id = *(nums+i);
        hash_item2->index = i;
        HASH_ADD_INT(hash_table, id, hash_item2);
    }
    return two_nums;
}