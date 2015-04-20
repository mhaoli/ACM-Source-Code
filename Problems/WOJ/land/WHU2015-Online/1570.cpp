#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 33;
int an[Max_N];
double calc(int t1, int t2, int m) {
        double ret = 0;
        while(t1 <= t2) {
                ret += an[t1++] / (m + 0.0);
        }
        return ret;
}
double calc2(int t1, int t2, double x) {
        double ret = 0;
        while(t1 <= t2) {
                ret += (an[t1] - x) * (an[t1] - x);
                ++t1;
        }
        return ret;
}
int main() {
        int n, m;
        while(scanf("%d%d", &n, &m) != EOF) {
                for(int i = 0; i < n; ++i) scanf("%d", an + i);
                std::sort(an, an + n);
                double ans, tmp;
                for(int i = 0, j = m-1; j < n; ++i, ++j) {
                        double t = calc(i, j, m);
                        //out(i); out(t);
                        tmp = calc2(i, j, t) / m;
                        //out(tmp);
                        if(!i) ans = tmp;
                        else if(tmp < ans) ans = tmp;
                }
                printf("%.3f\n", ans);
        }
        return 0;
}
