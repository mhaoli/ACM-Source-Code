/*
 * Author:  Plumrain
 * Created Time:  2014-02-15 14:22
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 15005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

struct nod{
    int w, l, p;
};

int n, num[N];
vi idx[N], des;
nod an[N];

int bin_search(int idx, int key)
{
    if (key < 0) return idx;
    if (num[idx] <= key) return -1;

    int ret, l = 0, r = idx-1;
    while (l <= r){
        int mid = (l + r) >> 1;
        int tmp;
        if (!mid) tmp = num[idx];
        else tmp = num[idx] - num[mid-1];

        if (tmp > key) ret = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d%d%d", &an[i].w, &an[i].l, &an[i].p);
        for (int i = 0; i < n-1; ++ i)
            if (an[i].w > an[i].l) an[i+1].w += an[i].w, an[i].w = an[i].p = 0;
        if (an[n-1].w > an[n-1].l) continue;

        num[0] = an[0].w;
        for (int i = 1; i < n; ++ i)
            num[i] = num[i-1] + an[i].w;

        for (int i = 0; i < n; ++ i) idx[i].clear();
        for (int i = 0; i < n; ++ i){
            int tmp = bin_search(i, an[i].l);
            if (tmp != -1) idx[tmp].pb (i);
        }

        //for (int i = 0; i < n; ++ i){
            //out (i);
            //for (int j = 0; j < sz(idx[i]); ++ j) tst (idx[i][j]);
            //cout << endl;
        //}
//
        int ans = an[n-1].p, flag = n-1, sum = an[n-1].p;
        for (int i = n-2; i >= 0; -- i){
            sum += an[i].p;
            for (int j = 0; j < sz(idx[i]); ++ j)
                sum -= an[idx[i][j]].p;
            if (sum < ans) ans = sum, flag = i;
        }

        des.clear();
        int tot = 0;
        for (int i = flag; i < n; ++ i){
            if (tot + an[i].w <= an[i].l) des.pb (i + 1);
            tot += an[i].w;
        }
        for (int i = 0; i < sz(des); ++ i) printf ("%d\n", des[i]);
    }
    return 0;
}
