//Kruskal算法求MST，返回MST的权值和，如果不联通返回-1
//时间复杂度O(m)

struct Pat{                 //表示边
    int s, e, w;            //s, e表示边的两个点，w为权值
};

int f[N];                   //并查集

int kruskal(int n, int m)       //n为点的数量，m为边的数量
{
    sort (p, p+m, cmp);
    for (int i = 0; i < n; ++ i)
        f[i] = i;
    
    int cost = 0;
    for (int i = 0; i < m; ++ i){
        int t1 = find(p[i].s), t2 = find(p[i].e);
        if (t1 != t2){
            cost += p[i].w;
            f[t1] = t2;
        }
    }

    int tmp;
    for (int i = 0; i < n; ++ i){
        if (!i) tmp = find(i);
        else if (tmp != find(i)) return -1;
    }
    return cost;
}
