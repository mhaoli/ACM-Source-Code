#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
/****head****/
bool check(ll sta, ll end, ll t, ll tp) {
        ll t1 = sta / tp, t2 = end / tp;
        if(sta % tp > t) ++t1;
        if(end % tp < t) --t2;
        if(t1 <= t2) return 1;
        return 0;
}
ll temp[111];
char s[111];
int main() {
        temp[0] = 1;
        for(int i = 1; i < 15; ++i) {
                temp[i] = temp[i-1] * 10;
        }

        int q;
        scanf("%d\n", &q);
        while(q--) {
                scanf("IAO'%s\n", s);
                int n = 0, L = strlen(s);
                for(int i = 0; i < L; ++i) n = n * 10 + (s[i] - '0');

                ll sta = 1989;
                for(int i = 0; i < L; ++i) {
                        ll l = sta, r = 1ll << 61, mid, res = -1;
                        while(l <= r) {
                                mid = (l + r) >> 1;
                                //OUT(l); OUT(r); OUT(mid);
                                //puts("");
                                if(check(sta, mid, n%temp[i+1], temp[i+1])) {
                                        res = mid;
                                        r = mid - 1;
                                } else {
                                        l = mid + 1;
                                }
                        }
                        //OUT(res);
                        assert(res != -1);
                        sta = res + 1;
                }
                std::cout << sta - 1 << "\n";
        }
        return 0;
}
