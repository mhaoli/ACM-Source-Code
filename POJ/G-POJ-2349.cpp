/*
 * Author:  Plumrain
 * Created Time:  2013-12-02 23:36
 * File Name: G-POJ-2349.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const double eps = 1e-8;
const int maxint = 1147483647;
typedef pair<int, double> pid;
struct pnt{double x, y;};

pnt p[505];
double d[505];
bool v[505];

struct cmp{
    bool operator() (pid a, pid b){
        return a.second > b.second + eps;
    }
};

bool cmp2(double x, double y)
{
    return x > y + eps;
}

double dis(pnt p1, pnt p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void init(int& s, int& n)
{
    scanf ("%d%d", &s, &n);
    for (int i = 0; i < n; ++ i)
        scanf ("%lf%lf", &p[i].x, &p[i].y);
}

double prim(int n, int s)
{
    vector<double> ret; ret.clear();
    priority_queue<pid, vector<pid>, cmp> q;
    while (!q.empty()) q.pop();

    CLR (v);
    v[0] = 1; d[0] = 0;
    for (int i = 1; i < n; ++ i){
        d[i] = dis(p[i], p[0]);
        pid tmp;
        tmp.first = i; tmp.second = d[i];
        q.push (tmp);
    }

    for (int i = 0; i < n-1; ++ i){
        if (q.empty()) break;
        pid t = q.top(); q.pop();
        while (v[t.first] && !q.empty()){
            t = q.top(); q.pop();
        }
        if (v[t.first]) break;

        v[t.first] = 1; ret.PB (t.second);
        for (int j = 1; j < n; ++ j) if (!v[j]){
            double tmp = dis(p[t.first], p[j]);
            if (tmp < d[j]){
                d[j] = tmp;
                pid x;
                x.first = j; x.second = tmp;
                q.push (x);
            }
        }
    }

    sort(ret.begin(), ret.end(), cmp2);
    return ret[s-1];
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        int s, n;
        init(s, n);
        double ans = prim(n, s);
        printf ("%.2f\n", ans);
    }
    return 0;
}
