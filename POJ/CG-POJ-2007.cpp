/*
 * Author:  plum rain
 * Created Time:  Sun 11 Aug 2013 11:25:32 PM CST
 * File Name: CG-POJ-2007.cpp
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
const int N = 1005;

inline int Mymod( int a , int b ) { int x=a%b;if(x<0) x+=b;return x;}

struct pnt{int x,y;};
struct vct{int x,y;};
const vct o = {0, 0};
vct operator - (pnt s, pnt t){
    vct ret = {t.x - s.x, t.y - s.y};
    return ret;
}
bool operator == (pnt a, pnt b){
    return ((a.x == b.x) && (a.y == b.y));
}
double operator * (vct a, vct b){
    return a.x * b.y - a.y * b.x;
}

pnt p[N], sta;
int n;

double dis (pnt a, pnt b)
{
    return sqrt (0.0 + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(pnt a, pnt b)
{
    if ((a - p[0]) * (b - p[0]) > eps)
        return true;
    if (zero ((a-p[0]) * (b-p[0])) && dis (a, p[0]) < dis (b, p[0]) + eps)
        return true;
    return false;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    scanf ("%d%d", &sta.x, &sta.y);
    p[0].x = sta.x, p[0].y = sta.y;
    n = 0;
    pnt tmp;
    while (scanf ("%d%d", &tmp.x, &tmp.y) !=EOF){ 
        p[++n] = tmp;
    }
    ++ n;
    for (int i = 1; i < n; ++ i)
        if (p[0].y > p[i].y || (p[0].y == p[i].y && p[0].x > p[i].y)){
            pnt tmp = p[0];
            p[0] = p[i];
            p[i] = tmp;
        }
    sort (p+1, p+n, cmp);
    int pos = 0;
    for (int i = 0; i < n; ++ i)
        if (p[i] == sta){
            pos = i;
            break;
        }
    int flag = Mymod (pos-1, n);
    while (1){
        printf ("(%d,%d)\n", p[pos].x, p[pos].y);
        if (pos == flag)
            break;
        pos = (pos+1) % n;
    }
    return 0;
}
