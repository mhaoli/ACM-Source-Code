#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
using namespace std;
const int N = 9 + (int)1e4;
struct nod{
    int v;
    long long n;
    nod *pre, *nxt;
}memo[N], *bat, *head, *last, *Top;

int n;
map<int, nod*> has;
map<int, nod*>::iterator it;

nod *find_v (int v){
    it = has.find (v);
    if (it == has.end ()) return 0;
    return it->second;
}
nod *find_mx (){
    int mx = head->v;
    nod *ret = head;
    for (nod *p = head; p; p = p->nxt){
        if (p->v > mx) mx = p->v, ret = p;
    }
    return ret;
}
void MoveToTop (nod *p){
    if (p == head) return ;
    p->pre->nxt = p->nxt;
    if (p->nxt) p->nxt->pre = p->pre;
    else last = p->pre;
    p->nxt = head;
    p->pre = 0;
    head->pre = p;
    head = p;
    return ;
}

void Add (int x){
    nod *tmp = bat++;
    tmp->v = x; tmp->n = 0;
    tmp->pre = last;
    //printf ("last:%d %d\n", last->v, head->v);
    if (last) last->nxt = tmp;
    tmp->nxt = 0;
    last = tmp;
    if (!tmp->pre) head = tmp;

    ++ n;
    has[x] = tmp;
}

void Close (int x){
    nod *p = find_v (x);
    if (!p) puts ("invalid priority.");
    else{
        printf ("close %d with %I64d.\n", x, p->n);
        if (p == head){
            head = p->nxt;
            if (p->nxt) p->nxt->pre = 0;
            else last = p->pre;
        } else{
            p->pre->nxt = p->nxt;
            if (p->nxt) p->nxt->pre = p->pre;
            else last = p->pre;
        }

        -- n;
        if (p == Top) Top = 0;
        has.erase (x);
    }
}

void Chat (int x){
    if (!head) puts ("empty.");
    else{
        puts ("success.");
        if (Top){
            Top->n += x;
        } else{
            head->n += x;
        }
    }
}

void Rotate (int x){
    for (nod *p = head; p;p = p->nxt, -- x){
        if (x == 1){
            MoveToTop (p);
            return ;
        }
    }
}

void Bye (nod *x){
    printf ("Bye %d: %I64d\n", x->v, x->n);
}

void init (){
    bat = memo;
    has.clear ();
    Top = last = head = 0;
    n = 0;
}
char op[20];
int main(){
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int _; scanf ("%d", &_);
    while (_--){
        init ();
        int T; scanf ("%d", &T);
        for (int i = 1, t; i <= T; ++ i){
            printf ("Operation #%d: ", i);
            scanf ("%s", op);
            if (op[0] == 'A'){
                scanf ("%d", &t);
                if (has.find (t) != has.end ()) puts ("same priority.");
                else{
                    Add (t);
                    puts ("success.");
                }
            } else if (op[0] == 'C'){
                if (op[1] == 'l'){
                    scanf ("%d", &t);
                    Close (t);
                } else if (op[2] == 'a'){
                    scanf ("%d", &t);
                    Chat (t);
                } else{
                    scanf ("%d", &t);
                    it = has.find (t);
                    if (it == has.end ()) puts ("invalid priority.");
                    else MoveToTop (it->second), puts ("success.");
                }
            } else if (op[0] == 'R'){
                scanf ("%d", &t);
                if (t < 1 || t > n) puts ("out of range.");
                else Rotate (t), puts ("success.");
            } else if (op[0] == 'P'){
                if (!head) puts ("empty.");
                else MoveToTop (find_mx()), puts ("success.");
            } else if (op[0] == 'T'){
                scanf ("%d", &t);
                it = has.find (t);
                if (it == has.end ()) puts ("invalid priority.");
                else Top = it->second, puts ("success.");
            } else if (op[0] == 'U'){
                if (Top) Top = 0, puts ("success.");
                else puts ("no such person.");
            }
        }

        if (Top && Top->n > 0) Bye (Top);
        for (nod *p = head; p; p = p->nxt)
            if (p != Top && p->n > 0) Bye (p);
    }
    return 0;
}
