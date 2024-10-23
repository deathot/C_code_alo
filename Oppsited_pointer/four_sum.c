/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* c, const void* d) {
    return *(int*)c - *(int*)d;
}

int** fourSum(int* nums, int n, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, n, sizeof(int), cmp);
    *returnColumnSizes = malloc(n * n * sizeof(int));
    int** ans = malloc(n * n * sizeof(int));
    int m = 0;

    for(int i = 0; i < n - 3; i++) {
        long x = nums[i];
        if(i > 0 && nums[i - 1] == x) continue;
        if(x + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        if(x + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

        for(int j = i + 1; j < n - 2; j++) {
            int y = nums[j];
            if(j > i + 1 && y == nums[j - 1]) continue;
            if(x + y + nums[j + 1] +nums[j + 2] > target) break;
            if(x + y + nums[n-1] + nums[n-2] < target) continue;

            int a = j + 1;
            int b = n - 1;

            while(a < b) {
                int s = x + y + nums[a] + nums[b];

                if(s < target) {
                    a++;
                } else if(s > target) {
                    b--;
                } else {
                    int* tuple = malloc(4 * sizeof(int));
                    tuple[0] = x;
                    tuple[1] = y;
                    tuple[2] = nums[a];
                    tuple[3] = nums[b];
                    ans[m] = tuple;
                    (*returnColumnSizes)[m++] = 4;
                    for(a++; a < b && nums[a] == nums[a - 1]; a++);
                    for(b--; a < b && nums[b] == nums[b + 1]; b--);
                }
            }

        }
        
    }
    *returnSize = m;
    return ans;
}
