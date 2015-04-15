#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = (T).begin(); it != (T).end(); ++ it)
using namespace std;
template<class T> bool chmax (T &a, const T &b){ return a < b ? a = b, 1 : 0;}
const int inf = ~0u>>1;
int kb[10], kc[10], kd[10], ka[10];
int equ[110], ea[110];
int n, m, X, Y;
int d[110][110][1<<7|1], g[10][40];
inline int calc (int state){
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (state & (1<<i)) ka[i] = kb[i] - 1, ans += kc[i];
        else ka[i] = kb[i];
        if (ka[i] < 0) return -inf;
    }
    memset (g, -1, sizeof g);
    for (int i = 0, up; i < n; ++ i){
        up = X < ka[i] ? X : ka[i];
        for (int k = 0; k <= up; ++ k)
            chmax (g[i][k], k*kc[i] + (k==ka[i] ? kd[i] : 0));

        if (!i) continue;

        for (int j = 0; j <= X; ++ j) if (d[i-1][j] >= 0){
            up = (X-j < ka[i] ? X-j : ka[i]);
            for (int k = 0; k <= up; ++ k){
                chmax (g[i][j+k], g[i-1][j] + k*kc[i] + (k==ka[i] ? kd[i] : 0));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= X; ++ j)
            chmax (res, g[i][j]);
    return res + ans;
}
int state[1<<10];
int main(){
    while (scanf ("%d%d", &n, &m) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d%d%d", kb + i, kc + i, kd + i);
        for (int i = 0, t, t2; i < m; ++ i){
            scanf ("%d%d", ea + i, &t);
            equ[i] = 0;
            while (t--){
                scanf ("%d", &t2);
                equ[i] |= (1 << (--t2));
            }
        }

        //for (int i = 0; i < m; ++ i)
            //printf ("%d %d\n", i, equ[i]);
        //puts ("aaa");
//
        scanf ("%d%d", &X, &Y);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j <= Y; ++ j)
                memset (d[i][j], -1, sizeof d[i][j]);
        for (int i = 0; i < m; ++ i){
            if (Y){
                chmax (d[i][1][equ[i]], ea[i]);
                d[i][0][0] = 0;
            }
            if (!i) continue;
            for (int j = 0; j <= Y; ++ j){
                for (int k = 0; k < (1<<n); ++ k) if (d[i-1][j][k] >= 0){
                    chmax (d[i][j][k], d[i-1][j][k]);
                    if (j < Y) chmax (d[i][j+1][k|equ[i]], d[i-1][j][k] + ea[i]);
                }
            }
        }

        int ans = 0;
        if (Y){
            memset (state, -1, sizeof state);
            for (int i = 0; i <= Y; ++ i)
                for (int j = 0; j < (1<<n); ++ j)
                    chmax (state[j], d[m-1][i][j]);

            //for (int i = 0; i <= (1<<n); ++ i)
                //printf ("%d %d\n", i, state[i]);
//
            for (int i = 0; i < (1<<n); ++ i)
                if (state[i] >= 0) chmax (ans, state[i] + calc (i));
        } else ans = calc (0);
        printf ("%d\n", ans);
    }
    return 0;
}
