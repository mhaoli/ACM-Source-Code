/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: mobius-HDU-1695-2.cpp
 * solution: mobius
 * time: 31 ms
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
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int prm[maxn], mo[maxn];
bool check[maxn];

int mobius (int n){
    clr (check, 0); 
    check[1] = 1; mo[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]){
            prm[tot++] = i; mo[i] = -1;
        }
        repf (j, 0, tot-1){
            int tmp = i * prm[j];
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j] == 0){
                mo[tmp] = 0; break;
            }
            else mo[tmp] = -mo[i];
        }
    }
    return tot;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    mobius(maxn - 5);

    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        printf ("Case %d: ", ++ cas);

        int x, y, d;
        scanf ("%*d%d%*d%d%d", &x, &y, &d);
        if (d == 0){
            puts ("0"); continue;
        }

        x /= d; y /= d;
        if (x > y) swap (x, y);
        int64 ans1 = 0, ans2 = 0;
        repf (i, 1, x){
            ans1 += (int64)(y/i) * (x/i) * mo[i];
            ans2 += (int64)(x/i) * (x/i) * mo[i];
        }
        cout << ans1 - ans2/2 << endl;
    }
    return 0;
}
