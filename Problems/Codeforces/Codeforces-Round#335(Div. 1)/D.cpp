#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
const int inf = 1 << 30;
set<int> xn;
set<pair<int, int> > st[1<<19];
pair<pair<int, int>, pair<int, int> > an[1<<17];
map<int, int> has;
int m, pre[1<<17];
bool inQ[1<<17];
int Q[1<<17];
set<int> vec;
int mi[1<<20];
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
void Up(int rt) {
        mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
}
void insert(int p, int v, int id, int l = 0, int r = m-1, int rt = 1) {
        if(l == r) {
                st[rt].insert(mp(v, id));
                mi[rt] = st[rt].begin()->x;
                return;
        }

        int mid = l + r >> 1;
        if(p <= mid) insert(p, v, id, lson);
        else insert(p, v, id, rson);
        Up(rt);
}
void query(int ql, int qr, int v, int l = 0, int r = m-1, int rt = 1) {
        if(mi[rt] > v) return;
        if(l == r) {
                //OUT(l); OUT(qr); OUT(v); OUT(SZ(st[rt])); OUT(rt); OUT(st[rt].begin()->y);
                auto it = st[rt].lower_bound(mp(v, inf)), it2 = it;
                //if(it == st[rt].begin()) return;
                --it;
                while(1) {
                        vec.insert(it->y);
                        it2 = it;
                        if(it == st[rt].begin()) {
                                st[rt].erase(it2);
                                break;
                        } else {
                                --it;
                                st[rt].erase(it2);
                        }
                }
                if(st[rt].empty()) mi[rt] = inf;
                else mi[rt] = st[rt].begin()->x;
                return;
        }
        int mid = l + r >> 1;
        if(ql <= mid) query(ql, qr, v, lson);
        if(qr > mid) query(ql, qr, v, rson);
        Up(rt);
}
int main() {
        int n;
        cin >> n;
        for(int i = 0, x1, x2, y1, y2; i < n; ++i) {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                xn.insert(x1);
                xn.insert(x2);
                an[i] = mp(mp(x1, y1), mp(x2, y2));
        }

        m = 0;
        for(auto it : xn) has[it] = m++;

        int l = 0, r = 0;
        memset(inQ, 0, sizeof inQ);
        memset(mi, 127, sizeof mi);
        for(int i = 0; i < n; ++i) {
                an[i].x.x = has[an[i].x.x];
                an[i].y.x = has[an[i].y.x];

                //printf("i : %d %d %d %d\n", an[i].x.x, an[i].x.y, an[i].y.x, an[i].y.y);
//
                if(!an[i].x.x && !an[i].x.y) {
                        Q[r++] = i;
                        pre[i] = -1;
                        inQ[i] = 1;
                } else insert(an[i].x.x, an[i].x.y, i);
        }

        while(!inQ[n-1] && l < r) {
                int id = Q[l];
                ++l;
                vec.clear();
                query(0, an[id].y.x, an[id].y.y);
                for(auto it : vec) if(!inQ[it]){
                        inQ[it] = 1;
                        pre[it] = id;
                        if(it == n-1) break;
                        //Q[r++] = mp(it, dis + 1);
                        Q[r++] = it;
                }
        }

        if(!inQ[n-1]) return puts("-1"), 0;
        vector<int> ans;
        int idx = n-1;
        while(idx != -1) {
                ans.push_back(idx + 1);
                idx = pre[idx];
        }
        printf("%d\n", SZ(ans));
        for(int i = SZ(ans)-1; i >= 0; --i) printf("%d ", ans[i]);
        return 0;
}
