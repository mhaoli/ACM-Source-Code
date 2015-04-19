/*
 * Author:  Plumrain
 * Created Time:  2014-02-09 12:35
 * File Name: F.cpp
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
#define clrs(x,y) memset(x, -1, sizeof(x))
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

int tot;
int64 an[100000];

int gen(int n)
{
    tot = 2;
    an[0] = 0; an[1] = 1;
    while (an[tot-1] < n){
        an[tot] = an[tot-1] + an[tot-2];
        ++ tot;
    }
    return tot;
}

void gao(int n)
{
    if (!n){
        cout << "0 0 0" << endl;
        return;
    }
    if (n == 1){
        cout << "0 0 1" << endl;
        return;
    }

    int idx;
    for (int i = 0; i < tot; ++ i) if (an[i] == n){
        idx = i; break;
    }
    tst(an[idx-3]);
    tst(an[idx-2]);
    cout << an[idx-2] << endl;
    return;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    tot = gen(1000000005);
    int n;
    while (scanf ("%d", &n) != EOF) gao(n);
    return 0;
}
