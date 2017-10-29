//Create Time: 2017-10-18 18:58:18
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
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define debug
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;
/****head****/
int cnt[(int)1e6 + 9], an[(int)1e6 + 9];
int main() {
    int n, K; cin >> n >> K;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &an[i]);
    }
    memset(cnt, 0, sizeof cnt);
    int posr = 0, len = 1, num = 1;
    cnt[an[0]]++;
    for(int i = 1, j = 0; i < n; ++i) {
        if(cnt[an[i]] == 0) {
            ++num;
        }
        ++cnt[an[i]];
        while(num > K) {
            if(cnt[an[j]] == 1) {
                --num;
            }
            --cnt[an[j]];
            ++j;
        }
        if(i - j + 1 > len) {
            len = i - j + 1;
            posr = i;
        }
    }
    cout << posr - len + 2 << " " << posr + 1;
    return 0;
}
