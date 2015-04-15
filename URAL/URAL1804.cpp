/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 13:36:18
 * File Name: E.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int a[2], b[2];

int ok (){
    if (a[0] == b[0] && a[1] == b[1]) return -1;
    if (a[0] + a[1] > b[0] + b[1]) return 1;
    if (a[0] + a[1] < b[0] + b[1]) return 0;
    if (a[1] > b[1]) return 1;
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    string s;
    repcase{
        bool away;
        repf (i, 0, 3) cin >> s;
        if (s[0] == 'h') away = 1;
        else away = 0;
        int t[2], p = 0;
        while (cin >> s){
            if (s[0] >= '0' && s[0] <= '9'){
                stringstream ss; ss << s; ss >> t[p]; ++ p;
            }
            if (p == 2 && s[0] == 'g') break;
        }

        int ans1 = 30, ans2 = 0;
        a[!away] = t[0]; b[away] = t[1];
        for (int i = 0; i <= 30; ++ i){
            a[away] = i; b[!away] = 0;
            int q = ok ();
            if (q == -1 || q == 1){
                ans1 = i; break;
            }
        }

        for (int i = 30; i >= 0; -- i){
            a[away] = i; b[!away] = 30;
            int q = ok();
            if (q == -1 || q == 0){
                ans2 = i; break;
            }
        }

        printf ("%d %d\n", ans1, ans2);
    }
    return 0;
}
