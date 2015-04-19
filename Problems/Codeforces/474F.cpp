#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)1e5;
int gd[N][25], lg2[N];
void init (int *a, int n){
    for (int i = 0; i < n; ++i){
        gd[i][0] = a[i];
        lg2[i] = !i ? -1 : lg2[i>>1] + 1;
    }
    for (int i, j = 1, l = 2; l <= n; ++j, l <<= 1){
        for (i = 0; i + l - 1 < n; ++i)
            gd[i][j] = __gcd (gd[i][j-1], gd[i+(l>>1)][j-1]);
    }
}
int query (int a, int b){
    int k = lg2[b - a + 1];
    return __gcd (gd[a][k], gd[b-(1<<k)+1][k]);
}
vector<int> st[N];
int a[N], b[N], s[N];
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", a + i), s[i] = a[i];
    init (a, n);
    sort (s, s + n);
    for (int i = 0; i < n; ++i)
        b[i] = lower_bound (s, s + n, a[i]) - s;
    for (int i = 0; i < n; ++i)
        st[b[i]].push_back (i);

    int m; scanf ("%d", &m);
    for (int tg, g, u, v, it1, it2; m; --m){
        scanf ("%d%d", &u, &v); --u; --v;
        g = query (u, v);
        tg = lower_bound (s, s + n, g) - s;
        if (s[tg] != g){
            printf ("%d\n", v - u + 1);
        } else{
            it1 = lower_bound (st[tg].begin(), st[tg].end(), u) - st[tg].begin ();
            it2 = upper_bound (st[tg].begin(), st[tg].end(), v) - st[tg].begin () - 1;
            printf ("%d\n", v - u + 1 - (it2 - it1 + 1));
        }
    }
    return 0;
}
