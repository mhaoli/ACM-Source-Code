#include<bits/stdc++.h>
char ans1[111], ans2[111];
int main(){
        int n, s;
        scanf ("%d%d", &n, &s);
        if (!s) return puts (n == 1 ? "0 0" : "-1 -1"), 0;
        if (9 * n < s) return puts ("-1 -1"), 0;
        int s1 = s, s2 = s;
        for (int i = 0, t; i < n; ++i){
                t = s1 - (n - i - 1) * 9;
                if (t <= 0) ans1[i] = i ? '0' : '1';
                else ans1[i] = t + '0';
                if (s2 >= 9) ans2[i] = '9';
                else ans2[i] = s2 + '0';
                s1 -= ans1[i] - '0';
                s2 -= ans2[i] - '0';
        }
        printf ("%s %s\n", ans1, ans2);
        return 0;
}
