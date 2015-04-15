/*
 * Author:  plum rain
 * Created Time:  2013-08-14 13:28
 * File Name: 
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
#define zero(x) (((x)>0?(x):-(x))<eps)
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
const int maxx = 1000;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int hash[250][250];

char solve(int x, int y)
{
    if (x == 0 && y == 0) return '+';
    if (x == 0) return '|';
    if (y == 0) return '-';
    return '.';
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
//    while (scanf ("%d", &n) != EOF){
    scanf ("%d", &n);
        int xmin = maxx, xmax = -1 * maxx, ymin = maxx, ymax = -1 * maxx;
        CLR (hash);
        
        int x, y;
        for (int i = 0; i < n; ++ i){
           scanf ("%d%d", &x, &y);
           hash[x+100][y+100] = true;
           xmin = min(xmin, x), ymin = min (y, ymin);
           xmax = max(xmax, x), ymax = max (y, ymax);
        }

        xmax = max(0, xmax), xmin = min(0, xmin), ymin = min(0, ymin), ymax = max(0, ymax);

//        out (xmin), out(xmax), out(ymin), out(ymax);
//        out (hash[90][105]);
        
        for (int i = ymax; i >= ymin; -- i){
            for (int j = xmin; j <= xmax; ++ j){
                if (hash[j+100][i+100]) printf ("*");
                else printf ("%c", solve(j, i));
            }
            printf ("\n");
        }
//    }
    return 0;
}
