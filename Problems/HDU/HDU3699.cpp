/*
 * Author:  Plumrain
 * Created Time:  2014/8/26 12:53:49
 * File Name: J.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 num[55];
int ans;
bool vis[55], vis_dig[55];
string str[11];
map<char, int> has;

int64 calc (const string &s){
    int64 res = 0;
    rep (i, 0, sz(s)-1){
        int t = has[s[i]];
        if (i == 0 && t == 0 && sz (s) > 1) return -1;
        res = res * 10 + t;
    }
    return res;
}

void dfs (int p){
    if (p == 5){
        rep (i, 0, 2){
            num[i] = calc (str[i]);
            if (num[i] == -1) return;
        }
        //tst (num[0]), tst (num[1]), out (num[2]);
        if (num[0] + num[1] == num[2]) ++ ans;
        if (num[0] - num[1] == num[2]) ++ ans;
        if (num[0] * num[1] == num[2]) ++ ans;
        if (num[1] != 0 && num[1] * num[2] == num[0]) ++ ans;
        return ;
    }

    if (!vis[p]) dfs (p + 1);
    else{
        rep (i, 0, 9) if (!vis_dig[i]){
            has[(char)(p + 'A')] = i;
            vis_dig[i] = 1;
            dfs (p + 1);
            vis_dig[i] = 0;
        }
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        clr (vis, 0);
        rep (i, 0, 2) cin >> str[i];
        rep (i, 0, 2) rep (j, 0, sz (str[i])-1) vis[str[i][j]-'A'] = 1;

        ans = 0;
        clr (vis_dig, 0);
        dfs (0);
        printf ("%d\n", ans);
    }
    return 0;
}
