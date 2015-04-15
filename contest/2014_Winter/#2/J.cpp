/*
 * Author:  Plumrain
 * Created Time:  2014-02-11 12:37
 * File Name: J.cpp
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

int gao(string s)
{
    s.pb (':');
    int n = sz(s), cnt = 0, tmp = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == ':'){
            cnt = cnt * 60 + tmp;
            tmp = 0;
        }
        else tmp = tmp * 10 + s[i] - '0';
    }
    return cnt;
}

void OUT(int a)
{
    if (a < 10) printf ("0%d", a);
    else printf ("%d%d", a/10, a%10);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    string t1, t2;
    while (cin >> t1 >> t2){
        int tim1 = gao(t1), tim2 = gao(t2);
        int sta = tim1 - tim2;
        if (sta < 0) sta += 24 * 60;

        OUT(sta / 60);
        cout << ":";
        OUT(sta % 60);
        cout << endl;
    }
    return 0;
}
