#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
const double eps = 1e-12;
struct Edge {
        int s, e;
        double dis;
        bool operator < (const Edge &t) const {
                return dis < t.dis;
        }
};
vector<Edge> E;
int x[111], y[111], f[111];
#define sqr(x) ((x) * (x))
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
double dis(int a, int b) {
        return sqrt(sqr(x[a] - x[b] + 0.0) + sqr(y[a] - y[b] + 0.0));
}
int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
}
bool kruskal (int n, int L) {
        sort(E.begin(), E.end());
        for(int i = 0; i < n; ++i) f[i] = i;
        double sum = 0;
        snuke(it, E) {
                if(find(it->s) == find(it->e)) continue;
                f[find(it->s)] = find(it->e);
                sum += it->dis;
        }
        return sum <= L;
}
int main() {
        int n, L;
        while(1) {
                if(scanf("%d", &n), !n) break;
                scanf("%d", &L);
                for(int i = 0; i < n; ++i) {
                        scanf("%d%d", x + i, y + i);
                }
                
                E.clear();
                Edge tmp;
                for(int i = 0, j; i < n; ++i) {
                        for(j = i+1; j < n; ++j) {
                                tmp.s = i; tmp.e = j; tmp.dis = dis(i, j);
                                E.push_back(tmp);
                        }
                }
                puts(kruskal(n, L) ? "Success!" : "Poor magicpig!");
        }
        return 0;
}
