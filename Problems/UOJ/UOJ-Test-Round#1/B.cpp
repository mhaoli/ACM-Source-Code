#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int inf = ~0u>>1;
const int Max_N = 9 + (int)3e5;
std::set<int> set;
struct oo {
        int t, s, p, id;
        void read(int ID) {
                id = ID;
                scanf("%d%d%d", &t, &s, &p);
                set.insert(p);
        }
        bool operator<(const oo &rhm) const {
                return p < rhm.p;
        }
};

int n, mx;
long long K;
oo an[Max_N];
long long ans[Max_N];

bool cmp(const oo&t1, const oo&t2) {
        return t1.t == t2.t ? t1.p > t2.p : t1.t < t2.t;
}

void solve() {
        std::priority_queue<oo> Q;
        
        bool flag;
        long long last = an[0].t, tim, Ptim;
        oo tmp;
        oo *idx = &tmp;
        for(int i = 0, j; i < n; i = j) {
                if(an[i].p == -1) {
                        Ptim = an[i].s;
                        flag = 1;
                        idx = &an[i];
                } else flag = 0;
                j = i + 1;
                while(j < n && an[j-1].t == an[j].t) {
                        if(an[j].p == -1) flag = 1, Ptim = an[j].s, idx = &an[j];
                        ++j;
                }

                tim = an[j-1].t;
                while(last < tim && !Q.empty()) {
                        tmp = Q.top(); Q.pop();
                        //if(1) {
                                //out(i);
                                //out(tmp.s);
                                //out(last);
                                //out(tim);
                        //}
                        if(tmp.s + last <= tim) {
                                last += tmp.s;
                                ans[tmp.id] = last;
                        } else {
                                tmp.s -= (tim - last);
                                last = tim;
                                Q.push(tmp);
                        }
                }
                last = tim;

                while(i < j) {
                        if(an[i].p != -1) Q.push(an[i]);
                        ++i;
                }

                //printf("%d %d\n", i, Q.size());
//
                if(flag) {
                        for(; j < n && an[j].t <= K; ++j) Q.push(an[j]);
                        tim = K - an[i-1].t - Ptim;
                        mx = 1e9;
                        while(tim > 0) {
                                tmp = Q.top(); Q.pop();
                                mx = tmp.p;
                                tim -= tmp.s;
                        }
                        --mx;
                        while(set.find(mx) != set.end()) --mx;
                        (*idx).p = mx;
                        return;
                }
        }
        while(!Q.empty()) {
                tmp = Q.top(); Q.pop();
                last += tmp.s;
                ans[tmp.id] = last;
        }
}

int main() {
        //freopen("a.out","w",stdout);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) an[i].read(i);
        scanf("%lld", &K);
        std::sort(an, an + n, cmp);
        solve();
        //puts("\n");
        std::sort(an, an + n, cmp);
        solve();
        printf("%d\n", mx);
        for(int i = 0; i < n; ++i) printf("%lld%c", ans[i], " \n"[i==n-1]);
        return 0;
}
