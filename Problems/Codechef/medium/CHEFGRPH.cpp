#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
const long long mod = 7 + (int)1e9;

std::pair<long long, int> a[Max_N][2];
std::set<long long> set;
std::map<long long, int> map;
long long pos[Max_N];
int f[Max_N], g[Max_N];

std::set<std::pair<long long, int> > set2;
std::map<std::pair<long long, int>, int> map2;
std::vector<int> start[Max_N];
std::set<int> arrive[Max_N];
int idx[Max_N][2];

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        long long n;
        int m, k;
        Read(n); Read(m); Read(k);
        for(int i = 0, j; i < k; ++i) {
                for(j = 0; j < 2; ++j) {
                        Read(a[i][j].first); Read(a[i][j].second);
                        set.insert(a[i][j].first);
                }
        }
        set.insert(0); set.insert(n + 1);
        int cnt = 0;
        snuke(it, set) map[*it] = cnt, pos[cnt++] = *it;

        for(int i = 0, j; i < k; ++i) {
                for(j = 0; j < 2; ++j) set2.insert(a[i][j]);
        }
        int cnt2 = 0;
        snuke(it, set2) map2[*it] = cnt2++;
        for(int i = 0, j; i < k; ++i) {
                for(j = 0; j < 2; ++j) {
                        idx[i][j] = map2[a[i][j]];
                }
                start[map[a[i][0].first]].push_back(i);
                arrive[map[a[i][1].first]].insert(idx[i][1]);
        }
        
        f[0] = 1;
        snuke(it, start[0]) add(g[idx[*it][1]], f[0]), add(g[idx[*it][1]], g[idx[*it][0]]);
        for(int i = 1; i < cnt; ++i) {
                if(i == 1) add(f[i], f[i-1] * pow_mod(m,  pos[i] - pos[i-1] - 1, mod) % mod);
                else add(f[i], f[i-1] * pow_mod(m, pos[i] - pos[i-1], mod) % mod);

                snuke(it, start[i]) add(g[idx[*it][1]], f[i]), add(g[idx[*it][1]], g[idx[*it][0]]);

                if(i < cnt-1) snuke(it, arrive[i]) add(f[i+1], g[*it] * pow_mod(m, pos[i+1] - pos[i] - 1, mod) % mod);
        }

        //for(int i = 0; i < cnt; ++i)
                //printf("%I64d %d\n", pos[i], f[i]);
//
        snuke(it, arrive[cnt-1]) add(f[cnt-1], g[*it]);
        printf("%d\n", f[cnt-1]);
        return 0;
}
