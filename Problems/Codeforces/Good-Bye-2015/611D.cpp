/*
other :
   http://codeforces.com/contest/611/submission/15109593
 */
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
int mod = (int)1e9 + 7;
const static int Max_N = 5005;

void add(int&a, int&b) {
        a += b;
        if(a >= mod) a -= mod;
}

struct RMQ{
        int mx[Max_N][30], lg2[Max_N];
        void init (int n, int *a){ //a: 0...n-1
                for (int i = 0; i < n; ++ i){
                        mx[i][0] = a[i];
                        lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
                }
                lg2[n] = lg2[n>>1] + 1;
                for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
                        for (int i = 0; i + l - 1 < n; ++ i)
                                mx[i][j] = std::min(mx[i][j-1], mx[i+(l>>1)][j-1]);
                }
        }
        int query(int a, int b) { //[a, b]
                int k = lg2[b - a + 1];
                return std::min(mx[a][k], mx[b-(1<<k)+1][k]);
        }
};

struct SA{
        //all array form 0 to n-1
        //r[i] != 0 should be guaranteed
        int n;
        int sa[Max_N];       //sa[i] = j: suffix(j)'s rank = i
        int rank[Max_N];     //rank[i] = j: suffix(i)'s rank = j
        int h[Max_N];        //hei[i] = LCP(suffix(sa[i-1], sa[i]))
        int wa[Max_N], wb[Max_N], wv[Max_N], wt[Max_N];

        RMQ rmq;

        int cmp(int *r, int a, int b, int l){
                return r[a]==r[b] && r[a+l]==r[b+l];
        }

        //1 <= r[i] < m, i from 0 to n-1
        void init(int *r, int n, int m)
        {
                r[n] = 0; this -> n = n ++;

                int i, j, p, *x=wa, *y=wb, *t;
                for (i = 0; i < m; ++ i) wt[i] = 0;
                for (i = 0; i < n; ++ i) wt[x[i]=r[i]] ++;
                for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
                for (i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
                for(j = 1, p = 1; p < n; j *= 2, m = p)
                {
                        for (p = 0, i = n-j; i < n; i++) y[p++] = i;
                        for (i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
                        for (i = 0; i < n; ++ i) wv[i] = x[y[i]];
                        for (i = 0; i < m; ++ i) wt[i] = 0;
                        for (i = 0; i < n; ++ i) wt[wv[i]] ++;
                        for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
                        for (i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
                        for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
                }
                calhei(r);
                return;
        }

        void calhei(int *r){
                int i, j, k = 0;
                for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
                for (i = 0; i < n; h[rank[i++]] = k)
                        for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);

                for(int i = 0; i < n; ++i) {
                        sa[i] = sa[i+1];
                        h[i] = h[i+1];
                        rank[i]--;
                }
                rmq.init(n, h);
                return;
        }

        int lcp(int a, int b){
                if(a == b) return n - a;
                a = rank[a]; b = rank[b];
                if(a > b) std::swap(a, b);
                return rmq.query(a+1, b);
        }
}gao;

int n;
int dp[5005][5005], s[5005][5005];
char str[5005];
int S[5005];

bool greater(int t1, int t2, int p1, int p2) {
        --t1; --t2; --p1; --p2;
        int lcp = gao.lcp(t1, p1);
        if(t2 - t1 + 1 <= lcp) return false;
        if(str[t1+lcp] >= str[p1+lcp]) return false;
        return true;
}
int main() {
        std::cin >> n;
        std::cin >> str;
        for(int i = 0; i < n; ++i) {
                S[i] = str[i] - '0' + 1;
        }
        gao.init(S, n, 12);

        memset(dp, 0, sizeof dp);
        memset(s, 0, sizeof s);

        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j < i; ++j) {
                        if(str[i-j] != '0') {
                                if((j<<1) <= i && greater(i-2*j+1, i-j, i-j+1, i)) {
                                        add(dp[i][j], dp[i-j][j]);
                                }
                                add(dp[i][j], s[i-j][std::min(i-j,j-1)]);
                        }
                }
                dp[i][i] = 1;

                for(int j = 1; j <= i; ++j) {
                        s[i][j] = dp[i][j];
                        add(s[i][j], s[i][j-1]);
                }
        }

        std::cout << s[n][n] << std::endl;
        return 0;
}
