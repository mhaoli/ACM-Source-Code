#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
int an[1<<12];
set<int> st;
vector<int> vec[1<<12];
map<int, int> has;
int dp[1<<12], pre[1<<12], f[1<<12], dpre[1<<12], fpre[1<<12];
int n;
int move(int s, int t) {
        if(s == t) return n;
        return min((s+n-t)%n, (t+n-s)%n);
}
int main() {
        int s;
        cin >> n >> s; --s;
        for(int i = 0; i < n; ++i) {
                cin >> an[i];
                st.insert(an[i]);
        }

        int m = 0;
        for(int i : st) has[i] = ++m;
        for(int i = 0; i < n; ++i) {
                vec[has[an[i]]].push_back(i);
        }
        for(int i = 0; i <= m; ++i) sort(ALL(vec[i]));

        //for(int i = 0; i < n; ++i) {
                //printf("%d ", has[an[i]]);
        //}
        //puts("");
       // 
        dp[s] = f[s] = 0;
        for(int t = 1; t <= m; ++t) {
                for(int i : vec[t]) {
                        if(t == 1) {
                                if(i == s) dp[i] = 0;
                                else dp[i] = move(s, i);
                                dpre[i] = s;
                        } else {
                                dp[i] = 1 << 30;
                                for(int j : vec[t-1]) {
                                        if(chmin(dp[i], f[j] + move(j, i))) {
                                                dpre[i] = j;
                                        }
                                }
                        }
                }

                //fpre : -1 for pre, 1 for next
                int sz = SZ(vec[t]);
                for(int i = 0; i < SZ(vec[t]); ++i) {
                        int pr = vec[t][(i+sz-1)%sz], nx = vec[t][(i+1)%sz], p = vec[t][i];
                        f[p] = dp[pr] + ((pr+n-p)%n);
                        fpre[p] = -1;
                        if(chmin(f[p], dp[nx] + ((p+n-nx)%n))) {
                                fpre[p] = 1;
                        }
                }
        }

        int cnt = 1 << 30, idx;
        vector<int> ans;
        for(int i : vec[m]) {
                if(chmin(cnt, f[i])) {
                        idx = i;
                }
        }
        for(int t = m; t; --t) {
                int d = fpre[idx], sz = SZ(vec[t]);
                int i = lower_bound(vec[t].begin(), vec[t].end(), idx) - vec[t].begin();
                int tar = (i + sz + d) % sz;
                for(; ; i = (i+sz-d)%sz) {
                        ans.push_back(vec[t][i]);
                        if(i == tar) break;
                }
                idx = dpre[vec[t][i]];
        }
        ans.push_back(s);
        reverse(ans.begin(), ans.end());

        //for(auto i : ans) printf("%d ", i);
        //puts("");
       // 
        printf("%d\n", cnt);
        for(int i = 1; i < SZ(ans); ++i) {
                int d = move(ans[i-1], ans[i]);
                if(ans[i-1] == ans[i]) d = 0;
                if(((ans[i-1]+d) % n) == ans[i]) printf("+%d\n", d);
                else printf("-%d\n", d);
        }
        return 0;
}
