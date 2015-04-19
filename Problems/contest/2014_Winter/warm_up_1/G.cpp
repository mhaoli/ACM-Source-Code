/*
 * Author:  Plumrain
 * Created Time:  2014-02-09 14:30
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
#define clrs(x,y) memset(x, -1, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
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

struct cir{
    int x, y, r;
    void TST(){
        tst (x); tst (y); cout << r << endl;
    }
};

cir an[4];

bool gao(cir a, cir b)
{
    double cha = fabs(a.r - b.r - 0.0), he = a.r + b.r + 0.0;
    double dis = sqrt ((double)(a.x-b.x)*(a.x-b.x) + (double)(a.y-b.y)*(a.y-b.y));
    if (dis > cha + eps && dis < he - eps) return 1;
    return 0;
}

bool sol (cir a, cir t1, cir t2)
{
    double dis = sqrt ((double)(a.x-t1.x)*(a.x-t1.x) + (double)(a.y-t1.y)*(a.y-t1.y));
    if (dis + a.r > t2.r + eps) return 0;
    if (dis + a.r < t1.r + eps) return 0;
    if (gao(a, t1)) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int tot = 0, x, y, r, R;
    cir tmp;
    for (int i = 0; i < 2; ++ i){
        scanf ("%d%d%d%d", &x, &y, &r, &R);
        tmp.x = x; tmp.y = y;
        tmp.r = r; an[tot++] = tmp;
        tmp.r = R; an[tot++] = tmp;
    }

    int ans = 4;
    for (int i = 0; i < 4; ++ i){
        bool u = 0;
        if (i < 2){
            if (sol(an[i], an[2], an[3])) u = 1;
            for (int j = 2; j < 4; ++ j) u |= gao (an[i], an[j]);
        }
        else{
            if (sol(an[i], an[0], an[1])) u = 1;
            for (int j = 0; j < 2; ++ j) u |= gao(an[i], an[j]);
        }
        if (u) ans --;
        //tst (i), out (u);
    }
    cout << ans << endl;
    return 0;
}
