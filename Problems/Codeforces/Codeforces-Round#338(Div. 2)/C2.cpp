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
using namespace std;
/****head****/
int _;
int rev(int x, int n) {
        return n - x - 1;
}
int main() {
        string s, tar;
        cin >> s >> tar;
        string ss = s;
        reverse(ALL(ss));
        int n = SZ(s), m = SZ(tar);
        vector<bool> fg1(n), fg2(n);
        vector<pair<int, int> > ans;
        for(int i = 0; ; ) {
                bool fd = 0;
                pair<int, int> cur = mp(-1, -1);
                for(int j = 0; j < n; ++j) {
                        fg1[j] = (tar[i] == s[j]);
                        fg2[j] = (tar[i] == ss[j]);
                        fd |= fg1[j];
                        //if(fg1[j]) cur = mp(j, j);
                }
                //if(!fd) return puts("-1"), 0;

                for(int len = 1; fd && i < m; ++i, ++len) {
                        fd = 0;
                        for(int j = 0; j + len <= n; ++j) if(fg1[j]) {
                                if(tar[i] == s[j+len-1]) {
                                        fd = 1;
                                        cur = mp(j, j+len-1);
                                } else {
                                        fg1[j] = 0;
                                }
                        }
                        for(int j = 0; j + len <= n; ++j) if(fg2[j]) {
                                if(tar[i] == ss[j+len-1]) {
                                        fd = 1;
                                        cur = mp(rev(j, n), rev(j+len-1, n));
                                } else {
                                        fg2[j] = 0;
                                }
                        }
                }

                if(cur.x == -1) return puts("-1"), 0;
                ans.pb(cur);
                if(fd && i == m) break;
                --i;
        }
        cout << SZ(ans) << endl;
        for(auto it : ans) {
                printf("%d %d\n", it.x + 1, it.y + 1);
        }
        return 0;
}
