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
typedef long long ull;
using namespace std;
/****head****/
int _;
ull hs1[2111], hs2[2111];
ull key = 500009, key2 = 30007, h1[2111], h2[2111], h3[2111], h4[2111], h5[2111], h6[2111];
map<pair<ull, ull>, pair<int, int> > has[2111];
pair<ull, ull> getHash(int l, int r, ull*h1, ull*h2) {
        pair<ull, ull> ret = mp(h1[r], h2[r]);
        if(l) {
                //ret.x = (ret.x + mod - (h1[l-1] * hs1[r-l+1] % mod)) % mod;
                //ret.y = (ret.y + mod - (h2[l-1] * hs2[r-l+1] % mod)) % mod;
                ret.x -= h1[l-1] * hs1[r-l+1];
                ret.y -= h2[l-1] * hs2[r-l+1];
        }
        return ret;
}
void Hash(const string &s, ull*h1, ull*h2) {
        hs2[0] = hs1[0] = 1;
        for(int i = 0; i < SZ(s); ++i) {
                h2[i] = h1[i] = s[i] - 'a' + 1;
                if(i) {
                        //h1[i] = (h1[i] + (h1[i-1] * key % mod)) % mod;
                        //h2[i] = (h2[i] + (h2[i-1] * key2 % mod)) % mod;
                        //hs1[i] = hs1[i-1] * key % mod;
                        //hs2[i] = hs2[i-1] * key2 % mod;
                        h1[i] += h1[i-1] * key;
                        h2[i] += h2[i-1] * key2;
                        hs1[i] = hs1[i-1] * key;
                        hs2[i] = hs2[i-1] * key2;
                }
        }
}
int dp[2222], pre[2222];
pair<int, int> path[2222];
string s1, s2;
int n, m;
bool ok(int l, int r, pair<int,int>&tmp) {
        if(l > r) return 1;
        //return has[r-l+1].find(getHash(l, r, h5, h6)) != has[r-l+1].end();
        auto h = getHash(l,r,h5,h6);
        for(int i = 0, j = r - l; j < m; ++j, ++i) {
                if(h == getHash(i,j,h1,h2)) {
                        tmp =mp(i,j);
                        return 1;
                }
                if(h == getHash(i,j,h3,h4)) {
                        tmp = mp(m-i-1, m-j-1);
                        return 1;
                }
        }
        return 0;
}
int main() {
        //OUT(mod * 3);
        cin >> s1 >> s2;
        n = SZ(s2), m = SZ(s1);
        Hash(s1, h1, h2);
        //for(int i = 0; i < m; ++i) {
                //for(int j = i; j < m; ++j) {
                        //has[j-i+1][getHash(i, j, h1, h2)] = mp(i, j);
                //}
        //}
        reverse(ALL(s1));
        Hash(s1, h3, h4);
        //for(int i = 0; i < m; ++i) {
                //for(int j = i; j < m; ++j) {
                        //has[j-i+1][getHash(i, j, h3, h4)] = mp(m-i-1, m-j-1);
                //}
        //}

        Hash(s2, h5, h6);

        memset(dp, 127, sizeof dp);
        pre[0] = -1;
        path[0] = mp(-1, -1);
        dp[0] = 0;
        pair<int, int> tmp;
        for(int i = 0, l, r, mid, res; i < n; ) {
                l = 0, r = n - i; res = 0;
                while(l <= r) {
                        mid = l + r >> 1;
                        if(ok(i, i + mid - 1, tmp)) {
                                res = mid;
                                l = mid + 1;
                        } else r = mid - 1;
                }
                if(!res) return puts("-1"), 0;
                ok(i, i + res -1, tmp);
                //auto it = has[res].find(getHash(i, i+res-1, h5, h6));
                pre[i+res] = i;
                dp[i+res] = dp[i] + 1;
                path[i+res] = tmp;
                i = i + res;
        }
        if(dp[n] > 222222) return puts("-1"), 0;
        int idx = n;
        vector<pair<int, int> > ans;
        while(idx != 0) {
                ans.pb(path[idx]);
                idx = pre[idx];
        }
        printf("%d\n", SZ(ans));
        for(int i = SZ(ans)-1; i >= 0; --i) {
                printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
        }
        return 0;
}
