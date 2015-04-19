/*
 * Author:  Plumrain
 * Created Time:  2013-12-24 22:26
 * File Name: B.cpp
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

#define clr0(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int ru[105], chu[105];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n , &m) != EOF){
        int t1, t2, w;
        clr0 (chu); clr0 (ru);
        for (int i = 0; i < m; ++ i){
            scanf ("%d%d%d", &t1, &t2, &w);
            chu[--t1] += w;
            ru[--t2] += w;
        }
        int ans = 0;
        for (int i = 0; i < n; ++ i)
            ans += abs(chu[i] - ru[i]);
        printf ("%d\n", ans / 2);
    }
    return 0;
}