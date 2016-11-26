namespace Dijkstra {
        const int maxn = 1e3;
        int dis[maxn + 5];
        int n;
        vector<vii > G;
        //G[x] = (y,t): x -> y, value = t
        void init(int _n, vector<vii > _G) {
                n = _n; G = _G;
        }
        vi getMin(int S) {
                memset(dis, -1, n * (sizeof(dis[0])));
                dis[S] = 0;
                set<pii > q;
                q.insert(mp(0, S));
                while(SZ(q)) {
                        pii x = *q.begin(); q.erase(q.begin());
                        for(pii t : G[x.y]) {
                                if(dis[t.x] == -1 || dis[t.x] > x.x + t.y) {
                                        q.erase(mp(dis[t.x], t.x));
                                        dis[t.x] = x.x + t.y;
                                        q.insert(mp(dis[t.x], t.x));
                                }
                        }
                }
                return vi(dis, dis + n);

        }
}
