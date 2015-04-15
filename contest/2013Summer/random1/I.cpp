/*
 * Author:  plum rain
 * Created Time:  2013年08月03日 星期六 19时19分27秒
 * File Name: I.cpp
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
const int N = 1005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{
    int x, y;
};
struct lst{
    point s, e;
    int len;
    bool use;
}an[2*N];

bool Overlap(point a, point b)
{
    return (a.x == b.x && a.y == b.y);
}

int main()
{
    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF && (n || m)){
        point p, q;
        int num = 0;
        int tot = m + n;
        rep (i, tot){
            scanf ("%d%d", &p.x, &p.y);
            q = p;
            if (i < n)
                q.x ++;
            else
                q.y ++;
            bool xxx = false;
            rep (j, num){
                if (xxx)
                    break;
                if (Overlap (p, an[j].s)){
                    an[j].s = q;
                    xxx = true;
                    an[j].len ++;
                    break;
                }
                if (Overlap (p, an[j].e)){
                    an[j].e = q;
                    xxx = true;
                    an[j].len ++;
                    break;
                }
                if (Overlap (q, an[j].s)){
                    an[j].s = p;
                    xxx = true;
                    an[j].len ++;
                    break;
                }
                if (Overlap (q, an[j].e)){
                    an[j].e = p;
                    xxx = true;
                    an[j].len ++;
                    break;
                }
            }
            if (!xxx){
                an[num].s = p;
                an[num].e = q;
                an[num].len = 1;
                an[num++].use = false;
            }
        }
        /*tst(a);
        rep (i, num){
            lst a = an[i];
            cout << a.s.x << " " << a.s.y << endl;
            cout << a.e.x << " " << a.e.y << endl;
            out (a.len);
        }*/
        rep (i, num){
            rep (j, num){
                lst a = an[i], b = an[j];
                if (a.use || b.use || (i == j))
                    continue;
                if (Overlap (a.s, b.s)){
                    an[i].s = b.e;
                    an[i].len += b.len;
                    an[j].use = true;
                    continue;
                }
                if (Overlap (a.s, b.e)){
                    an[i].s = b.s;
                    an[i].len += b.len;
                    an[j].use = true;
                    continue;
                }
                if (Overlap (a.e, b.s)){
                    an[i].e = b.e;
                    an[i].len += b.len;
                    an[j].use = true;
                    continue;
                }
                if (Overlap (a.e, b.e)){
                    an[i].e = b.s;
                    an[i].len += b.len;
                    an[j].use = true;
                    continue;
                }
            }
        }
        int ans = 0;
//        cout << endl << endl;
        rep (i, num){
            lst a = an[i];
            if (a.use)
                continue;
//            cout << a.s.x << " " << a.s.y << endl;
//            cout << a.e.x << " " << a.e.y << endl;
//            out (a.len);
            ans += a.len / 2;
        }
        printf ("%d\n", tot - ans);
    }
    return 0;
}
