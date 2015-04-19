#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
const int N = 1005;
int num[100];
char s[N];
int main(){
    int T, cas = 0; scanf ("%d", &T);
    while (T--){
        scanf ("%s", s);
        int L = strlen (s), ans = 0;
        for (int i = 0; i < L; ++ i){
            memset (num, 0, sizeof num);
            int cnt = 0;
            for (int j = i; j < L; ++ j){
                int t = s[j] - 'a';
                ++ num[t];
                if (num[t] & 1) ++ cnt;
                else -- cnt;
                if (cnt == 1 || cnt == 0) ++ ans;
            }
        }
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
