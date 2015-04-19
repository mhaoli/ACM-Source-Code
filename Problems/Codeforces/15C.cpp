#include<bits/stdc++.h>
int main(){
        int n; scanf ("%d", &n);
        long long ans = 0;
        for (long long x, t; n--;){
                scanf ("%I64d%I64d", &x, &t);
                if (x & 1){
                        ++t; ans ^= --x;
                }
                if (t & 1) ans ^= (x + t - 1);
                if ((t>>1) & 1) ans ^= 1;
        }
        puts (ans ? "tolik" : "bolik");
        return 0;
}
