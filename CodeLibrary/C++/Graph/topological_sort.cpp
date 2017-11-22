namespace Top_Sort{
    int in[Max_N];
    void sort(int n, int *top, Edge *hd[]){
        memset(in, 0, n * sizeof in[0]);
        set<pii> has;
        rep(i, 0, n){
            for(Edge *p = hd[i]; p; p = p->nxt){
                ++in[p->t];
            }
        }
        int idx = 0;
        rep(i, 0, n){
            has.insert(pii(in[i],i));
        }
        while(!has.empty()){
            top[idx++] = has.begin()->second;
            has.erase(has.begin());
            for(Edge *p = hd[top[idx-1]]; p; p = p->nxt){
                int tar = p->t;
                has.erase(pii(in[tar],tar));
                has.insert(pii(--in[tar],tar));
            }
        }
    }
}

