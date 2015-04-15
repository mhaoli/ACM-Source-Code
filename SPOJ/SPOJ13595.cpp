#include<bits/stdc++.h>
using namespace std;
template<class T> bool chmax (T &a, const T &b){ return a < b ? a=b, 1: 0;}
const int N = 1005;
int g[N][N];
int area[N][N], cnt[N][N];
pair<int, int> q[N];
int main(){
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1, j; i <= n; ++i){
        for (j = 1; j <= m; ++j) scanf ("%d", &g[i][j]);
    }
    for (int j, i = n; i; --i){
        for (j = m; j; --j) cnt[i][j] = g[i][j] ? 0 : cnt[i+1][j] + 1;
    }
    for (int i = 1, j, top = 0, last, cur; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            cur = cnt[i][last = j];
            while (top && q[top-1].first > cur){
                chmax (area[i][i + q[top-1].first - 1], j - q[top-1].second);
                last = q[--top].second;
            }
            if (!top || q[top-1].first < cur) q[top++] = make_pair (cur, last);
        }

        for (; top; --top) chmax (area[i][i + q[top-1].first - 1], m - q[top-1].second + 1);

        for (j = n-1; j >= i; --j) chmax (area[i][j], area[i][j+1]);
        for (j = n; j >= i; --j) area[i][j] *= (j - i + 1);
    }
    for (int i, l = 2; l <= n; ++l){
        for (i = 1; i+l-1 <= n; ++i){
            chmax (area[i][i + l - 1], area[i][i + l - 2]);
            chmax (area[i][i + l - 1], area[i+1][i + l - 1]);
        }
    }
    int q; scanf ("%d", &q);
    for (int a, b; q; --q){
        scanf ("%d%d", &a, &b);
        printf ("%d\n", area[a][b]);
    }
    return 0;
}
