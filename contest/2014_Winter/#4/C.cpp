/*
 * Author:  Plumrain
 * Created Time:  2014-02-13 14:14
 * File Name: C.cpp
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
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 500005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

struct nod{
    int64 pri;
    int l, r;
};
struct cmp{
    bool operator()(nod x, nod y){
        return x.pri > y.pri;
    }
};

nod an[2*N];
priority_queue<nod, vector<nod>, cmp> q;

int build()
{
    int pos = 0;
    while (sz(q) != 1){
        nod x = q.top(); q.pop();
        nod y = q.top(); q.pop();

        nod sum;
        sum.pri = x.pri + y.pri;
        sum.l = pos; sum.r = pos + 1;
        
        an[pos++] = x; an[pos++] = y;
        q.push(sum);
    }
    an[pos] = q.top();
    return pos;
}

int64 ask(int tmp, int64 num)
{
    nod x = an[tmp];
    if (x.l == -1 && x.r == -1) return num * x.pri;
    return ask(x.l, num+1) + ask(x.r, num+1);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    bool u = 0;
    nod x; x.l = -1; x.r = -1;
    while (T--){
        if (u) printf ("\n"); u = 1;

        while (sz(q)) q.pop();
        int n, a;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &a);
            x.pri = a; q.push(x);
        }

        int pos = build();
        printf ("%lld\n", ask(pos, 0LL));
    }
    return 0;
}
