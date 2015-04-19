/*
 * Author:  plum rain
 * Created Time:  2013-08-23 15:13
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
const int N = 50005;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

int a[N], num[48000];

int init()
{
    int time, tmp = 0;
    char x;
    scanf ("%d", &time);
    if (time == 12) time = 0;
    else time *= 3600;
    scanf ("%c%d", &x, &tmp);
    time += tmp * 60;
    scanf ("%c%d", &x, &tmp);
    time += tmp;
    ++ num[time];
    return time;
}

void Print (int x)
{
    int h, m, s;
    if (x < 3600){
        h = 12; 
    }
    else {
        h = x / 3600;
        x -= h * 3600;
    }
    m = x / 60;
    s = x - m * 60;

    printf ("%d:", h);
    if (m < 10) printf ("0");
    printf ("%d:", m);
    if (s < 10) printf ("0");
    printf ("%d\n", s);
}

void solve(int n)
{
    int64 cir = 12 * 3600;
    int64 tmp = 0;
    for (int i = 0; i < n; ++ i)
        if (a[i])
        tmp += (int64)(cir - a[i]);
   
    int64 ans = tmp;
    int flag = 0;
    for (int i = 1; i < cir; ++ i){
        tmp += n;
        tmp -= num[i] * cir;
        if (ans > tmp){
            ans = tmp;
            flag = i;
        }
    }

    Print (flag);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        CLR (a);
        CLR (num);
        for (int i = 0; i < n; ++ i)
            a[i] = init();
        sort (a, a+n);
        solve (n);
    }
    return 0;
}
