/*
 * Author:  Plumrain
 * Created Time:  2014-03-24 19:48
 * File Name: Aho-Corasick.cpp
 */

//Aho-Corasick
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

struct AC{
    const static int maxn = ;     //max_nod
    const static int maxs = ;     //max_sigma_size
    
    int ch[maxn][maxs];  //graph
    int val[maxn];       //nod
    int f[maxn];         //fail
    int last[maxn];      //suffix link
    int tot;
    
    int idx(char c){
        return c - 'a';    //a-z
    }
    void clear(){
        tot = 1; clr (ch[0], -1); val[0] = 0;
    }
    void insert (char *s, int v){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (ch[u][c] == -1){
                clr (ch[tot], -1);
                val[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    void fail(){
        queue<int> q;
        f[0] = last[0] = 0;
        repf (c, 0, maxs-1){
            int v = ch[0][c];
            if (v != -1) q.push (v), f[v] = last[v] = 0;
        }
        while (!q.empty()){
            int u = q.front(); q.pop();
            repf (c, 0, maxs-1){
                int v = ch[u][c];
                if (v == -1) continue;
                q.push (v);

                int r = f[u];
                while (r && ch[r][c] == -1) r = f[r];
                f[v] = ch[r][c] == -1 ? 0 : ch[r][c];
                last[v] = val[f[v]] ? f[v] : last[f[v]];
            }
        }
    }
};
