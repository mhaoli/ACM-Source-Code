/*
 * Author:  plum rain
 * Created Time:  Sun 11 Aug 2013 12:24:27 AM CST
 * File Name: CG-POJ-1113.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)
#define zero(x) (((x)>0?(x):-(x))<eps)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

struct pnt{
    int x, y;
};

pnt poi[1005], cvx[1005];

int xmult(pnt p1, pnt p2, pnt p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double dis(pnt a, pnt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + 0.0);
}

bool cmp(pnt a, pnt b)
{
    if (xmult (a, b, poi[0]) > 0)
        return true;
    if (!xmult(a, b, poi[0]) && dis(a, poi[0]) < (dis(b, poi[0]) + eps))
        return true;
    return false;
}

int graham(int n, pnt *p, pnt *sk)
{
    for (int i =1; i < n; ++ i)
        if (p[0].y > p[i].y || (p[0].y == p[i].y && p[0].x > p[i].x)){
            pnt tmp = p[0];
            p[0] = p[i];
            p[i] = tmp;
        }
    sort (p+1, p+n, cmp);
    for (int i = 0; i < 3; ++ i)
        sk[i] = p[i];
    int tp = 2;
    for (int i = 3; i < n; ++ i){
        while (xmult (sk[tp], p[i], sk[tp-1]) < 0)
            tp --;
        sk[++tp] = p[i];
    }
    return tp + 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, l;
    while (scanf ("%d%d", &n, &l) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d%d", &poi[i].x, &poi[i].y);
        int num = graham(n, poi, cvx);
//        for (int i = 0; i < num; ++ i)
//            cout << cvx[i].x << " " << cvx[i].y << endl;
        double sum = PI * (double)l * 2;
        for(int i = 1; i < num; ++ i)
            sum += dis(cvx[i], cvx[i-1]);
        sum += dis(cvx[num-1], cvx[0]);
        printf ("%d\n", (int)(sum + 0.5));
    }
    return 0;
}
