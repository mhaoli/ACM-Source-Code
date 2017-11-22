struct Edge{
    int t;
    ll w;
    Edge *nxt;
    Edge(){}
    Edge(int _t,ll _w):t(_t),w(_w){}
    void set(int _t, long long _w, Edge *n){
        t = _t; w = _w; nxt = n;
    }
};
Edge pool[Max_N], *head[Max_N], *bat;
void init_graph(int n){
    bat = pool;
    memset(head, 0, n * sizeof head[0]);
}
void add_edge(int s, int t, long long w){
    bat->set(t, w, head[s]); head[s]=bat++;
}
