/*
 * Author:  Plumrain
 * Created Time:  2014/8/18 23:17:23
 * File Name: D.cpp
 */
struct nod{
    nod *pre, *ch[2];
    int id, s, sum, v;
    int add;
    bool rev;
    void up (){
        if (id == -1) return;
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
    }
}Tnull, *null = &Tnull, memo[maxn<<3], *bat = memo;

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

nod *rt;

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
void splay (nod *x, nod *go, nod *&r){
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
void rto(int k, nod *go, nod *&r){
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
    splay (x, go, r);
}

//删除区间[x, y]
void del (int p, nod *&r){
    rto (p-1, null, r);
    rto (p+1, r, r);
    ket = null;
    r->ch[1]->up(); r->up();
}

/*
void debug (nod *x){
    if (x != null){
        printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d",
                x->id, lson->id, rson->id, x->s);
        if (x->link != 0) printf (" link: %2d", x->link->cnt ());
        puts ("");
        x->down();
        debug (lson);
        debug (rson);
    }
}
*/

nod *newnod (int c, nod *f){
    nod *x = bat++;
    x->id = c; x->s = 1;
    x->pre = f; lson = rson = null;
    return x;
}
//初始时根节点为0
//最小的元素是第0小，为-inf
//from 1
void init(nod *&r){
    r = newnod (-inf, null);
    r->ch[1] = newnod (inf, r);
    r->ch[1]->up(); r->up();
}
//c与节点值相同时放右子树
void insert (int c, nod *&r){
}

// 0 prev, 1 next
nod *find (nod *x, int c){
    while (x->ch[c]->pre) x = x->ch[c];
    return x;
}

void del_nod (nod *x, nod *&r){
    splay (x, null, r);
    nod *y = find (x->ch[0], 1), *z = find (x->ch[1], 0);
    splay (y, null, r); splay (z, r, r); 
    ket = null; r->ch[1]->up (); r->up ();
}

//from 0 begin
nod *find_kth (nod *x, int k){
    if (lson->s == k) return x;
    if (lson->s > k) return find_kth (lson, k);
    return find_kth (rson, k - lson->s - 1);
}

int main()
{
    return 0;
}
