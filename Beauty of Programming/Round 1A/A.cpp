/*
 * Author:  Plumrain
 * Created Time:  2014/4/19 14:03:28
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

double an[3];
string s[3];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        cin >> s[0] >> s[1] >> s[2];

        double tnum;
        string tmp;
        stringstream ss;
        repf (i, 0, 2){
            ss.clear(); ss << s[i]; ss >> tnum; ss >> tmp;
            if (tmp == "mm" || tmp == "px") an[i] = tnum + 0.0;
            if (tmp == "cm") an[i] = tnum * 10.0;
            if (tmp == "dm") an[i] = tnum * 100.0;
            if (tmp == "m") an[i] = tnum * 1000.0;
            if (tmp == "um") an[i] = tnum / 1000.0;
            if (tmp == "nm") an[i] = tnum / 1000000.0;
        }

        double ans = an[0] * an[2] / an[1];
        printf ("Case %d: %.2fpx\n", ++ cas, ans);
    }
    return 0;
}
