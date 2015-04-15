/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: mobius-HYSBZ-2005-2.cpp
 * time: 44ms, O(min(n, m))
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
const int maxn = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int prm[maxn];
int64 phi[maxn];
bool check[maxn];

void phi_init(int n){
    clr (check, 0); phi[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i, phi[i] = i - 1;
        repf (j, 0, tot-1){
            int tmp = i * prm[j];
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j] == 0){
                phi[tmp] = phi[i] * prm[j];
                break;
            }
            else phi[tmp] = phi[i] * (prm[j] - 1);
        }
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    phi_init(maxn-5);

    int64 n, m;
    while (cin >> n >> m){
        if (n > m) swap (n, m);
        int64 ans = 0;
        repf (i, 1, n) ans += phi[i] * (n / i) * (m / i);
        cout << 2*ans - n*m << endl;
    }
    return 0;
}
