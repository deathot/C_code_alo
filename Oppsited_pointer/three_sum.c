//
//  three_sum.c
//  C_code_alo
//
//  Created by deathot on 10/20/24.
//

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
        return *(int*)a - *(int*)b;
    }

int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {

    // sort for nums
    qsort(nums, n, sizeof(int), cmp);
    
    // allcoate memory for ans
    int** ans = malloc(n * n * sizeof(int));
    
    // allcoate mem
    *returnColumnSizes = malloc(n * n * sizeof(int));
    int m = 0;
    for (int i = 0; i < n-2; i++) {

        int x = nums[i];
        if (i > 0 && x == nums[i - 1]) continue;
        if (x + nums[i + 1]+ nums[i + 2] > 0) break;
        if (x + nums[n - 1] + nums[n - 2] < 0) continue;

        int j = i + 1, k = n - 1;
        while (j < k) {
            int s = x + nums[j] + nums[k];
            
            if (s > 0) {
                k--;
            } else if (s < 0) {
                j++;
            } else {
                
                // init tuple to store
                int* tuple = malloc(3 * sizeof(int));
                tuple[0] = x;
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[m] = tuple;
                
                // return every subtuple size in tuple which size = 3, and m += 1
                (*returnColumnSizes)[m++] = 3;

                for (j++; j < k && nums[j] == nums[j - 1]; j++);
                for (k--; j < k && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    *returnSize = m;
    return ans;

}

/*
    nums.sort();
    int n = len(nums);
    char *ans = [];

    for(i = 0; i < n-2; i++) {
        x = nums[i];
        if i > 0 && nums[i - 1] == x {
            continue
        }
        
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int s = x + nums[j] + nums[k];
            
            if s < 0 {
                j += 1;
            } elif {
                s > 0 {
                    k -= 1;
                }
            else {
                ans.append([x, nums[j], nums[k]])
                j += 1;
                while(nums[j - 1] == nums[j]) {
                    j += 1;
                }
                k -= 1;
                while(nums[k + 1] == nums[k]) {
                    k -= 1;
                }
            }
            }
        }
    }
    return ans
*/

