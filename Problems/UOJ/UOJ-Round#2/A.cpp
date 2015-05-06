#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int _;
const int Max_N = 9 + (int)3e5;
std::vector<std::pair<int, int> > ans;
char str[Max_N];
inline int calc(const char &c) {
        return c == '(' ? 1 : -1;
}
int main() {
        scanf("%s", str);
        int n = strlen(str), sum = 0;
        for(int i = 0, j; i < n; ) {
                sum += calc(str[i]);
                if(sum < 0) {
                        for(j = i+1; j < n && sum; ++j) sum += calc(str[j]);
                        if(sum < 0) return puts("-1"), 0;
                        ans.push_back(std::make_pair(i + 1, j));
                        i = j;
                } else ++i;
        }
        printf("%d\n", ans.size());
        snuke(it, ans) printf("%d %d\n", it->first, it->second);
        return 0;
}
