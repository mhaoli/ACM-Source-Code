void euler (int u){
    for (int v = 0; v < n; ++ v) if (G[u][v] && !vis[u][v]){
        vis[u][v] = vis[v][u] = 1;
        euler (v);
        printf ("%d %d\n", u, v);
    }
}
