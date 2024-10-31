//
//  3216.c
//  C_code_alo
//
//  Created by deathot on 10/30/24.
//

char* getSmallestString(char* s) {
    // int t = list(s);
    // int n = t.len();
    // int temp = 0;

    // for(int i = 0; i <= n - 1; i++) {
    //     int x = t[i - 1], y = t[i];
    //     while(x > y && ord(x) % 2 == ord(y) % 2) {
    //         temp = x;
    //         t[i - 1] = y;
    //         t[i] = temp;
    //         break;
    //     }
    //     return t
    // }
    
    for(int i = 1; s[i]; i++) {
        char x = s[i - 1], y = s[i];
        if(x > y && x % 2 == y % 2) {
            s[i - 1] = y;
            s[i] =x ;
            break;
        }
    }
    return s;
}
