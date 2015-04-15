/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: D.cpp
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

struct nod{
    pii s, e;
};

int n, m, k;
int num[55][55];
pii temp;
pii stk[3000];
nod an[55][55];

void gao(int tx, int ty, int x, int y)
{
    an[x][y].s = make_pair(tx, ty);

    if (tx == n && ty == m){
        an[x][y].e = temp;
        return;
    }

    if (x == 1){
        if (y+1 <= n) tx = y + 1, ty = 1;
        else tx = n, ty = y + 2 - n;
    }
    else if (y == m){
        if (x+m <= n) tx = x + m, ty = 1;
        else tx = n, ty = x + m + 1 - n;
    }
    else tx = x - 1, ty = y + 1;

    an[x][y].e = make_pair(tx, ty);
    gao(x, y, tx, ty);
}

void init()
{
    temp = make_pair(-1, -1);
    clr (num);
    an[1][1].s = temp;
    if (n > 1) an[1][1].e = make_pair(2, 1), gao(1, 1, 2, 1);
    else if (m > 1) an[1][1].e = make_pair(1, 2), gao(1, 1, 1, 2);
    else an[1][1].e = temp;
}

void OUT(pii x)
{
    int idx = 0;
    pii xxx = make_pair(1, 1);
    while (1){
        stk[idx++] = x;
        if (x == xxx) break;
        if (x.first > 1) x.first --;
        else x.second --;
    }
    while (idx){
        pii ans = stk[--idx];
        printf ("(%d,%d) ", ans.first, ans.second);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d%d", &n, &m, &k) != EOF){
        init();

        int cnt = 1;
        pii cur = make_pair(1, 1);
        while (cnt < k){
            cur = an[cur.first][cur.second].e;
            ++ cnt;
        }

        pii xxx = cur;
        int ans = 0;
        while (cur != temp){
            ans += abs(cur.first - 1) + abs(cur.second - 1) + 1;
            cur = an[cur.first][cur.second].s;
        }

        printf ("%d\n", ans);
        cur = xxx;
        while (cur != temp){
            OUT (cur); cout << endl;
            cur = an[cur.first][cur.second].s;
        }
    }
    return 0;
}
