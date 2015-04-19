#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)1e5;
struct nod{
    int x, y, id;
    bool operator<(const nod &t)const{
        return x == t.x ? y < t.y : x < t.x;
    }
};
int ans[N];
nod a[N<<1];
pair<int, int> b[N];
int main(){
    int n;
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i){
            scanf ("%d%d", &a[i<<1].x, &a[i<<1|1].x);
            -- a[i<<1|1].x;
            a[i<<1].y = -1; a[i<<1|1].y = 1;
            a[i<<1].id = a[i<<1|1].id = i;
        }
        memset (ans, 0, sizeof ans);
        sort (a, a + (n<<1));
        int cnt = 1;
        for (int i = 0; i < (n<<1); ++ i){
            //printf ("%d %d %d\n", a[i].x, a[i].y, a[i].id);
            if (a[i].y == -1){
                //printf ("i:%d\n", i);
                ans[a[i].id] = cnt;
            } else if (ans[a[i].id] == cnt){
                //printf ("i---:%d\n", i);
                ++ cnt;
            }
        }
        //for (int i = 0; i < n; ++ i)
            //printf ("%d %d\n", i, ans[i]);
        printf ("%d\n", cnt-1);
        for (int i = 0; i < n; ++ i)
            b[i].first = ans[i], b[i].second = i+1;
        sort (b, b + n);
        for (int i = 0; i < n; ++ i){
            if (i && b[i].first != b[i-1].first) puts ("");
            else if (i) printf (" ");
            printf ("%d", b[i].second);
        }
        puts (""); puts (""); 
    }
    return 0;
}
