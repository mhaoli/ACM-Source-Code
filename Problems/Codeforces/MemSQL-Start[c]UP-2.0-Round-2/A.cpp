/*
 * Author:  Plumrain
 * Created Time:  2014/8/11 17:19:06
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

char s[2][200005];

int calc (char *s, int n){
    reverse (s, s+n);
    repf (i, n, n+100) s[i] = '0';
    repf (i, 0, n-1) if (s[i] != '0'){
        int j = i;
        while (s[++j] == '1');
        for (int k = j-1; k >= i; k -= 2){
            if (k == i) break;
            s[k+1] = '1'; s[k] = s[k-1] = '0';
        }
    }
    repd (j, n + 100, 0) if (s[j] == '1') return j + 1;
    return 1;
}

int cmp (char *s, int n, char *t, int m){
    if (n > m) return 1;
    if (n < m) return -1;
    repd (i, n-1, 0){
        if (s[i] == t[i]) continue;
        if (s[i] == '1') return 1;
        return -1;
    }
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    clr (s, 0);
    scanf ("%s%s", s[0], s[1]);
    int n1 = calc (s[0], strlen (s[0]));

    //s[0][n1] = 0;
    //printf ("%s\n", s[0]);
//
    int n2 = calc (s[1], strlen (s[1]));

    //s[1][n2] = 0;
    //printf ("%s\n", s[1]);
//
    int q = cmp (s[0], n1, s[1], n2);
    if (q == -1) puts ("<");
    else puts ((q ? ">" : "="));
    return 0;
}
