#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int mi[1005][1005];
int an[1005];
std::set<int> set;
std::map<int, int> map;
std::vector<int> vec[1005];
std::vector<int>::iterator idx[1005];
int solve(int s, int t) {
        //printf("%d %d\n", s, t);
        if(s > t) return 0;
        //if(s == t) return 1;
        int val = mi[s][t], last = s, ret = 1;
        //if(s == 2 && t == 3) out(val);
        while(idx[val] != vec[val].end() && (*idx[val]) <= t) {
                //if(s == 2 && t == 3) out((*idx[val]));
                ret += solve(last, (*idx[val]) - 1);
                last = (*idx[val]) + 1;
                ++idx[val];
        }
        //if(idx[val] != vec[val].end()) --idx[val];
        //if(s == 0 && t == 0) out(ret);
        return ret + solve(last, t);
}
int main() {
        int n, xt;
        while(scanf("%d", &n) != EOF) {
                set.clear();
                for(int i = 0; i < n; ++i) vec[i].clear();

                for(int i = 0; i < n; ++i) {
                        scanf("%d", an + i);
                        set.insert(an[i]);
                }
                xt = 0;
                snuke(it, set) map[*it] = xt++;
                for(int i = 0; i < n; ++i) an[i] = map[an[i]];
                for(int i = 0; i < n; ++i) vec[an[i]].push_back(i);
                for(int i = 0; i < n; ++i) idx[i] = vec[i].begin();

                for(int i = 0, j; i < n; ++i) {
                        mi[i][i] = an[i];
                        for(j = i + 1; j < n; ++j) {
                                mi[i][j] = std::min(mi[i][j-1], an[j]);
                        }
                }
                printf("%d\n", std::max(0, solve(0, n-1)));
        }
        return 0;
}
