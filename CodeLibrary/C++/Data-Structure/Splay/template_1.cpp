/*
 * Author:  Plumrain
 * Created Time:  2014/8/4 16:01:47
 * File Name: Splay-Tree.cpp
 */

//before use : init();

struct nod{
    int a[2], n;
    nod(){
        a[0] = a[1] = -1;
    }
    int q(int x){
        if (x == n) return -1;
        return x < n ? 0 : 1;
    }
};

struct Splay{
    const static int maxn = ;  //max node number
    const static int inf = ; // inf is max ans -inf is min value

    int r, tot;
    nod an[maxn];
    void init (){
        tot = 0; r = -1;
        gao.insert (r, -inf);
        gao.insert (r, inf);
    }
    void newnod (int &r, int x){
        an[r=tot++].n = x;
    }
    bool insert (int &t, int x){
        if (t == -1){
            newnod (t, x); splay (r, x); return 1;
        }
        int q = an[t].q(x);
        if(q == -1){
            splay (t, x); return 0;
        }
        return insert (an[t].a[q], x);
    }
    //x = 0，找节点t为根的树上的最左（最小）的点，x = 1找最右的点（最大）
    int find (int t, int x){
        while (~an[t].a[x]) t = an[t].a[x];
        return an[t].n;
    }
    //将t的q儿子旋转到t位置，t变成其原q儿子的儿子
    void rotate (int &t, int q){
        int k = an[t].a[q];
        an[t].a[q] = an[k].a[q^1];
        an[k].a[q^1] = t;
        t = k;
    }
    void splay (int &t, int x){
        int q = an[t].q(x);
        if (q == -1) return;
        int p = an[t].a[q], q2 = an[p].q(x);
        if (~q2){
            splay (an[p].a[q2], x);
            if (q == q2) rotate (t, q);
            else rotate (an[t].a[q], q2);
        }
        rotate (t, q);
    }
}gao;
