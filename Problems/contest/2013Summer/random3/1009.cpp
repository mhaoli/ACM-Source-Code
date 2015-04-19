/*
 * Author:  plum rain
 * Created Time:  2013年08月06日 星期二 17时55分12秒
 * File Name: 
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 100005;

inline int Mymod( int a , int b ) { return (a%b+b)%b;}
struct ANS{
    int s;
    int num;
}sum[N];

int n, mod;
int an[N];

bool cmp(ANS a, ANS b)
{
    return (a.s < b.s || (a.s == b.s && a.num < b.num));
}

int main()
{
//    freopen("1009.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    while (scanf ("%d%d", &n, &mod) != EOF){
        sum[0].s = 0;
        for (int i = 1; i <= n ; i++){
            scanf ("%d", &an[i]);  
            sum[i].s = Mymod(sum[i-1].s+an[i], mod);
            sum[i].num = i;
        }
//        int cnt = Mymod(sum[n].s, mod);
        sort (sum+1, sum+n+1, cmp);
//        for (int i = 1; i <= n; i ++)
//            cout << sum[i].s << endl;
        
        int tmp = 0, ans = 0;
        int l = 0;
        for (int i = 1; i <= n; i ++){
            if (sum[i].s == tmp)
                continue;
            int num = sum[i-1].num;
                ans = max (num-l, ans);
            tmp = sum[i].s;
            l = sum[i].num;
        }
//        tst(aaa);
//        cout << sum[n].num;
//        cout << endl << l << endl;
//        cout << ans << endl;
        ans = max (sum[n].num-l, ans);
//        tst(ans);
        printf ("%d\n", ans);
//        tst(ans);
    } 
    return 0;
}
