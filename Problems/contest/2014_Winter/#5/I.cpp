/*
 * Author:  Plumrain
 * Created Time:  2014-02-14 13:03
 * File Name: I.cpp
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

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int a, b;
    while (scanf ("%d%d", &a, &b) != EOF){
        int tmp = abs(a) + abs(b);
        pii ans[2];
        ans[0].first = 0; ans[1].second = 0;
        ans[0].second = tmp * (b < 0 ? -1 : 1);
        ans[1].first = tmp * (a < 0 ? -1 : 1);

        sort (ans, ans+2, cmp); 
        for (int i = 0; i < 2; ++ i){
            printf ("%d %d", ans[i].first, ans[i].second);
            if (!i) printf (" ");
            else printf ("\n");
        }
    }
    return 0;
}
