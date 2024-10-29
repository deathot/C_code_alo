//
//  2730.c
//  C_code_alo
//
//  Created by deathot on 10/29/24.
//

#define Max(a, b) ((a) > (b) ? a : b)

int longestSemiRepetitiveSubstring(char* s) {
    int ans = 1, rep = 0, left = 0;
    int len = strlen(s);

    for(int right = 0; right <= len - 1; right++) {
        if( right > 0 && s[right] == s[right - 1]) {
            rep += 1;
        }

        if(rep > 1) {
            left += 1;
            while(s[left] != s[left - 1]) {
                left += 1;
            }
            rep = 1;
        }
        ans = Max(ans, right - left + 1);
    }
    return ans;
}
