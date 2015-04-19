/*
 * Author:  Plumrain
 * Created Time:  2014/8/6 9:41:19
 * File Name: LOJ1375.cpp
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

typedef unsigned long long int64;
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
const int maxn = 3000005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool check[maxn];
int prm[maxn], phi[maxn];
int64 s1[maxn];

void init (int n){
    clr (check, 0); phi[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[ tot++ ] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[ i*prm[j] ] = 1;
            if (i % prm[j] == 0){
                phi[ i*prm[j] ] = phi[i] * prm[j]; break;
            }
            else phi[ i*prm[j] ] = phi[i] * (prm[j] - 1);
        }
    }

    clr (s1, 0);
    repf (i, 2, n) for (int j = i; j <= n; j += i) s1[j] += (int64)phi[i] * i / 2;
    repf (i, 1, n) s1[i] *= i;
    repf (i, 2, n) s1[i] += s1[i-1];
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init(maxn - 5);
    repcase{
        int n; scanf ("%d", &n);
        printf ("Case %d: %llu\n", ++ cas, s1[n]);
    }
    return 0;
}
