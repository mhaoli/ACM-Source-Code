#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e4;
struct oo;
oo *idx;
struct oo {
        char str[333];
        int n;
        std::string p;
        void read() {
                scanf("%s", str);
                for(n = 0; str[n] && !(str[n] > '0' && str[n] <= '9'); ++n);
                p.clear();
                for(; str[n] && str[n] >= '0' && str[n] <= '9'; ++n) {
                        p.push_back(str[n]);
                }
                //std::cout << p << std::endl;
        }
        bool operator<(const oo&rhm) const {
                if(p.size() > rhm.p.size()) return 0;
                if(p.size() < rhm.p.size()) return 1;
                return p < rhm.p;
        }
}an[Max_N];
int main() {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) an[i].read();
        std::sort(an, an + n); 
        for(int i = 0; i < n; ++i) puts(an[i].str);
        return 0;
}
