/*
other:
        http://codeforces.com/contest/611/submission/15103816
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
int n, m, q;
int get(int s[505][505], int t1, int t2) {
        if(t1 < 0 || t2 < 0) return 0;
        return s[t1][t2];
}

void DP(int a[505][505], int s[505][505]) {
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                        s[i][j] = a[i][j] + get(s, i-1, j) + get(s, i, j-1) - get(s, i-1, j-1);
                }
        }
}

int calc(int s[505][505], int t1, int t2, int p1, int p2) {
        return get(s, p1, p2) - get(s, t1-1, p2) - get(s, p1, t2-1) + get(s, t1-1, t2-1);
}

char s[505][505];
int row[505][505], col[505][505];
int rowS[505][505], colS[505][505];
bool ins(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
        std::cin >> n >> m;
        for(int i = 0; i < n; ++i) {
                scanf("%s", s[i]);
        }
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) if(s[i][j] == '.'){
                        if(ins(i, j + 1)) {
                                if(s[i][j+1] == '.') row[i][j] = 1;
                        }
                        if(ins(i+1, j)) {
                                if(s[i+1][j] == '.') col[i][j] = 1;
                        }
                }
        }
        DP(row, rowS);
        DP(col, colS);

        //for(int i = 0; i < n; ++i) {
                //for(int j = 0; j < m; ++j) {
                        //printf("%d ", colS[i][j]);
                //}
                //puts("");
        //}

        int t1, t2, p1, p2, ans;
        std::cin >> q;
        while(q--) {
                //std::cin >> t1 >> t2 >> p1 >> p2;
                scanf("%d%d%d%d", &t1, &t2, &p1, &p2);
                --t1; --t2; --p1; --p2;
                ans = calc(rowS, t1, t2, p1, p2-1);
                ans += calc(colS, t1, t2, p1-1, p2);
                printf("%d\n", ans);
        }
        return 0;
}
