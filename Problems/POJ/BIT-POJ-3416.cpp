/*
 * Author:  Plumrain
 * Created Time:  2014-02-20 17:37
 * File Name: BIT-POJ-3416.cpp
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
#define lowbit(x) ((x)&(-x))
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 50005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
struct oo{
    int x, y, idx;
};

pii nod[N];
oo ask[N];
int c[3][N*10];
vector<pii > ans1, ans2;

bool cmp1(oo a, oo b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp2(pii a, pii b)
{
    return a.second < b.second;
}

int sum(int x, int idx)
{
    int ret = 0;
    while (x > 0) ret += c[idx][x], x -= lowbit(x);
    return ret;
}

void add(int x, int d, int idx)
{
    while (x < N*10) c[idx][x] += d, x += lowbit(x);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n, m;
        scanf ("%d%d", &n, &m);

        clr (c);
        for (int i = 0; i < n; ++ i){
            scanf ("%d%d", &nod[i].first, &nod[i].second);
            ++ nod[i].first; ++ nod[i].second;
        }
        sort (nod, nod+n);

        //for (int i = 0; i < n; ++ i) tst (nod[i].first), cout << nod[i].second << endl;
//
        for (int i = 0; i < m; ++ i){
            scanf ("%d%d", &ask[i].x, &ask[i].y);
            ++ ask[i].x; ++ ask[i].y;
            ask[i].idx = i;
        }
        sort (ask, ask+m, cmp1);

        //for (int i = 0; i < m; ++ i) tst (ask[i].x), tst (ask[i].y), cout << ask[i].idx << endl;
//
        int fla1 = 0, fla2 = n-1, cnt = 0;
        ans1.clear(); ans2.clear();
        for (int i = 0; i < m; ++ i){
            while (fla1 < n && ask[i].x > nod[fla1].first)
                add (nod[fla1 ++].second, 1, 0);
            ans1.pb (make_pair(sum (ask[i].y, 0), ask[i].idx));
            
            while (fla2 >= 0 && ask[m-1-i].x < nod[fla2].first)
                add (nod[fla2 --].second, 1, 1), ++ cnt;
            ans2.pb (make_pair(cnt - sum (ask[m-1-i].y, 1), ask[m-1-i].idx));
        }
        sort (all(ans1), cmp2); sort (all(ans2), cmp2);

        for (int i = 0; i < m; ++ i){
            int ans = abs(n - 2*(ans1[i].first + ans2[i].first));
            printf ("%d\n", ans);
        }

        if (T) printf ("\n");
    }
    return 0;
}
