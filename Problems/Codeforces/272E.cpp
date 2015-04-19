#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int N = 9 + (int)3e5;
std::vector<int> E[N];
char ans[N];
bool bad (int u){
        int cnt = 0;
        snuke (it, E[u]){
                if (ans[*it] == ans[u]) ++cnt;
        }
        return cnt > 1;
}
int main(){
        int n, m;
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) ans[i] = '0';
        ans[n] = 0;

        for (int i = 0, u, v; i < m; ++i){
                scanf ("%d%d", &u, &v);
                E[--u].push_back (--v);
                E[v].push_back (u);
        }
        std::queue<int> q;
        for (int i = 0; i < n; ++i) if (bad (i)) q.push (i);
        for (int x; !q.empty(); ){
                x = q.front ();
                q.pop();
                if (bad (x)){
                        ans[x] = ans[x] == '1' ? '0' : '1';
                        snuke (it, E[x]) if (bad (*it)) q.push (*it);
                }
        }
        puts (ans);
        return 0;
}
