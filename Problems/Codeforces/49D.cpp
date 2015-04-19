#include<bits/stdc++.h>
const int inf = ~0u>>2;
char str[1111];
int d[1111][2];
int main(){
        int n, ans = ~0u>>1;
        scanf ("%d%s", &n, str);
        for (int t = 0, i, res; t < 2; ++t){
                res = 0;
                for (i = 0; i < n; ++i){
                        if (str[i] - '0' != ((i + t) & 1)){
                                ++res;
                                if (str[i] == str[i+1]) ++i;
                        }
                }
                ans = std::min (ans, res);
        }
        printf ("%d\n", ans);
        return 0;
}
