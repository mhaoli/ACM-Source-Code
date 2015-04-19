/*
 * Author:  Plumrain
 * Created Time:  2014-02-13 13:12
 * File Name: G.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
struct nod{
    int a, b, idx;
    double cha;
};

int an[2000];
pii bn[2000];
nod cn[2000];
bool v[2000];
int n, m, y;

bool cmp(nod a, nod b)
{
    return a.cha < b.cha - eps;
}

void gao1()
{
    int sum = 0;
    bool u = 0;
    for (int i = 0; i < n; ++ i){
        if (i) printf (" ");

        if (u) printf ("0");
        else if (sum + bn[i].first > m) u = 1, printf ("%d", m - sum);
        else sum += bn[i].first, printf ("%d", bn[i].first);
    }
}

void gao2()
{
    int sum = 0;
    for (int i = 0; i < n-1; ++ i)
        sum += bn[i].second, printf ("%d ", bn[i].second);
    printf ("%d", m - sum);
}

void gao3(int cnt)
{
    for (int i = 0; i < n; ++ i){
        double tmp = (double)an[i] / y;
        cn[i].a = bn[i].first; cn[i].b = bn[i].second;
        cn[i].cha = fabs (tmp - (double)cn[i].a/m) - fabs(tmp - (double)cn[i].b/m);
        cn[i].idx = i;
    }
    sort (cn, cn+n, cmp);

    clr (v);
    for (int i = 0; i < cnt; ++ i) v[cn[i].idx] = 1;
    for (int i = 0; i < n; ++ i){
        if (i) printf (" ");
        printf ("%d", v[i] ? bn[i].first : bn[i].second);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    bool u = 0;
    scanf ("%d", &T);
    while (T--){
        if (u) printf ("\n");
        u = 1;

        scanf ("%d%d%d", &n, &m, &y);
        int lsum = 0, usum = 0;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &an[i]);
            int t = (int)((double)an[i] * m / y);
            bn[i].first = t; 
            lsum += t;
            bn[i].second = min(m, t + 1);
            usum += bn[i].second;
        }

        if (lsum > m) gao1();
        else if (usum < m) gao2();
        else gao3(n - (m-lsum));
    
        printf ("\n");
    }
    return 0;
}
