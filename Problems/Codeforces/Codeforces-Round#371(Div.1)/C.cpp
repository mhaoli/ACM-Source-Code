//Learn from: https://code.icpc-camp.org/ftiasch/acm-icpc/src/master/codeforces/713-codeforces-round-371/C.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
/****head****/
int main() {
        int n;
        cin >> n;
        VI vec(n);
        for(int i = 0; i < n; ++i) {
                cin >> vec[i];
                vec[i] -= i;
        }

        vector<PII> stk;
        for(int i = 0; i < n; ++i) {
                PII last(vec[i], i);
                while(!stk.empty() && stk.back().x > last.x) {
                        VI v(vec.begin() + stk.back().y, vec.begin() + i + 1);
                        nth_element(v.begin(), v.begin() + (SZ(v)>>1), v.end());
                        last = PII(v[SZ(v)>>1], stk.back().y);
                        stk.pop_back();
                }
                stk.pb(last);
        }

        ll res = 0;
        stk.pb(PII(0, n));
        for(int i = 0; i < SZ(stk)-1; ++i) {
                for(int j = stk[i].y; j < stk[i+1].y; ++j) {
                        res += abs(stk[i].x - vec[j]);
                }
        }
        cout << res;
        return 0;
}
