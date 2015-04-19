/*
 * Author:  Plumrain
 * Created Time:  2014-02-17 11:07
 * File Name: BIT-POJ-1990.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define lowbit(x) ((x)&(-x))
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 20005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

pii an[N];
pair<int64, int64> c[N];

pair<int64, int64> sum(int x)
{
    pair<int64, int64> ret = make_pair(0LL, 0LL);
    while (x > 0){
        ret.first += c[x].first; ret.second += c[x].second;
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int d)
{
    int tmp = x;
    while (x < N){
        c[x].second += tmp; c[x].first += d;
        x += lowbit(x);
    }
}

bool cmp(pii a, pii b)
{
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i) 
            scanf ("%d%d", &an[i].first, &an[i].second);
        sort (an, an+n, cmp);

        //for (int i = 0; i < n; ++ i)
            //tst (an[i].first), cout << an[i].second << endl;
       // 
        for (int i = 0; i < N; ++ i) 
            c[i].first = 0, c[i].second = 0;

        int64 ans = 0;
        //tst1 (ans);
        for (int i = 0; i < n; ++ i){
            pair<int64, int64> t1 = sum(an[i].second), t2 = sum(N-1);
            //tst (t1.first), tst (t1.second), tst (t2.first), tst (t2.second), tst1 (a);
            ans += an[i].first * (t1.first * an[i].second - t1.second + (t2.second - t1.second) - (t2.first-t1.first)*an[i].second);
            add (an[i].second, 1);
            //tst (i), cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
