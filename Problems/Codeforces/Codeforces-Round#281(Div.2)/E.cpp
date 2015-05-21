/*
 * Author:  Plumrain
 * Created Time:  2014/12/4 17:52:21
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
#include<functional>
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

ll n, a, b;
int cof[1111], cnt;

bool check() {
        ll res = a, j = 1;
        for(int i = 0; i < cnt; ++i, j *= n) {
                res -= cof[i] * j;
                if(res < 0) return 0;
        }
        return !res;
}

int main()
{
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        cin >> n >> a >> b;
        int ans = a == b ? 1 : 0;
        if (n <= a && a <= b) {
                if(a != 1) {
                        cnt = 0;
                        for(long long t = b; t; t /= a)
                                cof[cnt++] = t % a;
                        if(check()) ++ans;
                        for(int i = 1; i < cnt; ++i) if(cof[i]){
                                if(i == cnt-1 && cnt == 2) continue;
                                --cof[i]; cof[i-1] += a;
                                if(check()) ++ans;
                                ++cof[i]; cof[i-1] -= a;
                        }
                } else {
                        if(b == 1) return puts("inf"), 0;
                }
        }
        printf("%d\n", ans);
        return 0;
}
