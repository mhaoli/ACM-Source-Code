/*
 * Author:  Plumrain
 * Created Time:  2014/8/10 12:44:23
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

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    string s;
    repcase{
        cin >> s;
        char c = s[sz(s)-1];
        if (c == 'y'){
            s[sz(s)-1] = 'i';
            s += "es";
        }
        else if (c == 'o' || c == 'x' || c == 's'){
            s += "es";
        }
        else if (c == 'f'){
            s[sz(s)-1] = 'v'; s += "es";
        }
        else if (sz (s) > 1 && c == 'h' && s[sz(s)-2] == 'c') s += "es";
        else if (sz (s) > 1 && c == 'e' && s[sz(s)-2] == 'f') s[sz(s)-2] = 'v', s += "s";
        else s += "s";
        cout << s << endl;
    }
    return 0;
}
