#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_M = 59;
const int Max_N = 9 + (int)1e7;
std::vector<int> vec[Max_M];
bool check[Max_N];
int prm[Max_N/5], cnt[Max_N];
int init(int n){
        int tot = 0;
        cnt[1] = 0;
        vec[0].push_back(1);
        for(int i = 2; i <= n; ++ i) {
                if(!check[i]) prm[tot++] = i, vec[cnt[i] = 1].push_back(i);
                for(int j = 0; j < tot; j ++) {
                        if(i * prm[j] > n) break;
                        check[i*prm[j]] = 1;
                        if(i % prm[j] == 0) {
                                vec[cnt[i*prm[j]] = cnt[i]].push_back(i * prm[j]);
                                break;
                        } else vec[cnt[i*prm[j]] = cnt[i] + 1].push_back(i * prm[j]);
                }
        }
        for(int i = 0; i < Max_M; ++i) std::sort(vec[i].begin(), vec[i].end());
        return tot;
}
int query(int l, int r, std::vector<int> &A) {
        return upper_bound(A.begin(), A.end(), r) - lower_bound(A.begin(), A.end(), l);
}
int main() {
        freopen("homework.txt","r",stdin);
        freopen("A.out","w",stdout);
        int tot = init(Max_N - 5);
        int _; scanf("%d", &_);
        for(int l, r, K, cas = 0; _--; ) {
                scanf("%d%d%d", &l, &r, &K);
                printf("Case #%d: %d\n", ++cas, query(l, r, vec[K]));
        }
        return 0;
}
