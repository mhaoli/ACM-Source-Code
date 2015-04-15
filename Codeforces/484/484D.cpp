#include<bits/stdc++.h>
int main(){
    int n; scanf ("%d", &n);
    long long ans = 0, t1, t2;
    for (int i = 0, t; i < n; ++ i){
        scanf ("%d", &t);
        if (!i || ans+t > t1) t1 = ans + t;
        if (!i || ans-t > t2) t2 = ans - t;
        ans = t1 - t > t2 + t ? t1 - t : t2 + t;
    }
    printf ("%I64d\n", ans);
    return 0;
}
