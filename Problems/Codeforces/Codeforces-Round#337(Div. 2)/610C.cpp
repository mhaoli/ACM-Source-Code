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
using namespace std;
int _;
string modify(string s) {
        for(int i = 0; i < SZ(s); ++i) {
                if(s[i] == '+') s[i] = '*';
                else s[i] = '+';
        }
        return s;
}
int main() {
        vector<string> vec[10];
        vec[0].push_back("+");
        vec[1].push_back("++");
        vec[1].push_back("+*");
        for(int i = 2; i < 10; ++i) {
                for(auto s : vec[i-1]) {
                        vec[i].push_back(s + s);
                        vec[i].push_back(s + modify(s));
                }
        }

        int n;
        while(cin >> n) {
                for(auto s : vec[n]) {
                        std::cout << s << "\n";
                }
        }
        return 0;
}
