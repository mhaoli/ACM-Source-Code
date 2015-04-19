#include<bits/stdc++.h>
using namespace std;
template<class T> bool chmin (T &a, const T &b){ return a > b ? a = b, 1: 0;}
const int N = 111;
const int inf = ~0u>>2;
int d[2105][2105];
pair<int, int> a[N];
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n; scanf ("%d", &n);
        for (int i = 0; i < n; ++ i)
            scanf ("%d%d", &a[i].first, &a[i].second);
        sort (a, a + n, greater<pair<int, int> >());
        memset (d, 127, sizeof d);
        d[0][0] = 0;
        int mx = 0;
        for (int i = 0; i < n-1; ++ i){
            int h = a[i+1].first, w = a[i+1].second;
            for (int j = mx; j >= 0; -- j)
                for (int k = mx-j; k >= 0; -- k) if (d[j][k] < inf){
                    if (!j && !k) chmin (d[j+w][k], h);
                    else if (!k){
                        chmin (d[j][w], d[j][k] + h);
                        chmin (d[j+w][k], d[j][k]);
                    } else{
                        chmin (d[j+w][k], d[j][k]);
                        chmin (d[j][k+w], d[j][k]);
                    }
                }
            mx += w;
        }
        int ans = inf;
        for (int i = 1; i <= mx; ++ i)
            for (int j = 1; j <= mx-i; ++ j) if (d[i][j] < inf){
                chmin (ans, max (mx-i-j+a[0].second, max (i, j)) * (d[i][j] + a[0].first));
            }
        printf ("%d\n", ans);
    }
    return 0;
}
