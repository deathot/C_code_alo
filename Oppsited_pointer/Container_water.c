//
//  Container_water.c
//  C_code_alo
//
//  Created by deathot on 10/23/24.
//
#define Min(a, b) ((b) < (a) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int n) {
    int left = 0;
    int right = n - 1;
    int ans = 0;

    while(left < right) {
        int area = Min(height[left], height[right]) * (right - left);
        ans = Max(area, ans);
        // if(height[left] < height[right]) {
        //     left += 1;
        // }
        // else {
        //     right -= 1;
        // }
        height[left] < height[right] ? left++ : right--;
    }


    return ans;
}

