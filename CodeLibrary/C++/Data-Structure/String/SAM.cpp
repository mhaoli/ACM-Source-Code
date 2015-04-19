/*
 * Author:  Plumrain
 * Created Time:  2014/8/24 12:20:33
 * File Name: SAM.cpp
 */
struct SAM{
    //注意多组数据要调用clear()函数..
    const static int maxs = ;
    const static int maxn = ;

    struct State{
        State *suf, *ch[maxs], *nxt;
        int mx, mi, cnt;
        //void clear(){
            //suf = 0; mi = mx = cnt = 0;
            //memset (ch, 0, sizeof ch);
        //}
    }*rt, *last;

    int L;
    State memo[maxn<<1], *bat;
    State *head[maxn];

    void init (){
        bat = memo;
        rt = last = bat ++; 
        //rt->clear();
    }
    void extend (int w){
        State *p = last, *np = bat++; 
        //np->clear();
        np->mx = p->mx + 1;
        np->cnt = 1;
        while (p && !p->ch[w])
            p->ch[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->ch[w];
            if (p->mx + 1 == q->mx) np->suf = q;
            else{
                State *nq = bat++; 
                //nq->clear();
                memcpy (nq->ch, q->ch, sizeof q->ch);
                nq->mx = p->mx + 1;
                nq->suf = q->suf;
                q->suf = nq;
                np->suf = nq;
                while (p && p->ch[w] == q)
                    p->ch[w] = nq, p = p->suf;
            }
        }
        last = np;
    }

    void topo (int _L){
        L = _L;
        memset (head, 0, sizeof head);
        for (State *p = memo; p != bat; ++ p){
            p->nxt = head[p->mx], head[p->mx] = p;

            if (p->suf) p->mi = p->suf->mx + 1;
            //else p->mi = 1;
        }

        for (int i = L; i >= 0; -- i)
            for (State *p = head[i]; p; p = p->nxt)
                if (p->suf) p->suf->cnt += p->cnt;
    }

    /*********************/
}gao;

int main()
{
    scanf ("%s", str);
    gao.init ();
    int n = strlen (str);
    rep (i, 0, n-1) gao.extend (str[i] - 'a');
    return 0;
}
