/*
 * Author:  Plumrain
 * Created Time:  2014/7/25 1:31:58
 * File Name: D.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi num, num2;
bool v[100005];
int64 ans1, ans2, d[2][2][2];
char s[100005];

void solve (int u){
    int64 sum = 0, tmp = 0;
    clr (v, 0);
    int sta = -1, cnt2 = 0;;
    for (int i = u; i < sz(num); i += 2){
        sum += num[i];
        if (num[i] & 1) sta = (sta==-1 ? i : sta), v[i] = 1, ++ cnt2;
    }
    for (int i = u; i < sz(num); i += 2){
        int64 tt = (sum - num[i]) * num[i];
        if (v[i]) tt -= (cnt2 - 1);
        tmp += tt / 2;
    }
    //out (tmp / 2);
    tmp /= 2; ans1 += tmp; ans2 += tmp;

    if (cnt2 < 2) return;

    num2.clear();
    int tlen = 0;
    for (int i = sta+1; i < sz(num); i ++){
        if (v[i]) num2.pb (tlen), tlen = 0;
        else tlen = ((tlen + num[i]) & 1); 
    }

    //out (sz (num2));
    //repf (i, 0, sz(num2)-1) tst (num2[i]);
    //cout << endl;

    clr (d, 0);
    int nxt = 1, now = 0;
    for (int i = 0; i < sz(num2); ++ i){
        clr (d[nxt], 0);
        d[nxt][num2[i]][1] = 1 + d[now][1][1];
        d[nxt][num2[i]^1][1] = d[now][0][1];

        d[nxt][0][0] = d[now][0][0] + d[now][0][1];
        d[nxt][1][0] = d[now][1][0] + d[now][1][1];
        swap (now, nxt);
    }
    //out (d[now][1][0] + d[now][1][1]);
    ans1 += d[now][1][0] + d[now][1][1];
    ans2 += d[now][0][0] + d[now][0][1];
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%s", s) != EOF){
        n = strlen(s);
        num.clear();
        repf (i, 0, n-1){
            if (!i || s[i] != s[i-1]) num.pb (1);
            else ++ num[sz(num)-1];
        }
        //repf (i, 0, sz(num)-1) tst (num[i]);
        //cout << endl;
        ans1 = ans2 = 0;
        for (int x : num){
            if (x & 1){
                ans1 += 1LL * (x+1) * (x+1) / 4;
                ans2 += 1LL * (x+1) * (x-1) / 4;
            }
            else{
                ans1 += 1LL * (x+2) * x / 4;
                ans2 += 1LL * x * x / 4;
            }
            //tst (x), tst (ans2), out (ans1);
        }
        solve (0); solve (1);
        cout << ans2 << " " << ans1 << endl;
    }
    return 0;
}
