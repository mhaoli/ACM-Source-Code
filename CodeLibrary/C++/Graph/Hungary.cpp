/*
 * Author:  Plumrain
 * Algorithm: Hungary
 * Time: O(n*m)
 * Memory: O(m+n)
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())

bool v[1010];      //visited
int match[1010];   
vector<int> an[1010];   //graph

bool crosspath(int x){
    repf (i, 0, sz(an[x])-1){
        int p = an[x][i];
        if (!v[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath(match[p])){
                match[p] = x; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    int ret = 0;
    clr (match, -1);
    repf (i, 0, n-1){
        if (crosspath (i)) ++ ret;
        clr (v, 0);
    }
    return ret;
}
