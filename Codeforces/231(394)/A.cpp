/*
 * Author:  Plumrain
 * Created Time:  2014-02-20 23:34
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

string s;
vi v;

void gao(int x)
{
    for (int i = 0; i < x; ++ i) printf ("|");
}

void OUT()
{ 
    gao (v[0]); printf ("+");
    gao (v[1]); printf ("=");
    gao (v[2]); printf ("\n");
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (cin >> s){
        int n = sz(s);
        v.clear();

        int cnt = 0;
        s += ' ';
        for (int i = 0; i <= n; ++ i){
            if (s[i] != '|') v.pb (cnt), cnt = 0;
            else ++ cnt;
        }

        if (v[0] + v[1] == v[2]) OUT();
        else if (v[0] + v[1] == v[2] - 2){
            ++ v[0]; -- v[2];
            OUT();
        }
        else if (v[0] + v[1] == v[2] + 2){
            if (v[0] < v[1]) -- v[1], ++ v[2];
            else -- v[0], ++ v[2];
            OUT();
        }
        else printf ("Impossible\n");
    }
    return 0;
}
