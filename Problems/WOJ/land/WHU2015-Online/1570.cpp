#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
using namespace std;
int an[111], mid, n, m, tmid;
double bn[111];
const int inf = (int)1e9;
vector<double> vec[20], vec2[20];
int cnt[1<<16];
double sum[1<<16];
double Sum(double x) {
        double ret = 0;
        for(int i = 0; i < n; ++i) ret += (an[i] - x) * (an[i] - x);
        return ret;
}
double Three() {
        double l = 0, r = inf, t1, t2, tmp;
        for(int tim = 0; tim < 600; ++tim) {
                tmp = (r - l) / 3;
                t1 = l + tmp; t2 = r - tmp;
                if(Sum(t1) > Sum(t2)) l = t1;
                else r = t2;
        }
        return l;
}
void ZuiYou(double&a, double b, double t) {
        if(fabs(b-t) < fabs(a-t)) a = b;
}
double calc(int xttm, double t) {
        const vector<double>&V = vec[xttm];
        vector<double>::iterator it = lower_bound(vec[xttm].begin(), vec[xttm].end(), t);
        double ret = it == V.end() ? (*(it-1)) : (*it);
        if(it != V.begin()) ZuiYou(ret, *(it-1), t);
        if(it != V.end() && (it + 1) != V.end()) ZuiYou(ret, *(it+1), t);
        return ret;
}
int main() {
        while(scanf("%d%d", &n, &m) != EOF) {
                for(int i = 0; i < n; ++i) scanf("%d", an + i);
                double tmp = Three();
                out(tmp);
                mid = n >> 1;
                
                sum[0] = 0; cnt[0] = 0;
                for(int i = 0; i < mid; ++i) {
                        sum[1<<i] = an[i] / (m + 0.0);
                        cnt[1<<i] = 1;
                }
                for(int i = 0; i <= mid; ++i) vec[i].clear();
                for(int i = 1, xt; i < (1<<mid); ++i) {
                        xt = i & (-i);
                        sum[i] = sum[xt] + sum[i^xt];
                        cnt[i] = 1 + cnt[i^xt];
                        vec[cnt[i]].push_back(sum[i]);
                }
                for(int i = 1; i <= mid; ++i) sort(vec[i].begin(), vec[i].end());

                tmid = n - mid;
                sum[0] = 0; cnt[0] = 0;
                for(int i = 0; i < tmid; ++i) {
                        sum[1<<i] = an[i + mid] / (m + 0.0);
                        cnt[1<<i] = 1;
                }
                for(int i = 0; i < tmid; ++i) vec2[i].clear();
                for(int i = 1, xt; i < (1<<tmid); ++i) {
                        xt = i & (-i);
                        sum[i] = sum[xt] + sum[i^xt];
                        cnt[i] = 1 + cnt[i^xt];
                        vec2[cnt[i]].push_back(sum[i]);
                }
                for(int i = 1; i <= tmid; ++i) sort(vec2[i].begin(), vec2[i].end());
                
                //snuke(it, vec[1]) printf("%.3f ", *it);
                //puts("");
                //snuke(it, vec2[1]) printf("%.3f ", *it);
//
                double ans = 2 * inf;
                for(int i = 1; i <= tmid && i <= m; ++i) {
                        if(i == m) snuke(it, vec2[i]) ZuiYou(ans, *it, tmp);
                        else if(m - i <= mid) snuke(it, vec2[i]) ZuiYou(ans, (*it) + calc(m - i, tmp - (*it)), tmp);
                }
                out(ans);
                printf("%.3f\n", Sum(ans) / n);
        }
        return 0;
}
