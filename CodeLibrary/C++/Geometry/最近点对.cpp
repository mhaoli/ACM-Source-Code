/*
 * Author:  Plumrain
 * Created Time:  2014/9/29 1:05:37
 * File Name: 最近点对.cpp
 */
const int N = ;
//use : gao::solve()
namespace gao{
    int b[N];
    Pnt *a;
    bool cmp_y (int x, int y){
        return a[x].y < a[y].y;
    }
    bool cmp_x (Pnt a, Pnt b){
        return a.x < b.x;
    }
    long long dfs (int l, int r){
        if (l == r) return (long long)(9e18);
        if (l == r - 1) return dis (a[l], a[l+1]);

        int mid = (l + r) >> 1;
        long long mi = dfs (l, mid), tmi = dfs (mid+1, r);
        if (tmi < mi) mi = tmi;
        int tl, tr;
        for (tl = mid; tl > l && a[mid].x - a[tl-1].x < mi; -- tl);
        for (tr = mid; tr < r && a[tr+1].x - a[mid].x < mi; ++ tr);

        int top = 0;
        for (int i = tl; i <= tr; ++ i) b[top++] = i;
        sort (b, b + top, cmp_y);
        for (int i = 0; i < top; ++ i)
            for (int j = i+1; j < min (i+8,top); ++ j){
                long long tmp = dis (a[b[i]], a[b[j]]);
                if (tmp < mi) mi = tmp;
            }
        return mi;
    }
    long long solve (int n, Pnt *t){
        a = t;
        sort (a, a + n, cmp_x);
        return dfs (0, n-1);
    }
}
