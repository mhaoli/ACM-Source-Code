/*
other:
        http://codeforces.com/contest/611/submission/15103472
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
int main() {
        long long a, b;
        while(std::cin >> a >> b) {
                std::vector<std::pair<long long, long long> > vec;
                long long mask = 2, len = 1;
                while(mask <= b) {
                        vec.push_back(std::make_pair(mask, len));
                        mask <<= 1;
                        ++len;
                }
                std::vector<long long> ans;
                for(auto i : vec) {
                        for(auto j : vec) {
                                if(i.second + j.second + 1 > 60) continue;
                                ans.push_back((i.first - 1) << (j.second + 1) | (j.first - 1));
                        }
                        ans.push_back((i.first - 1) << 1);
                }
                //for(auto i : ans) std::cout << i << " ";
                std::sort(ans.begin(), ans.end());
                int cnt = 0;
                for(auto i : ans) if(i >= a && i <= b) ++cnt;
                printf("%d\n", cnt);
        }
        return 0;
}
