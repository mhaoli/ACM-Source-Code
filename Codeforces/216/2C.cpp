/*
 * Author:  Plumrain
 * Created Time:  2013-11-30 00:30
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
//#include <cmath>
//#include <algorithm>
#include <vector>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>
//#include <list>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//#include <bitset>
//#include <cctype>
//#include <ctime>
//#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
//#define SZ(v) ((int)(v).size())
//#define INF 999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int maxint = 2147483647;
//
//typedef vector<int> VI;
//typedef vector<string> VS;
//typedef vector<double> VD;
typedef pair<int, int> pii;
//typedef long long int64;
//
//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//
int n;
bool v[100005];
int num[100005];
vector<int> ans;
vector<pii> a[100005];

void DFS(int x, bool fla)
{
    int sz = a[x].size();
    v[x] = 1;

    if (!sz && fla){
        num[x] = 1;
        ans.PB (x);
        return;
    }

    int cnt = 0;
    for (int i = 0; i < sz; ++ i) if (!v[a[x][i].first]){
        pii tmp = a[x][i];
        DFS (tmp.first, tmp.second);
        cnt += num[tmp.first];
    }

    if (!cnt && fla){
        ans.PB (x);
        num[x] = 1;
    }
    else num[x] = cnt;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &n) != EOF){    
        for (int i = 0; i < n; ++ i)
            a[i].clear();
        int x, y, w;
        for (int i = 0; i < n-1; ++ i){
            scanf ("%d%d%d", &x, &y, &w);
            -- x; -- y; -- w;
            a[x].PB (make_pair(y, w));
            a[y].PB (make_pair(x, w));
        }

        CLR (v); CLR (num);
        v[0] = 1;
        ans.clear();
        for (int i = 0; i < a[0].size(); ++ i)
            DFS (a[0][i].first, a[0][i].second);

        int sz = ans.size();
        printf ("%d\n", sz);
        for (int i = 0; i < sz; ++ i){
            if (i) printf (" ");
            printf ("%d", ans[i]+1);
        }
        printf ("\n");
    }
    return 0;
}
