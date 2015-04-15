/*
 * Author:  Plumrain
 * Created Time:  2014-03-20 00:25
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
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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

set<char> st;
vs an;

int n;

bool ok(){
    if (an[0][0] == an[0][1]) return 0;
    st.clear(); st.insert (an[0][0]);
    repf (i, 0, n-1) if (!st.count(an[i][i])) return 0;
    repf (i, 0, n-1) if (!st.count(an[i][n-1-i])) return 0;

    st.insert (an[0][1]);
    repf (i, 0, n-1) repf (j, 0, n-1) if (i != j && i+j != n-1) 
        if (an[i][j] == an[0][0] || !st.count(an[i][j])) return 0;
    return 1;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    string tmp;
    while (cin >> n){
        an.clear();
        repf (i, 1, n){
            cin >> tmp; an.pb (tmp);
        }
        if (ok()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
