#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second
typedef long long ll;
template<class T> bool chmin (T&a, const T&b){return b < a ? a = b, 1 : 0;}
const int N = 4005;
const ll linf = (ll)(4e18);
ll d[4005][4005];
int p[N][N], ans[N], a[N], b[N];
pair<int, int> ta[N], tb[N];
int main(){
    int n, m;
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i) scanf ("%d", &ta[i].x), ta[i].y = i;
        sort (ta, ta + n);
        for (int i = 0; i < n; ++ i) a[i] = ta[i].x;
        scanf ("%d", &m);
        for (int i = 0; i < m; ++ i) scanf ("%d", &tb[i].x), tb[i].y = i;
        sort (tb, tb + m);
        for (int i = 0; i < m; ++ i) b[i] = tb[i].x;

        memset (d, -1, sizeof d);
        d[0][0] = abs (a[0] - b[0]);
        for (int i = 0; i < n-1; ++ i)
            for (int j = 0; j < m; ++ j) if (~d[i][j]){
                if (d[i+1][j] == -1) d[i+1][j] = linf;
                if (chmin (d[i+1][j], d[i][j] + abs (a[i+1]-b[j])))
                    p[i+1][j] = j;
                if (j < m-1){
                    if (d[i+1][j+1] == -1) d[i+1][j+1] = linf;
                    if (chmin (d[i+1][j+1], d[i][j] + abs (a[i+1]-b[j+1])))
                        p[i+1][j+1] = j;
                }
            }

        printf ("%lld\n", d[n-1][m-1]);
        for (int i = n-1, pos = m-1; i >= 0; pos = p[i--][pos]){
            ans[ta[i].y] = tb[pos].y;
        }
        for (int i = 0; i < n; ++ i)
            printf ("%d%c", ans[i]+1, " \n"[i==n-1]);
    }
    return 0;
}
