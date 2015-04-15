#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
int tmp[1005][1005];
void Swap(int a[1005][1005], int &n, int &m) {
        for(int i = 0, j; i < n; ++i)
                for(j = 0; j < m; ++j) tmp[j][i] = a[i][j];
        std::swap(n, m);
        for(int i = 0, j; i < n; ++i) 
                for(j = 0; j < m; ++j) a[i][j] = tmp[i][j];
}
int n, m;
int a[1005][1005], ans[1005][1005], pos[2][2];
bool vis[10];
std::set<int> st[2], xt[2];
bool calc() {
        st[0].clear(); st[1].clear();
        for(int i, j = 0; j < m; ++j) {
                xt[0].clear(); xt[1].clear();
                for(i = 0; i < n; ++i) if(a[i][j]) xt[i&1].insert(a[i][j]);
                if(xt[0].size() > 1 || xt[1].size() > 1) return 0;
                snuke(it, xt[0]) {
                        if(xt[1].count(*it)) return 0;
                        st[j&1].insert(*it);
                }
                snuke(it, xt[1]) {
                        if(xt[0].count(*it)) return 0;
                        st[j&1].insert(*it);
                }
        }
        if(st[0].size() > 2 || st[1].size() > 2) return 0;

        for(int i = 0; i < 2; ++i)
                snuke(it, st[i]) if(st[i^1].count(*it)) return 0;

        //puts("st0");
        //snuke(it, st[0]) printf("%d ", *it);
        //puts("\nst1");
        //snuke(it, st[1]) printf("%d ", *it);
        //puts("");
//
        for(int i = 1; i < 5; ++i) vis[i] = 0;
        snuke(it, st[0]) vis[*it] = 1; snuke(it, st[1]) vis[*it] = 1;
        while(st[0].size() < 2) for(int i = 1; i < 5 && st[0].size() < 2; ++i) if(!vis[i]) st[0].insert(i), vis[i] = 1;
        while(st[1].size() < 2) for(int i = 1; i < 5; ++i) if(!vis[i]) st[1].insert(i), vis[i] = 1;

        for(int i = 0, j; i < 2; ++i) {
                j = 0;
                snuke(it, st[i]) pos[i][j++] = *it;
        }
        for(int i, u, j = 0; j < m; ++j) {
                u = 0;
                for(i = 0; i < n; ++i) {
                        ans[i][j] = pos[j&1][i&1];
                        if(a[i][j] && ans[i][j] != a[i][j]) {
                                u = 1; break;
                        }
                }
                if(u) for(i = 0; i < n; ++i) {
                        ans[i][j] = pos[j&1][(i+1)&1];
                        if(a[i][j] && ans[i][j] != a[i][j]) return 0;
                }
        }
        return 1;
}
char str[1111];
int main() {
        scanf("%d%d", &n, &m);
        for(int j, i = 0; i < n; ++i) {
                scanf("%s", str);
                for(j = 0; j < m; ++j) a[i][j] = str[j] - '0';
        }
        if(!calc()) {
                Swap(a, n, m);
                //for(int i = 0; i < n; ++i)
                        //for(int j = 0; j < m; ++j) printf("%d%c", a[i][j], " \n"[j==m-1]);
                if(calc()) {
                        Swap(ans, n, m);
                        for(int i = 0, j; i < n; ++i) {
                                for(j = 0; j < m; ++j) printf("%d", ans[i][j]);
                                puts("");
                        }
                } else puts("0");
        } else {
                for(int i = 0, j; i < n; ++i) {
                        for(j = 0; j < m; ++j)
                                printf("%d", ans[i][j]);
                        puts("");
                }
        }
        return 0;
}
