/*
 * Author:  plum rain
 * Created Time:  2013年08月05日 星期一 14时24分19秒
 * File Name: F.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<utility>
#include <iomanip>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 155;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

double pob[N];
int ask[N];

void Print (double x)
{
    int num = 0;
    while (x <= 1.0 - eps){
        x *= 10;
        num ++;
    }
    cout << fixed;
    cout << setprecision(5) << x << " x 10^" << -1 * num << endl;
}

double fac (double x, int num)
{
    rep (i, num)
        x *= (pob[ask[i]] * (i+1));
    return x;
}

double cac(double x, int num)
{
    while (num > 1){
        x /= (num + 0.0);
        num --;
    }
    return x;
}

int main()
{
//    freopen("F.in","r",stdin);
//    freopen("a.out","w",stdout);
//    ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        int n;
        cin >> n;
        repf (i, 1, n)
            cin >> pob[i];        
        int m;
        cin >> m;
        cout << "Test Case #" << ++test << ":" << endl;
        while (m --){
            int cnt;
            double ans = 1.0;
            cin >> cnt;
            rep (i, cnt)
                cin >> ask[i];
            ans = fac (ans, cnt);
            sort (ask, ask + cnt);
            int tmp = ask[0], num = 1;
            repf (i, 1, cnt-1){
                if (tmp == ask[i]){
                    num ++;
                    continue;
                }
                ans = cac(ans, num);
                tmp = ask[i];
                num = 1;
            }
            ans = cac (ans, num);
            Print (ans);
        }
    }
    return 0;
}
