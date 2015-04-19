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

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
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
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int n;
char up;
char ans[1111], str[1111];

bool ok (int p, int c, char *str){
    if (p && str[p-1] == c) return 0;
    if (p > 1 && str[p-2] == c) return 0;
    return 1;
}

bool check (int p, char *str){
    rep (i, p, n-1){
        ans[i] = 0;
        rep (j, 'a', up) if (ok (i, j, str)){
            ans[i] = j; break;
        }
        if (!ans[i]) return 0;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int p;
    while (scanf ("%d%d", &n, &p) != EOF){
        up = 'a' + p - 1;
        scanf ("%s", str);
        bool ans_u = 0;
        red (i, n-1, 0){
            rep (j, 0, i-1) ans[j] = str[j];
            rep (j, str[i]+1, up){
                ans[i] = j;
                if (ok (i, j, str) && check (i+1, ans)){
                    ans_u = 1; break;
                }
            }
            if (ans_u) break;
        }
        if (ans_u){
            ans[n] = 0;
            puts (ans);
        } else puts ("NO");
    }
    return 0;
}