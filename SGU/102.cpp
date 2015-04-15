/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 11:25:32
 * File Name: 102.cpp
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
const int maxn = 10000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int prm[maxn+5], phi[maxn+5];
bool check[maxn+5];

int phi_table(int n){
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
    return tot;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    phi_table(maxn);
    int n;
    while (cin >> n) cout << phi[n] << endl;
    return 0;
}
