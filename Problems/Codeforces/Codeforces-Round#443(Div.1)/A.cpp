//Create Time: 2017-10-26 23:25:22
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
const int Max_N = (int)5e5 + 9;
char opt[Max_N];
int opt_num[Max_N];
int dir[4][3] = {
    0,0,0,
    1,0,0,
    1,0,1,
    1,1,0
};
int gao(int x, char c, int cons){
    if(c == '&') return x & cons;
    if(c == '|') return x | cons;
    return x ^ cons;
}
int main() {
    //rep(i,0,4) {
        //rep(j,0,3) cout << dir[i][j] << " ";
        //cout << endl;
    //}
    int n; cin >> n;
    char tmp[10];
    rep(i,0,n){
        scanf("%s%d", tmp, opt_num+i);
        opt[i] = tmp[0];
    }
    int a = 0, b = 1023;
    rep(i,0,n) {
        a = gao(a, opt[i], opt_num[i]);
        b = gao(b, opt[i], opt_num[i]);
    }
    int ans[3] = {0,0,0}, offset = 1;
    rep(i,0,10) {
        int t = (a & 1) * 2 + (b & 1);
        a >>= 1; b >>= 1;
        rep(j,0,3) {
            ans[j] += offset * dir[t][j];
        }
        offset <<= 1;
    }
    cout << "3" << endl;
    cout << "& " << ans[0] << endl;
    cout << "| " << ans[1] << endl;
    cout << "^ " << ans[2] << endl;
    return 0;
}
