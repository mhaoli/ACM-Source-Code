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
#include <complex>
#define tst(x) cout<<(x)<<" ";
#define out(x) cout<<#x<<" "<<(x)<<endl;
using namespace std;
typedef unsigned long long UL;
const int N = 9 + (int)6e4;
const UL seed = 257;
struct nod{
    int v, id;
    void setIt (int _v, int i){
        v = _v; id = i;
    }
}a[N];

char ss[N], op[10];
bool fg[N];
int idx[N], n;
UL has[N], pp[N];

UL Hash (int p, int l){
    return p ? has[p+l-1] - has[p-1]*pp[l] : has[p+l-1];
}
int query (int t1, int t2){
    if (t1 == t2) return n - t1;
    if (t1 > t2) swap (t1, t2);
    int res = 0;
    for (int l = 0, r = n, m; m = (l+r) >> 1, l <= r; ){
        if (t2 + m <= n && Hash(t1,m) == Hash(t2,m)) res = m, l = m + 1;
        else r = m - 1;
    }
    return res;
}
void calc (){
    for (int i = 0; i < n; ++ i) 
        has[i] = i ? a[i].v + has[i-1]*seed : a[i].v;
}
int main(){
    for (int i = 0; i < N; ++ i)
        pp[i] = i ? pp[i-1]*seed : 1;

    scanf ("%s", ss);
    n = strlen (ss);
    memset (fg, 1, sizeof fg);
    for (int i = 0; i < n; ++ i)
        idx[i+1] = i, a[i].setIt (ss[i], i+1);

    bool u = 1;

    int m, p, t1, t2;
    nod tmp;
    scanf ("%d", &m);
    while (m--){
        scanf ("%s", op);
        if (op[0] == 'I'){
            scanf ("%s%d", op, &p);
            tmp = a[--p];
            a[p].setIt (op[0], 0);
            bool tfg = fg[p]; fg[p] = 0;

            for (int i = p+1; i <= n; ++ i){
                if (tfg) idx[tmp.id] = i;
                swap (tfg, fg[i]);
                swap (tmp, a[i]);
            }
            ++ n; u = 1;
        } else{
            if (u) calc (), u = 0;
            scanf ("%d%d", &t1, &t2);
            printf ("%d\n", query (idx[t1], idx[t2]));
        }
    }
    return 0;
}
