//Create Time: 2017-10-14 12:01:33
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
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char bd[1111][1111], ans[1111][1111];
int num[1111*1111], label[1111][1111];
int n, m;
bool ins(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int x, int y, int lb) {
    if(bd[x][y] == '*') return;
    label[x][y] = lb;
    for(int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if(ins(tx, ty) && label[tx][ty] == 0) dfs(tx, ty, lb);
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) scanf("%s", bd[i]);
    int idx = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(label[i][j] == 0) dfs(i, j, idx++);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ++num[label[i][j]];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) ans[i][j] = bd[i][j];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) if(ans[i][j] == '*') {
            int cnt = 1;
            map<int, int> has;
            for(int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if(ins(x,y) && bd[x][y] == '.')  has[label[x][y]] = num[label[x][y]];
            }
            for(auto pr: has) {
                cnt += pr.y;
            }
            ans[i][j] = (cnt % 10) + '0';
        }
    }
    for(int i = 0; i < n; ++i) {
        puts(ans[i]);
    }
    return 0;
}
