/*
 * Author:  Plumrain
 * Created Time:  2014/12/4 20:26:49
 * File Name: 487C.cpp
 */
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
#include<functional>
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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int Max_N = (int)1e5 + 9;
bool check[Max_N];
int prm[Max_N], tot;
ll mod;

void primes(int n) {
        tot = 0;
        for(int j, i = 2; i < n; ++i) {
                if(!check[i]) prm[tot++] = i;
                for(j = 0; j < tot && i*prm[j] <= n; ++j) {
                        check[i*prm[j]] = 1;
                        if(i % prm[j] == 0) break;
                }
        }
}

ll pow_mod(ll p, int n) {
        ll ret = 1;
        for(; n; n >>= 1) {
                if(n & 1) ret = ret * p % mod;
                p = p * p % mod;
        }
        return ret;
}

int main()
{
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        primes(Max_N - 5);
        int n; scanf("%d", &n);
        if(n == 1) puts("YES\n1");
        else if(n == 4) puts("YES\n1 3 2 4");
        else if(check[n]) puts("NO");
        else {
                puts("YES");
                mod = n;
                puts("1");
                for(int i = 2; i < n; ++i)
                        printf("%d\n", i * pow_mod(i - 1, mod-2) % mod);
                printf("%d\n", n);
        }
        return 0;
}
