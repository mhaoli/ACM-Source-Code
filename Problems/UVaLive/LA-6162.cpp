/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 12:50:52
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int t[10];

void Read (int &t){
    int t1, t2; scanf ("%d:%d", &t1, &t2);
    t = t1 * 60 + t2;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF && n){
        bool ans = 1;
        int s1 = 0, s2 = 0;
        while (n --){
            repf (i, 0, 3) Read (t[i]);
            if (t[3] <= t[2]) t[3] += 24 * 60;
            repf (i, 4, 5) t[i] = t[i-4] + 24 * 60;
            if (t[3] - t[2] > 120){
                 ans = 0; continue;
            }

            s1 += t[3] - t[2] + 1;
            int t1 = t[3] - t[2] + 1, t2 = 0;
            repf (i, t[2], t[3]){
                if (i < t[0]) ++ t2;
                if (i > t[1] && i < t[4]) ++ t2;
            }
            if (2*t2 >= t1) s2 += t1;
        }
        if (ans == 0 || s2 < 600 || s1 < 3000) puts ("NON");
        else puts ("PASS");
    }
    return 0;
}
