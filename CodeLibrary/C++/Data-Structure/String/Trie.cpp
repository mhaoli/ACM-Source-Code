/*
 * Author:  Plumrain
 * Created Time:  2014-03-11 22:32
 * File Name: Trie.cpp
 */

#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)

struct Trie{
    const static int maxn = 200000;
    const static int maxs = 26;
    
    int ch[maxn][maxs];      //nod
    int num[maxn];           //state
    int tot;

    int idx(char c){
        return c - 'a';
    }
    Trie(){
        tot = 1; num[0] = 0; clr (ch[0], 0);
    }
    void insert (char *s, int v){
        int n = strlen (s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (!ch[u][c]){
                clr (ch[tot], 0);
                num[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        num[u] = v;
    }
}
