/*
 * Author:  Plumrain
 * Created Time:  2014-03-30 15:03
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

vector <pii > vec;

int gao (int a, int b){
    int t = sqrt (b*b - a*a + 0.0);
    int tt = max (1, t-2);
    repf (i, tt, t+2){
        if (i*i + a*a == b*b) return i;
    }
    return -1;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("1.ans","w",stdout);
//    std::ios::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b){
        vec.clear();
        vec.pb (mp (0, 0));
        repf (i, 1, a-1) repf (j, 1, b-1) if (sz(vec) == 1){
            int t1 = gao (i, a), t2 = gao (j, b);
            if (t1 == -1 || t2 == -1) continue;
            if (t1 == t2) continue;
            if (t1*t1 + t2*t2 + i*i + j*j != (j+i)*(j+i) + (t1-t2)*(t1-t2)) continue;
            vec.pb (mp (-i, t1)); vec.pb (mp (j, t2));

            if (sz(vec) > 1) break;
        }

        if (sz(vec) == 1) printf ("NO\n");
        else{
            printf ("YES\n");
            repf (i, 0, sz(vec)-1) printf ("%d %d\n", vec[i].first, vec[i].second);
        }
    }
    return 0;
}
