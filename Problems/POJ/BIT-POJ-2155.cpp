/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: BIT-POJ-2155.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<cctype>
#include<ctime>
#include<utility>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define lowbit(x) ((x)&(-x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n;
char s[100];
int c[1005][1005];

void add(int x, int y)
{
    int yy = y;
    while (x > 0){
        y = yy;
        while (y > 0){
            c[x][y] ^= 1;
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
}

int sum(int x, int y)
{
    int ret = 0, yy = y;
    while (x <= n){
        y = yy;
        while (y <= n){
            ret ^= c[x][y];
            y += lowbit(y);
        }
        x += lowbit(x);
    }
    return ret;
}

void gao1()
{
    int x1, y1, x2, y2;
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    add (x1-1, y1-1); add (x2, y2); add (x1-1, y2); add (x2, y1-1);
}

void gao2()
{
    int x, y;
    scanf ("%d%d", &x, &y);
    printf ("%d\n", sum(x, y));
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int q;
        scanf ("%d%d", &n, &q);
        clr (c);
        while (q--){
            scanf ("%s", s);
            if (s[0] == 'C') gao1();
            else gao2();
        }

        if (T) printf ("\n");
    }
    return 0;
}
