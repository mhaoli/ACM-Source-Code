#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second
typedef long long ll;
template<class T> bool chmin (T&a, const T&b){return b < a ? a = b, 1 : 0;}
template<class T> bool chmax (T&a, const T&b){return b > a ? a = b, 1 : 0;}

void R(int &ret){
    ret = 0;
    bool ok = 0;
	for( ; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
		else if (ok) return;
	}
}

const int N = int(1e4) + 9;
const int M = int(1e5) + 9;
struct Edge{
    int v;
    Edge *nxt;
    void add (int _v, Edge*n){
        v = _v; nxt = n;
    }
};

Edge e[M<<1], *bat, *head[N];
int col[N], tot, UP, deg[N];

void adde (int u, int v){
    bat->add (v, head[u]); head[u] = bat++;
}

bool dfs (int u){
    vector<int> vec;
    for (Edge*p = head[u]; p; p = p->nxt){
        if (~col[p->v]) vec.push_back (col[p->v]);
    }

    sort (vec.begin (), vec.end ());
    vec.erase (unique (vec.begin(), vec.end ()), vec.end ());
    int siz = vec.size (), cnt = 0;
    for (; cnt < siz && cnt == vec[cnt]; ++ cnt);
    col[u] = cnt;

    for (Edge*p = head[u]; p; p = p->nxt){
        if (col[p->v] == -1) dfs (p->v);
    }
    return 0;
}

int main(){
    int m, n;
    bool blank = 0;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (blank) puts ("");
        blank = 1;

        if (n < 1000) for (int i = 0; i < n; ++ i) head[i] = 0;
        else memset (head, 0, sizeof head);
        memset (deg, 0, sizeof deg);
        bat = e;
        for (int i = 0; i < m; ++ i){
            int u, v;
            R (u); R (v); -- u; -- v;
            adde (u, v); adde (v, u);
            ++ deg[u]; ++ deg[v];
        }

        memset (col, -1, (n + 5) * 4);
        UP = 0;
        for (int i = 0; i < n; ++ i) chmax (UP, deg[i]);
        if (!(UP & 1)) ++ UP;
        dfs (0);
        printf ("%d\n", UP);
        for (int i = 0; i < n; ++ i) printf ("%d\n", col[i] + 1);
    }
    return 0;
}
