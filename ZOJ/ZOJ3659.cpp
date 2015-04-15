#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;
#define x first
#define y second
#define out(x) cout<<#x<<":"<<(x)<<endl;
typedef pair<int, int> pii;

const int N = 2222;

struct square{
    int f, l, r, shu, cnt;
    pii a, b;
    void read (){
        scanf ("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
        shu = a.x == b.x ? 1 : 0;
        l = r = f = -1;
        cnt = 1;
    }
}a[N], tar;

bool line (square &A, pii &B){
    if (B == A.a || B == A.b) return 0;
    if (A.shu){
        if (B.x != A.a.x) return 0;
        if (B.y > max (A.a.y, A.b.y) || B.y < min (A.a.y, A.b.y)) return 0;
        return 1;
    } else{
        if (B.y != A.a.y) return 0;
        if (B.x > max (A.a.x, A.b.x) || B.x < min (A.a.x, A.b.x)) return 0;
        return 1;
    }
}

void dfs (int p){
    if (~a[p].l){
        dfs (a[p].l); a[p].cnt += a[a[p].l].cnt;
    }
    if (~a[p].r){
        dfs (a[p].r); a[p].cnt += a[a[p].r].cnt;
    }
}

int ans;

void solve (int p){
    if (p == -1) return ;
    if (a[p].shu){
        int x = a[p].a.x;
        if ((x - tar.a.x > 0) != (x - tar.b.x > 0)){
            ans = a[p].cnt; 
            return;
        } else{
            if (x > tar.a.x) solve (a[p].l);
            else solve (a[p].r);
        }
    } else{
        int y = a[p].a.y;
        if ((y - tar.a.y > 0) != (y - tar.b.y > 0)){
            ans = a[p].cnt; return;
        } else{
            if (y > tar.a.y) solve (a[p].l);
            else solve (a[p].r);
        }
    }
}

int main(){
    int x0, y0, x1, y1;
    while (cin >> x0 >> y0 >> x1 >> y1){
        int n, q; scanf ("%d%d", &n, &q);
        for (int i = 0; i < n; ++ i){
            a[i].read ();
            if (i){
                for (int j = i-1; j >= 0 && a[i].f == -1; -- j){
                    if (line (a[j], a[i].b)) swap (a[i].a, a[i].b);
                    if (line (a[j], a[i].a)){
                        a[i].f = j;
                        if (a[j].shu){
                            if (a[i].b.x < a[j].a.x) a[j].l = i;
                            else a[j].r = i;
                        } else{
                            if (a[i].b.y < a[j].a.y) a[j].l = i;
                            else a[j].r = i;
                        }
                    }
                }
            } else a[i].f = -1;
        }

        dfs (0);

        while (q--){
            tar.read ();
            ans = 0;
            solve (0);
            printf ("%d\n", 1 + n - ans);
        }
    }
    return 0;
}
