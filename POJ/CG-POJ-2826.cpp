/*
 * Author:  plum rain
 * Created Time:  2013年08月05日 星期一 01时47分58秒
 * File Name: CG-POJ-2826.cpp
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

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{
    double x, y;
}a, b, c, d;

bool equal (point a, point b)
{
    if (!(a.x >= b.x - eps && a.x <= b.x + eps))
        return false;
    if (!(a.y >= b.y - eps && a.y <= b.y + eps))
        return false;
    return true;
}

double Distance (point a, point b)
{
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        bool xxx = false;
        if (equal (a, c)){
            a = d;
            xxx = true;
        }
        else if (equal (a, d)){
            point x = a;
            a = c;
            c = x;
            xxx = true;
        }
        else if (equal (b, c)){
            b = d;
            xxx = true;
        }
        else if (equal (b, d)){
            point x = b;
            b = c;
            c = x;
            xxx = true;
        }
        if (!xxx){
            printf ("0.00\n");
            continue;
        }
        if (a.y >= b.y - eps){
            point x = a;
            a = b;
            b = x;   
        }
        if (a.y <= c.y + eps){
            printf ("0.00\n");
            continue;
        }
        else {
            point x;
            x.y = a.y;
            x.x = b.x - (b.y - a.y) * (b.x - c.x) / (b.y - c.y);
            b = x;
        }
//        cout << a.x << " " << a.y << endl;
//        cout << b.x << " " << b.y << endl;
//        cout << c.x << " " << c.y << endl;
        double a1, a2, a3, p;
        a1 = Distance (a, b);
        a2 = Distance (a, c);
        a3 = Distance (b, c);
        p = (a1 + a2 + a3) / 2;
       double s = sqrt (p * (p-a1) * (p-a2) * (p-a3));
       printf ("%.2f\n", s);
    }
    return 0;
}
