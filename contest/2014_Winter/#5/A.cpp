/*
 * Author:  Plumrain
 * Created Time:  2014-02-14 13:31
 * File Name: A.cpp
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

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
struct Pat{
    int s, e;
};

int n, m, q;
int des[N], f[N];
bool v[N];
vi ans;
vector<Pat> pat;

int find(int x)
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> n >> m){
        pat.clear();
        for (int i = 0; i < m; ++ i){
            int t1, t2;
            scanf ("%d%d", &t1, &t2);
            -- t1; -- t2;
            Pat tmp;
            tmp.s = t1; tmp.e = t2;
            pat.pb (tmp);
        }

        clr (v);
        scanf ("%d", &q);
        for (int i = 0; i < q; ++ i) scanf ("%d", &des[i]), v[des[i]-1] = 1;


        for (int i = 0; i < n; ++ i) f[i] = i;
        for (int i = 0; i < m; ++ i) if (!v[i]){
            int t1 = find(pat[i].e), t2 = find(pat[i].s);
            if (t1 != t2) f[t1] = t2;
        }

        ans.clear();
        int cnt = 0;
        for (int i = 0; i < n; ++ i) if (f[i] == i) ++ cnt;
        ans.pb (cnt);

        for (int i = q-1; i; -- i){
            Pat t = pat[des[i]-1];
            int t1 = find(t.s), t2 = find(t.e);
            if (t1 != t2) -- cnt, f[t1] = t2;
            ans.pb (cnt);
        }

        for (int i = sz(ans) - 1; i >= 0; -- i){
            printf ("%d", ans[i]);
            if (i) printf (" ");
            else printf ("\n");
        }
    }
    return 0;
}
