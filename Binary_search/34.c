//
//  34.c
//  C_code_alo
//
//  Created by deathot on 10/30/24.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int func(int* nums, int n, int target) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(nums[m] >= target) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return l;
}

int* searchRange(int* nums, int n, int target, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    int fir = func(nums, n, target);
    if(fir >= n || nums[fir] != target) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int las = func(nums, n, target + 1) - 1;
    ans[0] = fir;
    ans[1] = las;

    return ans;

}
