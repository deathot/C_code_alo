//
//  Max_substr.c
//  C_code_alo
//
//  Created by deathot on 10/28/24.
//

#define Max(a, b) ((a) > (b) ? a : b)

int lengthOfLongestSubstring(char* s) {
    int ans = 0, left = 0;
    bool has[128] = {};

    for(int right = 0; s[right]; right++) {
        char c = s[right];

        while(has[c]) {
            has[s[left++]] = false;
        }
        has[c] = true;
        int len = right- left + 1;
        ans = Max(ans, len);
    }
    return ans;
}
