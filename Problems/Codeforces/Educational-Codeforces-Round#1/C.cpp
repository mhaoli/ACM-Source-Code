//Create Time: 2017-08-20 23:44:21
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
typedef pair<long double, long double> pdd;
const int Max_N = (int)1e5 + 9;
struct oo {
    long double angle, x, y;
    int idx;
    long double norm() {
        return sqrt(x*x + y*y);
    }
}an[Max_N];
bool cmp(oo a, oo b) {
    return a.angle < b.angle;
}
int main() {
    int n; cin >> n;
    rep(i, 0, n) {
        cin >> an[i].x >> an[i].y;
        an[i].angle = atan2(an[i].y, an[i].x);
        an[i].idx = i;
    }
    sort(an, an + n, cmp);
    an[n] = an[0];

    const long double PI = acos(-1.0l);
    long double mx = PI + 0.1l;
    pii ans;
    rep(i, 0, n) {
        long double diff = an[i+1].angle - an[i].angle;
        if(i == n-1) diff += PI * 2.0l;
        if(diff < mx) {
            ans = pii(an[i].idx, an[i+1].idx);
            mx = diff;
        }
    }
    cout << ans.x+1 << " " << ans.y+1 << endl;
    return 0;
}
