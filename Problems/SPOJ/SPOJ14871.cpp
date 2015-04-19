#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
const int mod = 5000011;
int d[N], s[N];
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n, K; scanf ("%d%d", &n, &K);
        s[1] = d[1] = 1;
        for (int i = 2; i <= n; ++ i){
            d[i] = 1;
            if (i - K - 1 > 0) add (d[i], s[i-K-1]);
            s[i] = s[i-1]; add (s[i], d[i]);
        }
        printf ("%d\n", s[n] + 1);
    }
    return 0;
}
