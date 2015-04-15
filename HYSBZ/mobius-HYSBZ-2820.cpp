/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: mobius-HYSBZ-2820.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<cctype>
#include<ctime>
#include<utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 10000005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

bool check[maxn];
int sum[maxn];
int g[maxn], mu[maxn], prm[maxn];

void init(int n){
    clr (check, 0);
    check[1] = 1; mu[1] = 1; g[1] = 0;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]){
            mu[i] = -1; prm[tot++] = i; g[i] = 1;
        }
        repf (j, 0, tot-1){
            int tmp = prm[j] * i;
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j]) mu[tmp] = -mu[i], g[tmp] = -g[i] + mu[i];
            else{
                g[tmp] = mu[i]; mu[tmp] = 0; break;
            }
        }
    }

    clr (sum, 0);
    repf (i, 1, n) sum[i] += sum[i-1] + g[i];
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    init(maxn - 5);

    int T;
    scanf ("%d", &T);
    while (T--){
        int n, m;
        scanf ("%d%d", &n, &m);
        int64 ans = 0;
        for (int i = 1, la = 0; i <= min (n, m); i = la+1){
            la = min (n/(n/i), m/(m/i));
            ans += 1LL * (n / i) * (m / i) * (sum[la] - sum[i-1]);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
