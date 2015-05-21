#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
const int Dx[] = {0, 0, -1, 1}, Dy[] = {-1, 1, 0, 0};
int n, m, len[105];
char s[105][105], ts[105];
bool vis[105][105];
void color(int x, int y, int l, char c) {
        for(int i = x, j; i < x+l; ++i) 
                for(j = y; j < y+l; ++j) s[i][j] = c, vis[i][j] = 1;
}
void solve(int x) {
        if(x == n) return;
        char c;
        memset(ts, 0, sizeof ts);
        for(int i = 0; i < m; ++i) {
                if(vis[x][i]) continue;
                c = 'A';
                while(1) {
                        if(!(x && s[x-1][i]==c) && !(i && s[x][i-1]==c) && s[x][i+1]!=c) {
                                if(i && c == ts[i-1]) {
                                        if(len[i-1] > 1) {
                                                len[i] = len[i-1] - 1; break;
                                        }
                                } else {
                                        len[i] = n - x; break;
                                }
                        }
                        ++c;
                }
                ts[i] = c;
        }
        for(int i = 0, j; i < m; ++i) {
                if(vis[x][i]) continue;
                for(j = i+1; j < m && ts[j] == ts[i]; ++j);
                color(x, i, j - i, ts[i]);
                i = j-1;
        }
        solve(x + 1);
}
int main() {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                solve(i); s[i][m] = 0, puts(s[i]);
        }
        return 0;
}
