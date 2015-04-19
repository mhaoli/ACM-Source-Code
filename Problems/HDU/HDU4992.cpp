/*
 * Author:  Plumrain
 * Created Time:  2014/12/5 19:28:43
 * File Name: HDU4992.cpp
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
#define snuke(i,x) for(__typeof(x.begin()) i = (x).begin(); i != (x).end(); ++i)
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

const int Max_N = 9 + (int)1e6;
ll mod;
bool check[Max_N], pr[Max_N];
int prm[Max_N], tot, phi[Max_N];
int fac[Max_N], fac_tot;

int phi_table(int n){
        clr (check, 0); phi[1] = 1;
        int tot = 0;
        for (int i = 2, j; i <= n; ++ i){
                if (!check[i]) prm[ tot++ ] = i, phi[i] = i - 1;
                for (j = 0; j < tot; j ++){
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

int pow_mod(ll p, int n) {
        ll ret = 1;
        for(; n; n >>= 1) {
                if(n & 1) ret = ret * p % mod;
                p = p * p % mod;
        }
        return ret;
}

void devide(int n, bool fg) {
        fac_tot = 0;
        if(fg && n % 2 == 0) n >>= 1;
        for(int i = 0; i < tot && prm[i]*prm[i] <= n; ++i) if(n % prm[i] == 0){
                while(n % prm[i] == 0) n /= prm[i];
                fac[fac_tot++] = prm[i];
                if(fg && fac_tot > 1) return;
        }
        if(n > 1) fac[fac_tot++] = n;
}

bool solve(int n, vector<int> &ans) {
        mod = n; ans.clear();
        if(n == 2) ans.pb(1);
        else if(n == 4) ans.pb(3);
        else if(n == 1 || n % 4 == 0) return 0;
        else {
                devide(n, 1);
                if(fac_tot > 1) return 0;
                else {
                        devide(phi[n], 0);
                        int res = -1;
                        for(int i = 2, can, j; i < n; ++i) if(pow_mod(i, phi[n]) == 1 && __gcd(i, n) == 1) {
                                can = 1;
                                for(j = 0; j < fac_tot; ++j) if(pow_mod(i, phi[n] / fac[j]) == 1) {
                                        can = 0; break;
                                }
                                if(can) {
                                        res = i; break;
                                }
                        }

                        for(int i = 1; i < phi[n]; ++i) if(__gcd(i, phi[n]) == 1) ans.pb(pow_mod(res, i));
                        std::sort(ans.begin(), ans.end());
                }
        }
        return 1;
}

int main()
{
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        tot = phi_table(Max_N - 5);
        vi ans;
        for(int n; scanf("%d", &n) != EOF; ) {
                if(!solve(n, ans)) puts("-1");
                else {
                        snuke(it, ans) {
                                if(it != ans.begin()) putchar(' ');
                                printf("%d", *it);
                        }
                        puts("");
                }
        }
        return 0;
}
