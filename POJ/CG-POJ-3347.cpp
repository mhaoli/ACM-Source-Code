/*
 * Author:  plum rain
 * Created Time:  2013年08月03日 星期六 21时55分20秒
 * File Name: CG-POS-3347.cpp
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
const int N = 55;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct sqa{
    int a, s, l, r;
    int num;
}an[N];

VI ans;

bool cmp (sqa x, sqa y)
{
    return x.a < y.a;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF && n){
        scanf ("%d", &an[0].a);
        an[0].s = an[0].a;
        an[0].l = 0;
        an[0].r = 2 * an[0].a;
        an[0].num = 1;
        repf (i, 1, n-1){
            scanf ("%d", &an[i].a);
            an[i].num = i + 1;
            if (an[i].a < an[i-1].a){
                an[i].s = an[i-1].s + 2 * an[i].a;
                an[i].l = an[i].s - an[i].a;
                an[i].r = an[i].s + an[i].a;
            }
            else{
                int pos = 0;
                rep (j, i){
                    int tmp = an[j].s + 2 * min (an[i].a, an[j].a);
                    pos = max (tmp, pos);
                }
                an[i].s = pos;
                an[i].l = pos - an[i].a;
                an[i].r = pos + an[i].a;
            }
        }
        sort (an, an+n, cmp);
        ans.clear();
        rep (i, n){
            repf (j, i+1, n-1){
                if (an[j].s < an[i].s)
                    an[i].l = max (an[i].l, an[j].r);
                if (an[j].s > an[i].s)
                    an[i].r = min (an[i].r, an[j].l);
                if (an[i].l >= an[i].r)
                    break;    
            }
            if (an[i].l < an[i].r)
                ans.PB(an[i].num);
        }
        int size = SZ(ans);
        sort (ans.begin(), ans.end());
        if (size){
            printf ("%d", ans[0]);
            repf (i, 1, size-1)
                printf (" %d", ans[i]);
        }
        printf ("\n");
    }
    return 0;
}
