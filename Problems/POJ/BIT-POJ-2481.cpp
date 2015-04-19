/*
 * Author:  Plumrain
 * Created Time:  2014-02-16 21:05
 * File Name: BIT-POJ-2481.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define lowbit(x) ((x)&(-x))
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
    int s, e, idx;
};

nod an[100005];
int num[100005], c[100005], lim;
vector<pii > ans;

int sum(int x)
{
    int ret = 0;
    while (x > 0)
        ret += c[x], x -= lowbit(x);
    return ret;
}

void add(int x, int d)
{
    while (x <= lim)
        c[x] += d, x += lowbit(x);
}

bool cmp1(nod a, nod b)
{
    return a.e > b.e || (a.e == b.e && a.s < b.s);
}

bool cmp2(pii a, pii b)
{
    return a.second < b.second;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF && n){
        for (int i = 0; i < n; ++ i){
            scanf ("%d%d", &an[i].s, &an[i].e);
            ++ an[i].s; ++ an[i].e;
            an[i].idx = i;
            lim = max(lim, an[i].s);
        }
        sort (an, an + n, cmp1);

        //for (int i = 0; i < n; ++ i) tst (an[i].s), tst (an[i].e), out (an[i].idx);
//
        clr (num); clr (c);
        ans.clear();
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (!i || an[i].s != an[i-1].s || an[i].e != an[i-1].e)
                cnt = sum(an[i].s);
                
            ans.pb (make_pair(cnt, an[i].idx));
            add (an[i].s, 1);
        }
        sort (all(ans), cmp2);
        
        for (int i = 0; i < sz(ans); ++ i){
            if (i) printf (" ");
            printf ("%d", ans[i].first);
        }
        printf ("\n");
    }
    return 0;
}
