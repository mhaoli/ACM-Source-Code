#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)5e5;
struct nod{
    int l, r, x;
}q[N];
map<int, int> has, pos;
map<int, int>::iterator it;
vector<int> ans;
int cnt;
void add (int t1, int t2){
    ans.push_back (t1);
    ans.push_back (t2);
    ans.push_back (t1);
    ans.push_back (t2);
    has.clear (); pos.clear ();
    cnt = 0;
}
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0, t, l, r; i < n; ++ i){
        scanf ("%d", &t);
        ++ has[t];
        //printf ("%d %d\n", t, has[t]);
        if (has[t] == 4){ add (t, t); continue;}
        it = pos.find (t);
        if (it == pos.end()){ pos[t] = i; continue;}
        l = it->second; r = i;
        pos[t] = i;
        while (cnt){
            //printf ("%d %d %d %d\n", q[cnt-1].l, q[cnt-1].r, l, r);
            if (q[cnt-1].r <= l){
                q[cnt].l = l; q[cnt].r = r; q[cnt++].x = t; break;
            } else if (q[cnt-1].l <= l){
                add (q[cnt-1].x, t);
            } else --cnt;
        }
        if (!cnt){
            q[cnt].l = l; q[cnt].r = i; q[cnt++].x = t;
        }
    }
    printf ("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++ i)
        printf ("%d%c", ans[i], " \n"[i==ans.size()-1]);
    return 0;
}
