#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
int an[Max_N];
struct Edge {
        int e, c;
        Edge *nxt;
        void add(int E, int C, Edge*n) {
                e = E; c = C; nxt = n;
        }
};
Edge E[Max_N<<1], *bat=E, *head[Max_N];
void adde(int s, int t, int c) {
        bat->add(t, c, head[s]); head[s] = bat++;
}

int dis[Max_N], fa[Max_N], S, T;
int dis2[Max_N], diameter[Max_N], dia_top, ans[Max_N];
bool special[Max_N], black[Max_N];
std::vector<int> point[Max_N];

void dfs(int x, int pre) {
        fa[x] = pre;
        for(Edge*p = head[x]; p; p = p->nxt) if(p->e != pre) {
                dis[p->e] = p->c + dis[x];
                dfs(p->e, x);
        }
}
int res, resCnt;
int stk[Max_N], stk_top;
int dfs2(int x, int pre, int *d) {
        int ret = 0, tmp;
        if(special[x]) stk[stk_top++] = x;
        if(black[x]) {
                point[stk[stk_top-1]].push_back(x);
        }
        for(Edge*p = head[x]; p; p = p->nxt) if(p->e != pre){
                d[p->e] = p->c + d[x];
                tmp = dfs2(p->e, x, d);
                if(!special[p->e]) ret += tmp;
        }
        if(special[x]) --stk_top;

        if(!special[x] && !black[x]) {
                if(ret > res) res = ret, resCnt = 1;
                else if(ret == res) ++resCnt;
        }
        return ret + black[x];
}
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
                scanf("%d", an + i); 
                black[--an[i]] = 1;
        }
        for(int i = 0, s, t, c; i < n-1; ++i) {
                scanf("%d%d%d", &s, &t, &c);
                --s; --t;
                adde(s, t, c); adde(t, s, c);
        }

        dis[an[0]] = 0;
        dfs(an[0], -1);
        S = an[0];
        for(int i = 0; i < m; ++i) if(dis[S] < dis[an[i]]) S = an[i];
        dis[S] = 0;
        dfs(S, -1);
        T = S;
        for(int i = 0; i < m; ++i) if(dis[T] < dis[an[i]]) T = an[i];
        dia_top = 0;
        for(int i = T; ~i; i = fa[i]) {
                special[i] = 1;
                diameter[dia_top++] = i;
        }
        dis2[T] = 0;
        stk_top = 0;
        res = 0, resCnt = 0;
        dfs2(T, -1, dis2);

        int cnt = 0;
        for(int i = 0, idx; i < dia_top; ++i) {
                idx = diameter[i];
                ans[idx] += cnt;
                snuke(it, point[idx]) {
                        if(dis2[*it] < dis[*it]) {
                                ++cnt;
                        }
                        if(dis2[*it] == dis2[S]) {
                                cnt = 0; break;
                        }
                }
        }

        cnt = 0;
        for(int i = dia_top-1, idx; i >= 0; --i) {
                idx = diameter[i];
                ans[idx] += cnt;
                snuke(it, point[idx]) {
                        if(dis2[*it] > dis[*it]) {
                                ++cnt;
                        }
                        if(dis[*it] == dis[T]) {
                                cnt = 0; break;
                        }
                }
                
        }

        for(int i = 0, idx; i < dia_top; ++i) {
                idx = diameter[i];
                if(black[idx]) continue;
                ans[idx] += point[idx].size();
                if(res < ans[idx]) res = ans[idx], resCnt = 1;
                else if(res == ans[idx]) ++resCnt;
        }
        if(!res) printf("%d %d\n", 0, n - m);
        else printf("%d %d\n", res, resCnt);
        return 0;
}
