/*
 * Author:  Plumrain
 * Created Time:  2014/8/30 0:20:05
 * File Name: Splay.cpp
 */
#define lson x->ch[0]
#define rson x->ch[1]

struct nod{
    nod *pre, *ch[2];
    int s, sum, v;
    int add;
    bool rev;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down ();
    void addIt (int x){
        add += x; v += x; sum += x;
    }
    void revIt (){
        swap (ch[0], ch[1]); 
        rev ^= 1;
    }
    bool q(){
        return this == pre->ch[1];
    }
    void setc (nod *c, int d){
        ch[d] = c;
        c->pre = this;
        this->up ();
    }
}Tnull, *null = &Tnull, memo[666666], *bat;

nod *link[maxn];

void nod::down (){
    if (add != 0){
        for (int i = 0; i < 2; ++ i)
            if (ch[i] != null) ch[i]->addIt (add);
        add = 0;
    }
    if (rev){
        for (int i = 0; i < 2; ++ i)
            if (ch[i] != null) ch[i]->revIt ();
        rev = 0;
    }
}

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
}

//把第k大的数旋转到go, idx from 0
//返回操作以后Splay的根
nod *rto(int k, nod *go, nod *r){
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
    return x;
}

//删除区间[x, y]
void del (int p, nod *x){
    splay (x, null);
    x = rto (p-1, null, x);
    rto (p+1, x, x);
    x->ch[1]->ch[0] = null;
    x->ch[1]->up(); x->up();
}

/*
void debug (nod *x){
    if (x != null){
        printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d",
                x->v, lson->v, rson->v, x->s);
        puts ("");
        x->down();
        debug (lson);
        debug (rson);
    }
}
*/

nod *newnod (int c, nod *f = null){
    nod *x = bat++;
    x->v = c; x->s = 1;
    x->pre = f;
    lson = rson = null;
    return x;
}
//初始时根节点为0
//最小的元素是第0小，为-inf
//from 1
nod *init(int c){
    nod *r = newnod (-inf);
    r->setc (newnod (inf), 1);
    return r;
    //r->ch[1]->setc (newnod (c), 0);
    //r->up ();
    //return r->ch[1]->ch[0];
}
//c与节点值相同时放左子树
void insert (nod *x, nod *r){
    int tid = 0;
    nod *pre = null;
    while (r->pre){
        pre = r;
        if (x->v <= r->v) r = r->ch[0], tid = 0;
        else r = r->ch[1], tid = 1;
    }
    x->s = 1;
    x->ch[0] = x->ch[1] = null;
    pre->setc (x, tid);
    splay (x, null);
}

// 0 prev, 1 next
nod *find (nod *x, int c){
    while (x->ch[c]->pre) x = x->ch[c];
    return x;
}

//返回删除节点后的Splay的根
nod *del_nod (nod *x){
    splay (x, null);
    nod *y = find (x->ch[0], 1), *z = find (x->ch[1], 0);
    splay (y, null); splay (z, y); 
    z->ch[0] = null; z->up (); y->up ();
    return y;
}

int main()
{
    return 0;
}
