/*
 * Author:  Plumrain
 * Created Time:  2014/4/25 15:29:07
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
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    string s;
    while (cin >> n >> s){
        int cnt = 0;
        repf (i, 0, n-1) if (s[i] == 'x') ++ cnt;
        int ans = n/2 - cnt;
        cout << abs(ans) << endl;
        if (ans == 0) cout << s << endl;
        else if (ans < 0){
            repf (i, 0, n-1){
                if (s[i] == 'X') cout << s[i];
                else if (ans) cout << 'X', ++ ans;
                else cout << 'x';
            }
            cout << endl;
        }
        else{
            repf (i, 0, n-1){
                if (s[i] == 'x') cout << s[i];
                else if (ans) cout << 'x', -- ans;
                else cout << 'X';
            }
            cout << endl;
        }
    }
    return 0;
}
