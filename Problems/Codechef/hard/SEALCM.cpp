#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define swap(a, b) (a ^= b, b ^= a, a ^= b)
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 1019;
const long long mod = 7 + (int)1e9;
std::vector<int> fac[Max_N];
int prm[Max_N], mo[Max_N], mi[Max_N];
bool check[Max_N];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
void init() {
        mo[1] = 1;
        int tot = 0, n = Max_N - 10;
        for(int i = 2, j; i <= n; ++i){
                if (!check[i]) prm[tot++] = i, mo[i] = -1, mi[i] = i;
                for (j = 0; j < tot; ++ j){
                        if (i * prm[j] > n) break;
                        mi[i*prm[j]] = prm[j];
                        check[i*prm[j]] = 1;
                        if (i % prm[j] == 0){
                                mo[i*prm[j]] = 0; break;
                        }
                        else mo[i*prm[j]] = -mo[i];
                }
        }

        for(int i = 1, t, res, last; i <= n; ++i) {
                for(t = i, last=mi[i], res=1; t > 1; t /= mi[t]) {
                        if(mi[t] == last) res *= mi[t];
                        else {
                                fac[i].push_back(res);
                                last = res = mi[t];
                        }
                }
                fac[i].push_back(res);
        }
}
struct matrix {
        int a[16][16], n;
        matrix(int t = 0, int _n = 0) {
                n = _n;
                memset(a, 0, sizeof a);
                if(t) for(int i = 0; i < n; ++i) a[i][i] = 1;
        }
        matrix operator*(const matrix &A) const {
                matrix ret = matrix(0, n);
                for(int i = 0, j, k; i < n; ++i)
                        for(j = 0; j < n; ++j) {
                                for(k = 0; k < n; ++k) {
                                        add(ret.a[i][j], (long long)a[i][k] * A.a[k][j] % mod);
                                }
                        }
                return ret;
        }
        matrix operator^(const int &tn) const {
                matrix ret = matrix(1, n), p = matrix(0, n); 
                for(int i = 0, j; i < n; ++i) for(j = 0; j < n; ++j) p.a[i][j] = a[i][j];
                for(int _ = tn; _; _ >>= 1) {
                        if(_ & 1) ret = ret * p;
                        p = p * p;
                }
                return ret;
        }
        void output() {
                out(n);
                for(int i = 0, j; i < n; ++i) for(j = 0; j < n; ++j) printf("%d%c", a[i][j], " \n"[j==n-1]);
        }
};
int N, M;
int cnt[20];
int solve(int x) {
        int n = fac[x].size(), up = 1 << n, i, j, t;

        memset(cnt, 0, sizeof cnt);
        for(i = 1; i <= M; ++i) {
                for(t = j = 0; j < n; ++j) if(i % fac[x][j] == 0) t |= 1 << j;
                ++cnt[t];
        }

        matrix A = matrix(0, up);
        for(i = 0; i < up; ++i) {
                for(j = 0; j < up; ++j) {
                        add(A.a[i][i|j], cnt[j]);
                }
        }
        A = A^N;
        return A.a[0][up-1];
}
int main() {
        init();
        int _; Read(_);
        for(int l, r, i, ans; _--; ) {
                Read(N); Read(M); Read(l); Read(r);
                ans = 0;
                for(i = l; i <= r; ++i) add(ans, solve(i));
                printf("%d\n", ans);
        }
        return 0;
}
