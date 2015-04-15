/*
 * Author:  Plumrain
 * Created Time:  2014/7/26 18:36:31
 * File Name: 447.cpp
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vector<pair<string, int> > vec;
char s[maxn];
int temp[] = {1, 16, 2, 32, 4, 64, 8};
int idx[1000], num[100];
int has[3201000];

bool cmp (pair<string, int> a, pair<string, int> b){
    return a.x + "R" < b.x + "R";
}

void init (int t1, int t2){
    t1 = temp[t1]; t2 = temp[t2];
    string t, tt;
    t.pb ('R');

    stringstream ss;
    ss << t1; ss >> tt;
    t += tt;
    
    int sum = 0;
    for (int i = t1; i != t2; i *= 2) t.pb ('.'), sum += (64 / i);
    sum += (64 / t2);
    vec.pb (mp (t, sum));
}

int dfs_len (int sum){
    int &ret = has[sum];
    if (ret != -1) return ret;
    ret = inf;
    repf (i, 0, sz(vec)-1) if (vec[i].y <= sum){
        chmin (ret, dfs_len (sum - vec[i].y) + sz(vec[i].x));
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    vec.clear();
    repf (i, 0, 6) repf (j, 0, 6) if (temp[j] >= temp[i]) init(i, j);
    sort (all (vec), cmp);
    repf (i, 0, 6) idx[temp[i]] = i;

    scanf ("%s", s);
    int n = strlen(s), pos = 0, sum = 0;
    while (pos < n){
        if (s[pos] == 'R'){
            int cnt = 0; ++ pos;
            while (pos < n && (s[pos] >= '0' && s[pos] <= '9')) cnt = cnt * 10 + s[pos++] - '0';
            sum += (64 / cnt);
            while (pos < n && s[pos] == '.') sum += (32 / cnt), cnt *= 2, ++ pos;
        }
    }

    string ans;
    clr (has, -1); has[0] = 0;
    int len = dfs_len (sum);
    while (sum){
        int tmp = has[sum];
        repf (i, 0, sz(vec)) if (sum >= vec[i].y && has[sum-vec[i].y] + sz (vec[i].x) == tmp){
            ans += vec[i].x; sum -= vec[i].y; break;
        }
    }
    cout << ans << endl;
    return 0;
}
