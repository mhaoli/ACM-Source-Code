/*
 * Author:  Plumrain
 * Created Time:  2014/12/5 11:49:51
 * File Name: POJ1284.cpp
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

const int maxn = 70000;
int prm[maxn+5], phi[maxn+5];
bool check[maxn+5];

int phi_table(int n) {
    clr (check, 0); phi[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[ tot++ ] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[ i*prm[j] ] = 1;
            if (i % prm[j] == 0){
                phi[ i*prm[j] ] = phi[i] * prm[j]; break;
            }
            else phi[ i*prm[j] ] = phi[i] * (prm[j] - 1);
        }
    }
    return tot;
}

int main()
{
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        phi_table(maxn);
        for(int n; scanf("%d", &n) != EOF; ) printf("%d\n", phi[n - 1]);
        return 0;
}
