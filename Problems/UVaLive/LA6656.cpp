#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
using namespace std;
#define x first
#define y second
template<class T> T chmax(T &a, const T&b){return a < b ? a = b, 1 : 0;}
typedef pair<int, int> pii;
const int N = 9 + (int)1e5;

void Read(int &ret){
    ret = 0;
    bool ok = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
		else if (ok) return;
	}
}

struct seg{
    int x, y, id;
    void read(){
        //scanf ("%d%d", &x, &y);
        Read (x); Read (y);
        x <<= 1; y <<= 1; id = 0;
    }
    bool operator<(const seg&t)const{
        return x == t.x ? y < t.y : x < t.x;
    }
    bool operator==(const seg&t)const{
        return x == t.x && y == t.y;
    }
}a[N];

pii q[N], temp;
int ans[N];
vector<pii> mid, px, py;
set<pii> le;
set<pii, greater<pii > > ri;

int main(){
    int T, cas = 0; scanf ("%d", &T);
    while (T--){
        printf ("Case %d:\n", ++ cas);

        int n, m;
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < n; ++ i) a[i].read ();
        sort (a, a + n);
        //n = unique (a, a + n) - a;
        int tot = 1;
        for (int i = 1; i < n; ++i)
             if (a[i] == a[tot-1]) continue;
             else a[tot++] = a[i];
        n = tot;

        mid.clear (); px.resize (n); py.resize (n);
        for (int i = 0; i < n; ++ i){
            temp.x = (a[i].x>>1) + (a[i].y>>1); temp.y = i;
            mid.push_back (temp);

            temp.y = a[i].id = i;
            temp.x = a[i].x; px[i] = temp;
            temp.x = a[i].y; py[i] = temp;
        }
        sort (px.begin (), px.end ());
        sort (py.begin (), py.end ());

        for (int i = 0; i < m; ++ i){
            //scanf ("%d", &q[i].x);
            Read (q[i].x);
            q[i].y = i;
            q[i].x <<= 1;
        }
        sort (q, q + m);

        le.clear (); ri.clear ();
        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 0; i < m; ++ i){
            while (t1 < n && px[t1].x <= q[i].x){
                le.insert (px[t1++]);
            }
            while (t2 < n && mid[t2].x <= q[i].x){
                temp.x = a[mid[t2].y].x; temp.y = mid[t2].y;
                le.erase (temp);
                temp.x = a[mid[t2].y].y;
                ri.insert (temp);
                ++ t2;
            }
            while (t3 < n && py[t3].x <= q[i].x){
                ri.erase (py[t3++]);
            }
            ans[q[i].y] = 0;
            if (le.size ()) chmax (ans[q[i].y], q[i].x - (*le.begin()).x);
            if (ri.size ()) chmax (ans[q[i].y], (*ri.begin()).x - q[i].x);
            //ans[q[i].y] = min (q[i].x - (*px.begin()).x, (*py.begin()).y - q[i].x);
        }
        for (int i = 0; i < m; ++ i) printf ("%d\n", ans[i] >> 1);
    }
    return 0;
}
