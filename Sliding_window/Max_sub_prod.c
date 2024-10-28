//
//  Min_sub_prod.c
//  C_code_alo
//
//  Created by deathot on 10/28/24.
//
int numSubarrayProductLessThanK(int* nums, int n, int k) {
    
    int left = 0;
    int ans = 0;
    int prod = 1;

    if(k <= 1) return 0;

    for(int i = 0; i < n; i++) {
        prod *= nums[i];

        while(prod >= k) {
            prod /= nums[left];
            left += 1;
        }
        ans += i - left + 1;
    }
    return ans;
}

