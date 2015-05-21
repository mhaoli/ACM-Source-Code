#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
int _;
const long long mod = 1e9 + 7;
const int Max_N = 2e5 + 9;
int fa[Max_N];
std::vector<int> E[Max_N];
long long sub[Max_N], from[Max_N]; 
int main() {
        int n;
        scanf("%d", &n);
        for(int i = 1, f; i < n; ++i) {
                scanf("%d", &f);
                --f;
                E[f].push_back(i);
                fa[i] = f;
        }
        for(int i = n-1; i >= 0; --i) {
                sub[i] = 1;
                for(int j : E[i]) {
                        sub[i] = sub[i] * (sub[j] + 1) % mod;
                }
        }

        for(int i = 0; i < n; ++i) {
                from[i] = 1;
        }

        int ans;
        long long pre;
        for(int i = 0; i < n; ++i) {
                ans = sub[i] * from[i] % mod;
                printf("%d ", ans);
                pre = 1;
                for(int j : E[i]) {
                        from[j] = pre;
                        pre = pre * (sub[j] + 1) % mod;
                }
                pre = from[i];
                for(int j = SZ(E[i]) - 1; j >= 0; --j) {
                        int k = E[i][j];
                        from[k] = (from[k] * pre + 1) % mod;
                        pre = pre * (sub[k] + 1) % mod;
                }
        }
        return 0;
}
