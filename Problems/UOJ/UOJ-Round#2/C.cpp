#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)2e5;
const int block = 500;
struct Edge {
        int e;
        Edge *nxt;
        void add(int E, Edge*n) {
                nxt = n; e = E;
        }
} E[Max_N], *head[Max_N], *bat;
bool off[Max_N];
void adde(int s, int e) {
        bat->add(e, head[s]); head[s] = bat++;
}
int Q[Max_N], fa[Max_N], sz[Max_N], dep[Max_N];
int findRt(int x) {
        int r = 0;
        Q[r++] = x;
        for(int i = 0; i != r; ++i) {
                int t = Q[i];
                sz[t] = 0;
                for(Edge*p = head[t]; p; p = p->nxt) if(!off[p->e]){
                        Q[r++] = p->e;
                }
        }
        for(int i = r-1; i >= 0; --i) {
                if(((++sz[Q[i]]) << 1) >= r) return Q[i];
                sz[fa[Q[i]]] += sz[Q[i]];
        }
}
int bfs(int x, int *cnt) {
        int r = 0;
        Q[r++] = x;
        for(int i = 0; i != r; ++i) {
                int t = Q[i];
                for(Edge*p = head[t]; p; p = p->nxt) if(!off[p->e]){
                        Q[r++] = p->e;
                }
        }
        int h = dep[Q[r-1]] - dep[x];
        for(int i = 0; i <= h; ++i) cnt[i] = 0;
        for(int i = 0; i != r; ++i) ++cnt[dep[Q[i]] - dep[x]];
        return h;
}
int check[block+5][block+5], checkClock;
int _, n, cnt[Max_N], cntRt[Max_N], prefix[Max_N];
long long ans[Max_N], cntNum[Max_N], sqrNum[Max_N], ans2[Max_N];
int query[block+5][block+5];
int calc(int d, int stt, int h) {
        if(stt < 0) {
                stt %= d;
                if(stt < 0) stt += d;
        }
        if(stt < 0) stt = (stt % d) + d;
        if(d <= block) {
                int &ret = query[d][stt];
                if(check[d][stt] == checkClock) return ret;
                check[d][stt] = checkClock;
                ret = 0;
                for(; stt <= h; stt += d) ret += cntRt[stt];
                return ret;
        } else {
                int ret = 0;
                for(; stt <= h; stt += d) ret += cntRt[stt];
                return ret;
        }
}
void dfs(int x) {
        int rt = findRt(x), hmax = -1;
        off[rt] = 1;
        for(Edge*p = head[rt]; p; p = p->nxt) if(!off[p->e]) {
                int h = bfs(p->e, cnt) + 1;
                if(hmax < h) {
                        for(int d = hmax+1; d <= h; ++d) cntNum[d] = sqrNum[d] = 0;
                        hmax = h;
                }

                for(int d = 1, dd, tmp; d <= h; ++d) {
                        tmp = 0;
                        for(dd = d; dd <= h; dd += d) {
                                tmp += cnt[dd-1];
                        }
                        cntNum[d] += tmp;
                        sqrNum[d] += 1ll * tmp * tmp;
                        ans2[d] += cnt[d-1];
                }
        }
        for(int i = 1; i <= hmax; ++i) ans[i] += (cntNum[i] * cntNum[i] - sqrNum[i]) >> 1;

        int hTmp = bfs(rt, cntRt), f, last, up;
        //memset(query, -1, sizeof query);
        ++checkClock;
        for(f = fa[rt], last = rt; ~f && !off[f]; last = f, f = fa[f]) {
                off[last] = 1;
                int h = bfs(f, cnt);
                off[last] = 0;
                
                up = std::min(h, dep[rt] - dep[f] + hTmp);
                for(int d = 1, dd, tmp; d <= up; ++d) {
                        tmp = 0;
                        for(dd = d; dd <= h; dd += d) {
                                tmp += cnt[dd];
                        }
                        ans[d] += 1ll * tmp * calc(d, d - (dep[rt] - dep[f]), hTmp);
                }

        }

        up = hTmp + dep[rt] - dep[last];
        prefix[0] = cntRt[0];
        for(int i = 1; i <= hTmp; ++i) prefix[i] = prefix[i-1] + cntRt[i];
        for(int i = hTmp+1; i <= up; ++i) prefix[i] = prefix[i-1];
        for(int i = 1, L, R; i <= up; ++i) {
                L = std::max(i + dep[last] - dep[rt], 0);
                R = std::min(i - 1, hTmp);
                ans2[i] += prefix[R] - (L ? prefix[L-1] : 0);
        }
        off[rt] = 1;
        if(rt != x) dfs(x);
        for(Edge*p = head[rt]; p; p = p->nxt) if(!off[p->e]) dfs(p->e);
}
int main() {
       // freopen("tst.in","r",stdin);
      //  freopen("my.out","w",stdout);
        checkClock = 0;
        scanf("%d", &n);
        bat = E;
        fa[0] = -1;
        for(int i = 1, t; i < n; ++i) {
                scanf("%d", &t);
                --t;
                fa[i] = t;
                dep[i] = dep[t] + 1;
                adde(t, i);
        }
        dfs(0);
        for(int j, i = n-1; i; --i) {
                for(j = i<<1; j < n; j += i) 
                        ans[i] -= ans[j];
        }
        for(int i = 1; i < n; ++i) printf("%lld\n", ans[i] + ans2[i]);
        return 0;
}
