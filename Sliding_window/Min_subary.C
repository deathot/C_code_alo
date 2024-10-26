//
//  Min_subary.C
//  C_code_alo
//
//  Created by deathot on 10/26/24.
//

#define Min(a, b) ((a) < (b) ? (a) : (b))
int minSubArrayLen(int target, int* nums, int n) {
    int ans = n + 1;
    int s = 0;
    int left = 0;

    for(int i = 0; i < n; i++) {
        s += nums[i];
        while(s - nums[left] >= target) {
            s -= nums[left];
            left += 1;
        }

        if(s >= target) {
            ans = Min(ans, i - left + 1);
        }
    }
    return ans <= n ? ans : 0;
}
