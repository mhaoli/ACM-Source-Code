/*
 * Author:  Plumrain
 * Created Time:  2014-02-11 16:04
 * File Name: H.cpp
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

int mod;
string s;
vector<pii > an;

bool cmp(pii a, pii b)
{
    return a.second > b.second;
}

void init()
{
    an.clear();
    pii xia;
    int t1 = 0, t2 = 0;
    bool nu = 0, xu = 0, fu = 0;
    for (int i = 0; i < sz(s); ++ i){
        if (s[i] == '/'  || s[i] == '(') continue;

        if (s[i] == ')' || s[i] == '+' || s[i] == '-'){
            if (nu && !t1) t1 = 1;
            if (nu && !xu) t2 = 1;
            if (fu) t1 *= -1;

            xia.first = t1; xia.second = t2; 
            if (xia.first || xia.second) an.pb (xia);

            t1 = t2 = nu = xu = fu = 0;
            if (s[i] == '-') fu = 1;
        }
        else if (s[i] == '^') xu = 1;
        else if (s[i] == 'n') nu = 1;
        else if (nu && xu) t2 = t2 * 10 + s[i] - '0';
        else t1 = t1 * 10 + s[i] - '0';
    }
    mod = t1;
    sort (all(an), cmp);
//
    //for (int i = 0; i < sz(an); ++ i) tst (an[i].first), out (an[i].second);
    //out (mod);
}

bool gao(int64 x)
{
    int64 yu = 0;
    for (int i = 0; i < sz(an); ++ i){
        int64 p = an[i].first, cnt = an[i].second, tmp = 1;
        while (cnt){
            tmp = tmp * x % mod;
            -- cnt;
        }
        yu = (yu + tmp * p) % mod;
    }
    return !yu;
}

bool ok()
{
    int maxx = an[0].second;
    for (int64 i = 0; i <= maxx; ++ i) if (!gao(i)) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int cas = 0;
    while (cin >> s && s != "."){
        init(); 
        printf ("Case %d: ", ++ cas);
        if (ok()) printf ("Always an integer\n");
        else printf ("Not always an integer\n");
    }
    return 0;
}
