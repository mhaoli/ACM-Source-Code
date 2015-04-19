/*
 * Author:  Plumrain
 * Created Time:  2014-04-06 23:48
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
#define INF 999999999999999999
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

const int maxn = 5000000;
bool check[maxn+5];
int prm[maxn+5];

int primes(int n){
    clr (check, 0);
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot; 
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int tot = primes (maxn);
    int n, k;
    while (cin >> n >> k){
        if (n == 1){
            if (k > 0) cout << "-1" << endl; 
            else cout << "1" << endl;
            continue;
        }

        bool u = 0;
        if (n & 1) n --, u = 1;

        int tmp = k - (n/2) + 1;
        if (tmp < 1) cout << "-1" << endl;
        else{
            int cnt = 2;
            printf ("%d %d", tmp*3, tmp*4);
            for (int i = 3; i < tot-1; i += 2) if (cnt < n){
                printf (" %d %d", prm[i], prm[i+1]);
                cnt += 2;
                if (cnt >= n) break;
            }
            if (u) printf (" 1");
            printf ("\n");
        }
    }
    return 0;
}
