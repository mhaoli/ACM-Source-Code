#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 1 << 20;
int A[Max_N], B[Max_N], C[Max_N];
int main() {
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
        int _; scanf("%d", &_);
        for(int n, cas = 0, T1, T2, T3; _--; ) {
                scanf("%d%d%d%d", &T1, &T2, &T3, &n);
                for(int i = 0, t1, t2, t3; i < n; ++i) {
                        scanf("%d%d%d", &t1, &t2, &t3);
                        A[1<<i] = t1; B[1<<i] = t2; C[1<<i] = t3;
                }
                bool ans = 0;
                A[0] = B[0] = C[0] = 0;
                for(int i = 0, t; i < 1<<n; ++i) {
                        t = i & (-i);
                        A[i] = A[i^t] + A[t];
                        B[i] = B[i^t] + B[t];
                        C[i] = C[i^t] + C[t];
                        if(A[i] == T1 && B[i] == T2 && C[i] == T3) {
                                ans = 1; break;
                        }
                }
                printf("Case #%d: %s\n", ++cas, ans ? "yes" : "no");
        }
        return 0;
}
