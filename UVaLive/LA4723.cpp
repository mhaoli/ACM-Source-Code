/*
 * Author:  Plumrain
 * Created Time:  2014/9/25 13:18:12
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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

struct nod{
    int a[20], n;
    void modify (int *b, int _n){
        n = _n;
        rep (i, 0, n-1) a[i] = b[i];
    }
    bool operator<(const nod &t)const {
        rep (i, 0, n-1){
            if (a[i] < t.a[i]) return 1;
            if (a[i] > t.a[i]) return 0;
        }
        return 0;
    }
    bool zero (){
        rep (i, 0, n-1) if (a[i]) return 0;
        return 1;
    }
}memo[1111];

int a[20], b[20];
set<nod> has;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int T; scanf ("%d", &T);
    while (T--){
        has.clear ();
        int n; scanf ("%d", &n);
        rep (i, 0, n-1) scanf ("%d", a + i);
        int top = 0;
        memo[top++].modify (a, n);
        while (1){
            rep (i, 0, n-1) b[i] = abs (memo[top-1].a[i] - memo[top-1].a[(i+1)%n]);
            memo[top++].modify (b, n);
            if (memo[top-1].zero ()){
                puts ("ZERO"); break;
            } else{
                if (has.count (memo[top-1])){
                    puts ("LOOP"); break;
                } else has.insert (memo[top-1]);
            }
        }
    }
    return 0;
}
