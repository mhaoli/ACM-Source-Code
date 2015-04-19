
//静态数组版
/* **********************************************
Author      : JayYe
Created Time: 2013-8-16 11:14:36
File Name   : zzz.cpp
*********************************************** */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define LL __int64
#define keytree (ch[ ch[root][1] ][0])
#define lson ch[x][0]
#define rson ch[x][1]

const int maxn = 111111;

struct Splaytree {

    int pre[maxn], ch[maxn][2], sz[maxn];
    int root, top;
    // 旋转操作， c = 0代表左旋， c = 1代表右旋
    void Rotate(int x, int c) {
        int y = pre[x];
        push_down(y), push_down(x);
        ch[y][!c] = ch[x][c];
        pre[ch[x][c]] = y;
        if(pre[y])  ch[pre[y]][ ch[pre[y]][1] == y ] = x;
        pre[x] = pre[y];
        ch[x][c] = y;
        pre[y] = x;
        push_up(y);
    }
    // Splay 操作， 把 x 节点转到go的下面
    void Splay(int x, int go) {
        while(pre[x] != go) {
            if(pre[pre[x]] == go) {
                Rotate(x, ch[pre[x]][0] == x);
            }
            else {
                int y = pre[x] , z = pre[y];
                int f = (ch[z][1] == y);
                if(ch[y][f] == x)  
                    Rotate(y, !f), Rotate(x, !f); // 一字型旋转
                else
                    Rotate(x, f), Rotate(x, !f); // 之字型旋转
            }
        }
        push_up(x);
        if(go == 0) root = x;
    }
    // 将第k位的数旋转到go的下面
    void RotateTo(int k, int go) {
        int x = root;
        push_down(root);
        while(sz[lson] != k) {
            if(k < sz[lson]) {
                x = lson;
            }
            else {
                k -= sz[lson] + 1;
                x = rson;
            }
            push_down(x);
        }
        Splay(x, go);
    }

    void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x]);
			Treaval(ch[x][1]);
		}
	}
    

    int val[maxn], add[maxn], a[maxn];
    LL sum[maxn];
    // 把儿子节点的信息更新上来
    void push_up(int x) {
        sz[x] = sz[lson] + sz[rson] + 1;
        sum[x] = val[x] + add[x] + sum[lson] + sum[rson];
    }
    // 标记下传
    void push_down(int x) {
        if(add[x]) {
            val[x] += add[x];
            add[lson] += add[x];
            add[rson] += add[x];
            sum[lson] += (LL)add[x]*sz[lson];
            sum[rson] += (LL)add[x]*sz[rson];
            add[x] = 0;
        }
    }
    
    void newnode(int &x, int c)  {
        x = ++top;
        lson = rson = 0;
        sz[x] = 1;
        val[x] = sum[x] = c;
        add[x] = 0;
    }

    void build(int &x, int l, int r, int f) {
        if(l > r)   return ;
        int mid = (l+r)/2;
        newnode(x, a[mid]);
        build(lson, l, mid-1, x);
        build(rson, mid+1, r, x);
        pre[x] = f;
        push_up(x);
    }

    void init(int n) {
        ch[0][0] = ch[0][1] = pre[0] = 0;
        top = root = 0;
        newnode(root, -1);
        newnode(ch[root][1], -1);
        // 为了方便处理边界，加两个边界顶点
        pre[top] = root;
        sz[root] = 2;

        for(int i = 0;i < n; i++)   scanf("%d", &a[i]);
        build(keytree, 0, n-1, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }

    void update(int l ,int r, int c) {
        RotateTo(l-1, 0);
        RotateTo(r+1, root);
        add[keytree] += c;
        sum[keytree] += (LL)c*sz[keytree];
    }

    LL query(int l, int r) {
        RotateTo(l-1, 0);
        RotateTo(r+1, root);
        return sum[keytree];
    }

}spt;

int main() {
    int n, m, l, r, c;
    char s[2];
    scanf("%d%d", &n, &m);
    spt.init(n);
    while(m--) {
        scanf("%s%d%d", s, &l, &r);
        if(s[0] == 'Q')
            printf("%I64d\n", spt.query(l, r));
        else {
            scanf("%d", &c);
            spt.update(l, r, c);
        }
    }
    return 0;
}


//指针版

#include <cstdio>

typedef __int64 ll;
#define lson x->ch[0]
#define rson x->ch[1]
#define ket (root->ch[1]->ch[0])

const int maxn = 100000+10;

struct NODE {
    NODE *ch[2], *pre;
    int add, val, id, sz;
    ll sum;
    void down() {
        if(add) {
            if(ch[0]->pre) {
                ch[0]->add += add;
                ch[0]->val += add;
                ch[0]->sum += (ll)add*ch[0]->sz;
            }
            if(ch[1]->pre) {
                ch[1]->add += add;
                ch[1]->val += add;
                ch[1]->sum += (ll)add*ch[1]->sz;
            }
            add = 0;
        }
    }

    void up() {
        sz = ch[0]->sz + ch[1]->sz + 1;
        sum = val + ch[0]->sum + ch[1]->sum;
    }
}node[maxn], *null = &node[0], *root;

struct SplayTree {
    int top;

    void Rotate(NODE *x, int c) {
        NODE *y = x->pre;
        y->down(); x->down();
        y->ch[!c] = x->ch[c];
        if(x->ch[c] != null) x->ch[c]->pre = y;
        x->pre = y->pre;
        if(y->pre != null)  y->pre->ch[ y->pre->ch[1] == y] = x;
        x->ch[c] = y; y->pre = x;
        y->up();
    }

    void Splay(NODE *x, NODE *go) {
        while(x->pre != go) {
            if(x->pre->pre == go)   Rotate(x, x->pre->ch[0] == x);
            else {
                NODE *y = x->pre, *z = y->pre;
                int f = z->ch[1] == y;
                if(y->ch[f] == x)   Rotate(y, !f);
                else    Rotate(x, f);
                Rotate(x, !f);
            }
        }
        x->up();
        if(go == null)  root = x;
    }

    void RTO(int k, NODE *go) {
        NODE *x = root;
        x->down();
        while(lson->sz != k) {
            if(lson->sz > k)    x = lson;
            else {
                k -= lson->sz + 1;
                x = rson;
            }
            x->down();
        }
        Splay(x, go);
    }

     void debug(NODE *x) {
        if(x != null) {
            printf("节点: %2d  左儿子: %2d 右儿子: %2d size = %2d val = %2d\n",
                x->id, x->ch[0]->id, x->ch[1]->id, x->sz, x->val);
            debug(x->ch[0]);
            debug(x->ch[1]);
        }
    }

    int a[maxn];

    NODE *newnode(NODE *f, int c) {
        NODE *x = &node[++top];
        x->id = top;
        x->val = x->sum = c;
        lson = rson = null;
        x->sz = 1; x->add = 0; x->pre = f;
        return x;
    }

    void build(NODE* &x, int l, int r, NODE *f) {
        if(l > r)   return ;
        int mid = (l+r)/2;
        x = newnode(f, a[mid]);
        build(lson, l, mid-1, x);
        build(rson, mid+1, r, x);
        x->up();
    }

    void init(int n) {
        null->id = 0;
        null->ch[0] = null->ch[1] = NULL;
        null->val = null->sum = null->add = null->sz=0;
        top = 0;
        root = newnode(null, -1);
        root->ch[1] = newnode(root, -1);

        for(int i = 0;i < n; i++)   scanf("%d", &a[i]);
        build(ket, 0, n-1, root->ch[1]);
        root->ch[1]->up(); root->up();
    }

    void update() {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        RTO(l-1, null);
        RTO(r+1, root);
        ket->add += c; ket->val += c;
        ket->sum += (ll)c*ket->sz;
    }

    void query() {
        int l, r;
        scanf("%d%d", &l, &r);
        RTO(l-1, null);
        RTO(r+1, root);
        printf("%I64d\n", ket->sum);
    }
}spt;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != -1) {
        spt.init(n);
        while(m--) {
            char op[2];
            scanf("%s", op);
            if(op[0] == 'Q')    spt.query();
            else    spt.update();
        }
    }
    return 0;
}
