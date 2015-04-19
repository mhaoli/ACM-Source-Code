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

using namespace std;

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n, m;
char str[55], ans[55];
int lef[55][55], state[2][55][55];

void transform (const int &now, const int &nxt, const int &tim){
    rep (i, 0, n-1) rep (j, 0, m-1){
        if (state[now][i][j] == -1 || lef[i][j] == tim){
            state[nxt][i][j] = -1; continue;
        }

        int cnt = 0;
        rep (tx, i-1, i+1) rep (ty, j-1, j+1){
            if (tx == i && ty == j) continue;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m){ 
                if (state[now][tx][ty] == 1) ++ cnt; 
            }
            if (state[now][i][j] == 1 && cnt > 3) break;
        }

        if (state[now][i][j] == 1){
            if (cnt < 2 || cnt > 3) state[nxt][i][j] = 0;
            else state[nxt][i][j] = 1;
        } else{
            if (cnt == 3) state[nxt][i][j] = 1;
            else state[nxt][i][j] = 0;
        }
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int L, K;
        scanf ("%d%d%d%d", &n, &m, &L, &K);
        rep (i, 0, n-1){
            scanf ("%s", str);
            rep (j, 0, m-1) state[0][i][j] = str[j] - '0';
        }
            
        clr (lef, -1);
        rep (i, 0, K-1){
            int t, tx, ty;
            scanf ("%d%d%d", &t, &tx, &ty);
            lef[tx-1][ty-1] = t;
        }

        int now = 0, nxt = 1;
        rep (i, 1, L){
            transform (now, nxt, i);
            swap (now, nxt);
        }

        int top = 0;
        rep (i, 0, n-1){
            top = 0;
            while (top < m){
                if (state[now][i][top] == -1) ans[top] = 'X';
                else ans[top] = state[now][i][top] ? '1' : '0';
                ++ top;
            }
            ans[top] = 0;
            puts (ans);
        }
    }
    return 0;
}
