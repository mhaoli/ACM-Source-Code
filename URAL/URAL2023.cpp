#include<bits/stdc++.h>
std::string s[] = { "APOR", "BMS", "DGJKTW" };
char str[111];
int main(){
    int n, p = 1, i, sz, ans = 0;
    scanf ("%d", &n);
    while (n--){
        scanf ("%s", str);
        bool u = 0;
        for (i = 0; i < 3 && !u; ++ i){
            for (sz = 0; sz < (int)s[i].size(); ++ sz)
                if (str[0] == s[i][sz]) u = 1;
        }
        ans += p - i < 0 ? i-p : p-i;
        p = i;
    }
    printf ("%d\n", ans);
    return 0;
}
