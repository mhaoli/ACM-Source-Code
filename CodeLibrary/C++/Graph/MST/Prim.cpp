//Prim算法求MST，返回MST的权值和，如果图不联通返回-1
//时间复杂度O(n*n)
//这代码是用优先队列priority_queue写的，其实用set来写会快一些。

typedef pair<int, int> pii;
const int N = ;                         //N表示节点数

int c[N];                               //c[i]表示i点目前到已选出的点中最短边的权值
bool v[N];                              //v[i] = 0表示i点目前还没有被选出
vector<pii> p[N];                       //p[i]表示一点为i的边，另一点为p[i][j].first，该边权值为p[i][j].second

int prim(int n, int m)                  //n为节点数，m为边数
{
    int cost = 0;
    CLR (v);
    priority_queue<pii, vector<pii>, cmp> q;
    while (!q.empty()) q.pop();

    for (int i = 1; i < n; ++ i)
        c[i] = maxint - 1000;
    c[0] = 0;
    v[0] = 1;
    for (int i = 0; i < (int)p[0].size(); ++ i){
        pii tmp = p[0][i];
        c[tmp.first] = tmp.second;
        q.push (make_pair(tmp.first, tmp.second));
    }

    for (int i = 0; i < n-1; ++ i){
        if (q.empty()) break;
        pii tmp = q.top(); q.pop();
        while (v[tmp.first] && !q.empty()){
            tmp = q.top(); q.pop();
        }
        if (v[tmp.first]) break;

        int t1 = tmp.first, t2 = tmp.second;
        cost += t2;
        v[t1] = 1;
        c[t1] = 0;
        for (int j = 0; j < (int)p[t1].size(); ++ j) if (!v[p[t1][j].first]){
            pii t = p[t1][j];
            if (c[t.first] > t.second){
                q.push (make_pair(t.first, t.second));
                c[t.first] = t.second;
            }
        }
    }

    for (int i = 0; i < n; ++ i)
        if (!v[i]) return -1;
    return cost;
}
