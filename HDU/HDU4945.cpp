/*
 * Author:  OpenRainbow
 * Created Time:  2014/8/14 15:26:56
 * File Name: 1001.cpp
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
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef __int64 int64;
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
const int64 mod = 998244353;
const int maxn = (1e5) + 10;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 cn[5000];
int d[13][3000], inv[maxn], two[maxn];
int num[100], num0, idx[3000];

inline void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

inline int R(){
	int ret = 0;
    bool ok = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + ret + ret + c - '0', ok = 1;
		else if (ok) return ret;
	}
}

void init (){
    clr (idx, -1);
    repf (i, 0, 11) idx[1<<i] = i;
    
    repf (i, 0, maxn-5) two[i] = i ? (two[i-1]<<1) % mod : 1;

    inv[1] = 1;
    repf (i, 2, maxn-5) inv[i] = (mod - mod/i) * inv[mod%i] % mod;
}

int calc (const int &x, const int &n){
    if (x > n) return 0;
    int ret = two[n];
    int64 tmp_c = 1;
    repf (i, 0, x-1){
        add(ret, mod - tmp_c);

        tmp_c = tmp_c * (n - i) % mod;
        tmp_c = tmp_c * inv[i+1] % mod;
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init();

    int n, cas = 0;
    while (n = R()){
        clr (num, 0); num0 = 0;
        repf (i, 0, n-1){
            int t = R();
            if (~idx[t]) ++ num[idx[t]];
            else ++ num0;
        }

        clr (d, 0);
        int ans = 0, up = min ((1<<11)-1, num[0]);
        int64 tmp_c = 1;
        repf (i, 0, up){
            d[0][i] = tmp_c;
            tmp_c = tmp_c * (num[0] - i) % mod;
            tmp_c = tmp_c * inv[i+1] % mod;
        }
        if (num[0] >= (1<<11)) add (d[0][1<<11], calc (1<<11, num[0]));

        repf (i, 1, 11){
            int64 xxt = calc (1<<(11-i), num[i]);
            up = min ((1<<(11-i)) - 1, num[i]);
            cn[0] = 1;
            repf (j, 0, up-1){
                cn[j+1] = cn[j] * (num[i]-j) % mod;
                cn[j+1] = cn[j+1] * inv[j+1] % mod;
            }

            repf (k, 0, 1<<(12-i)) if (d[i-1][k]){
                repf (j, 0, up){
                    int tval = j + (k >> 1);
                    if (tval >= (1<<(11-i))) tval = 1 << (11-i);
                    add (d[i][tval], d[i-1][k] * cn[j] % mod);
                }
                if (num[i] >= 1 << (11-i)) add (d[i][1<<(11-i)], xxt * d[i-1][k] % mod);
            }
        }

        ans = 1LL * d[11][1] * calc (0, num0) % mod;
        printf ("Case #%d: %d\n", ++ cas, ans);
    }
    return 0;
}
