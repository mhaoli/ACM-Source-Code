/*
 * Author:  Plumrain
 * Created Time:  2014/8/4 19:34:54
 * File Name: Splay Tree.cpp
 */

//before use : init();

struct nod{
    nod *pre, *ch[2];
    int id, s, u;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down (){
        if (u){
            if (ch[0]->pre){
            }
            if (ch[1]->pre){
            }
            u = 0;
        }
    }
};

struct Splay{
#define lson x->ch[0]
#define rson x->ch[1]
#define ket (r->ch[1]->ch[0])
    const static int maxn = ; // max node number
    const static int inf = ;     //-inf is min value and inf is max value

    int tot;
    nod an[maxn], nod0, *null, *r;

    //c = 0 left, c = 1 right
    void rotate (nod *x, int c){
        nod *y = x->pre;
        y->down(); x->down();

        y->ch[!c] = x->ch[c];
        if (x->ch[c] != null) x->ch[c]->pre = y;
        x->pre = y->pre;
        if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
        x->ch[c] = y; y->pre = x;

        y->up();
    }

    //旋转到go节点下面，如果旋转到根go = null
    void splay (nod *x, nod *go){
        while (x->pre != go){
            if (x->pre->pre == go) rotate (x, x->pre->ch[0] == x);
            else{
                nod *y = x->pre, *z = y->pre;
                int f = z->ch[1] == y;
                if (y->ch[f] == x) rotate (y, !f);
                else rotate (x, f);
                rotate (x, !f);
            }
        }
        x->up();
        if (go == null) r = x;
    }

    //把第k大的数旋转到go, idx from 0
    void rto(int k, nod *go){
        nod *x = r;
        x->down();
        while (lson->s != k){
            if (lson->s > k) x = lson;
            else{
                k -= lson->s + 1;
                x = rson;
            }
            x->down();
        }
        splay (x, go);
    }

    //删除区间[x, y]
    nod *del (int x, int y){
        rto (x-1, null); rto (y+1, r);
        nod *ret = ket;
        ket = null;
        r->ch[1]->up(); r->up();
        return ret;
    }


    //void debug (nod *x){
        //if (x != null){
            //printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d val: %2d\n",
                    //x->id, lson->id, rson->id, x->s, x->v);
            //x->down();
            //debug (lson);
            //debug (rson);
        //}
    //}

    nod *newnod (int c, nod *f){
        nod *x = &an[tot++];
        x->id = c; x->s = 1; x->u = 0;
        x->pre = f; lson = rson = null;
        return x;
    }
    //初始时根节点为0
    //最小的元素是第0小，为-inf
    //from 1
    void init(){
        null = &nod0;
        null->id = -1; null->s = null->v = null->u = 0;
        tot = 1;
        r = newnod (-inf, null);
        r->ch[1] = newnod (inf, r);
        r->ch[1]->up(); r->up();
    }
    //c与节点值相同时放右子树
    void insert (int c){
        nod *x = r;
        while (x->ch[x->id <= c] != null){
            x->down();
            x = x->ch[x->id <= c];
        }
        x->down();
        x->ch[x->id <= c] = newnod (c, x);
        splay (x->ch[x->id <= c], null);
    }

    
    //调用的时候x为r
    //以x为根的树上，比c小的元素有多少个(包含-inf)
    int find_cnt(nod *x, int c){
        if (x == null) return 0;
        x->down();
        if (x->id < c) return lson->s + 1 + find_cnt (rson, c);
        else return find_cnt (lson, c);
    }

    //from 0 begin
    nod *find_kth (nod *x, int k){
        if (lson->s == k) return x;
        if (lson->s > k) return find_kth (lson, k);
        return find_kth (rson, k - lson->s - 1);
    }
};

Splay gao;
