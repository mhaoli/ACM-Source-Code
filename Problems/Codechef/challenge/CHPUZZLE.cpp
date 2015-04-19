#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
using namespace std;
namespace transformWH {
        void solve(int w, int h, int &tw, int &th) {
                if(w <= 50) {
                        tw = 1; th = 1; return;
                }
                if(w <= 200) {
                        tw = 1; th = 1; return;
                }
                if(w <= 800) {
                        tw = w / 100; th = h / 100; return;
                }
                tw = w / 40; th = h / 40;
        }
}
struct Shape {
        int n, idx, mw, mh;
        std::pair<int, int> *beg, *end;
        int *S, *T;
};
Shape A[9 + (int)1e5], *pnt[9 + (int)1e5];
std::pair<int, int> pool[9 + (int)5e6], *bat;
int mem[12000009], *bat2;
int temMem[9 + (int)1e6], *temMemBat;
 
int w, h, n, W, H, tot, wCnt, hCnt;
int ans[1010][1010], ans_cnt;
int idx[1010][1010];
bool vis[9 + (int)1e6];
bool cmp(Shape *a, Shape *b) {
        return a->n > b->n;
}
void init() {
        Read(W); Read(H); Read(n);
        transformWH::solve(W, H, w, h);
        wCnt = ceil(W / (w + 0.0)); hCnt = ceil(H / (h + 0.0));
 
        for(int i = 1, j, ti, tj, t1, t2, t3, t4; i <= W; ++i) {
                t1 = i; t2 = std::min(t1 + w - 1, W);
                for(j = 1; j <= H; ++j) {
                        t3 = j; t4 = std::min(t3 + h - 1, H);
                        for(ti = t1; ti <= t2; ++ti) for(tj = t3; tj <= t4; ++tj) idx[ti][tj] = tot;
                        ++tot;
                        j = t4;
                }
                i = t2;
        }
 
        bat = pool; bat2 = mem;
        for(int i = 0, *pos; i < n; ++i) {
                pnt[i] = &A[i];
                pnt[i]->idx = i + 1;
                Read(pnt[i]->n);
                pnt[i]->mw = pnt[i]->mh = 0;
                for(pnt[i]->beg = bat, pnt[i]->end = bat + pnt[i]->n, temMemBat = temMem; bat != pnt[i]->end; ++bat, ++temMemBat) {
                        Read(bat->first); Read(bat->second);
                        *temMemBat = idx[bat->first][bat->second];
                        pnt[i]->mw = std::max(pnt[i]->mw, bat->first);
                        pnt[i]->mh = std::max(pnt[i]->mh, bat->second);
                }
 
                std::sort(temMem, temMemBat);
                pnt[i]->S = bat2;
                if(pnt[i]->n) {
                        *bat2 = temMem[0]; ++bat2;
                        for(pos = temMem + 1; pos != temMemBat; ++pos) {
                                if((*pos) != (*(pos-1))) *bat2 = *pos, ++bat2;
                        }
                }
                pnt[i]->T = bat2;
        }
}
bool check(Shape *p, int t1, int t2) {
        if(p->mw + t1*w > wCnt || p->mh + t2*h > hCnt) return 0;
        for(int*pos = p->S; pos != p->T; ++pos) if(vis[(*pos) + hCnt*t1 + t2]) return 0;
        for(std::pair<int, int> *pos = p->beg; pos != p->end; ++pos) {
                vis[idx[pos->first][pos->second] + hCnt*t1 + t2] = 1;
                ans[pos->first + t1*w][pos->second + t2*h] = p->idx;
        }
        return 1;
}
void solve() {
        std::sort(pnt, pnt + n, cmp);
        //for(int i = 0; i < n; ++i) printf("%d ", pnt[i]->n);
        //out(pnt[1]->idx);
        //puts("");
        ans_cnt = 0;
        bool flag = 0;
        for(int i = 0, j, k; i < n; ++i) {
                flag = 0;
                for(j = 0; j < wCnt && !flag; ++j) for(k = 0; k < hCnt && !flag; ++k) if(check(pnt[i], j, k)) flag = 1;
 
                //if(i == 8) {
                        //for(int i = 1, j, t; i <= W; ++i) {
                                //for(j = 1; j <= H; ++j, ++t) printf("%d%c", vis[t], " \n"[j==H]);
                        //}
                        //puts("\n");
                //}
        }
        for(int i = 1, j; i <= W; ++i) {
                for(j = 1; j <= H; ++j) printf("%d%c", ans[i][j], " \n"[j==H]);
        }
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("a.out","w",stdout);
        init();
        solve();
        return 0;
}
