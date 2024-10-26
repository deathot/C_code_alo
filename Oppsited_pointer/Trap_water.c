//
//  Trap_water.h
//  C_code_alo
//
//  Created by deathot on 10/26/24.
//

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))

int trap(int* height, int n) {
    int ary1[n];
    int ary2[n];
    int ans = 0;
    if (n == 0) {
        return 0;
    }
    // memset(ary1,0,sizeof(ary1));
    // memset(ary2,0,sizeof(ary2));
    ary1[0] = height[0];
    ary2[n-1] = height[n-1];
    
    for(int i = 1; i < n; ++i) {
        ary1[i] = Max(ary1[i - 1], height[i]);
    }

    for(int i = n - 2; i >= 0; --i) {
        ary2[i] = Max(ary2[i + 1], height[i]);
    }

    for(int i = 0; i < n; ++i) {
        ans += Min(ary1[i], ary2[i]) - height[i];
    }

    return ans;
}
