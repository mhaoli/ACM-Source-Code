/*
 * Author:  Plumrain
 * Created Time:  2014/9/12 19:29:53
 * File Name: C.cpp
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
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(1e5) + 9;
map<int, int> has;
int idx[maxn], n;
pii cor[maxn];
pair<int, double> an[maxn];

inline void Read(int &ret){
    ret = 0;
    bool ok = 0, u = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
        else if (c == '-') u = 1;
		else if (ok){
            if (u) ret *= -1;
            return ;
        }
	}
}

double change (int &p1, int &p2, const int &p){
    if (p1 < 0){
        ++ p2;
        return an[cor[p2-1].y].y;
    } else if (p2 >= n){
        -- p1;
        return an[cor[p1+1].y].y;
    } else{
        int dif1 = p - cor[p1].x, dif2 = cor[p2].x - p;
        if (dif1 < dif2 || (dif1 == dif2 && cor[p1].y < cor[p2].y)){
            -- p1; return an[cor[p1+1].y].y;
        } else{
            ++ p2; return an[cor[p2-1].y].y;
        }
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int m, k;
        Read (n); Read (m); Read (k);
        rep (i, 0, n-1){
            int t; Read (an[i].x); Read (t);
            an[i].y = t;
            cor[i].x = an[i].x; cor[i].y = i;
        }
        sort (cor, cor + n);
        rep (i, 0, n-1) idx[cor[i].y] = i;

        double ans = 0;
        rep (xt, 0, m-1){
            int t; Read (t); -- t;
            int p1 = idx[t] - 1, p2 = idx[t] + 1;
            double sum = 0;
            rep (i, 0, k-1){
                sum += change (p1, p2, an[t].x);
            }
            sum /= k;

            ans += sum;
            an[t].y = sum;
        }
        printf ("%.6f\n", ans);
    }
    return 0;
}
