#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 1111;
const int Max_M = 500005;

bool v[Max_N];
int match[Max_N];
std::vector<int> an[Max_N];
int bn[Max_N], cnt[Max_M];

void add(int t1, int t2) {
        an[t1].push_back(t2);
        an[t2].push_back(t1);
}
bool cross(int x) {
        for(int i = 0, p; i < (int)an[x].size(); ++i) {
                p = an[x][i];
                if(!v[p]) {
                        v[p] = 1;
                        if(match[p] == -1 || cross(match[p])) {
                                match[p] = x; return 1;
                        }
                }
        }
        return 0;
}
int hungary(int n) {
        int ret = 0;
        memset(match, -1, sizeof match);
        for(int i = 0; i < n; ++i) if(cnt[bn[i]] & 1){
                memset(v, 0, sizeof v);
                if(cross(i)) ++ret;
        }
        return ret;
}

bool check[Max_M+5];
int prm[Max_M+5];

int primes(int n){
    int tot = 0;
    cnt[0] = cnt[1] = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i, cnt[i] = 1;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            cnt[i*prm[j]] = cnt[i] + 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}
int _;
void init(int n) {
        for(int i = 0; i < n; ++i) an[i].clear();
}
bool Check(int t1, int t2) {
        if(t1 < t2) std::swap(t1, t2);
        if(t1 % t2) return 0;
        return !check[t1/t2];
}
int main() {
        int tot = primes(Max_M), n;
        for(scanf("%d", &_); _--; ) {
                scanf("%d", &n);
                init(n);
                for(int i = 0; i < n; ++i) {
                        scanf("%d", bn + i);
                }
                for(int i = 0, j; i < n; ++i) {
                        for(j = i+1; j < n; ++j) if(Check(bn[i], bn[j])) {
                                add(i, j);
                        }
                }
                static int cas = 0;
                printf("Case #%d: %d\n", ++cas, n - hungary(n));
        }
        return 0;
}
