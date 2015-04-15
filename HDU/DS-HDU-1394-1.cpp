/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: DS-HDU-1394-1.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn =  5005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int n;
int num[maxn<<2], an[maxn];

int query (int v, int rt, int l, int r)
{
    if (v == 0) return 0;

    if (v >= r) return num[rt];
    if (v < l) return 0;
    int m = (l + r) >> 1;
    int ret = query (v, 2*rt, l, m);
    if (v > m) ret += query (v, 2*rt+1, m+1, r);
    return ret;
}

void update(int v, int rt, int l, int r)
{
    if (l == r){
        ++ num[rt]; return;
    }
    int m = (l + r) >> 1;
    if (v <= m) update (v, 2*rt, l, m);
    else update (v, 2*rt+1, m+1, r);
    num[rt] = num[2*rt] + num[2*rt+1];
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &an[i]), ++ an[i];

        clr (num);
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            cnt += i - query (an[i]-1, 1, 1, n);
            update (an[i], 1, 1, n);
        }

        int ans = cnt;
        for (int i = 0; i < n; ++ i){
            cnt += n - 1 - 2 * (an[i] - 1);
            ans = min (ans, cnt);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
