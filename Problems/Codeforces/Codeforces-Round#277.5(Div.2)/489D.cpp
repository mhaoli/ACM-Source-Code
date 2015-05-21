#include<bits/stdc++.h>
using namespace std;
bitset<3005> to[3005], from[3005];
struct Edge{
        int v; Edge *nxt;
        void add (int _v, Edge*n){ v = _v; nxt = n;}
}mem[60005], *bat=mem, *head[3005];
void adde (int u, int v){
        bat->add (v, head[u]); head[u]=bat++;
}
int main(){
        int n, m;
        scanf ("%d%d", &n, &m);
        memset (head, 0, sizeof head);
        for (int u, v, i = 0; i < m; ++i){
                scanf ("%d%d", &u, &v);
                adde (--u, --v);
                to[u][v] = 1;
                from[v][u] = 1;
        }

        Edge *p;
        bitset<3005> tmp;
        long long t, ans = 0;
        for (int i = 0, j; i < n; ++i){
                tmp.reset ();
                //printf ("%d : ", i);
                for (p = head[i]; p; p = p->nxt){
                        //printf ("%d ", p->v);
                        tmp |= to[p->v];
                }
                //puts ("");
                //printf ("%d %d\n", i, tmp.count());
                for (j = 0; j < n; ++j) if (j != i && tmp[j]){
                        t = (from[j] & to[i]).count();
                        if (t > 1) ans += t * (t-1) / 2;
                }
        }
        cout << ans << endl;
        return 0;
}
