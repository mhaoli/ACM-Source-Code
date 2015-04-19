/*
 * Author:  Plumrain
 * Created Time:  2013-10-14 20:49
 * File Name: math-POJ-2454.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
int n;
int t1[1000], t2[1000], t3[1000];
vector<pair<int, int> > a;
map<int, int> mp;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

void gao()
{
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++ i){
        s1 += mp[t1[i]];
        s2 += mp[t2[i]];
    }

    int tmp = 500 * n;
    while (s1 <= tmp || s2 <= tmp){
        int x1 = rand()%n, x2 = rand()%n;
        s1 += mp[t2[x2]] - mp[t1[x1]];
        s2 += mp[t1[x1]] - mp[t2[x2]];
        swap(t1[x1], t2[x2]);
    }
}

int main()
{
    while (scanf ("%d", &n) != EOF){    
        int tmp;
        for (int i = 0; i < 3*n; ++ i){
            scanf ("%d", &tmp);
            a.PB (make_pair(tmp, i));
            mp[i] = tmp;
        }
        sort(a.begin(), a.end(), cmp);

        CLR (t1); CLR (t2); CLR (t3);
        for (int i = 0; i < 3*n; ++ i){
            if (i < n) t1[i] = a[i].second;
            else if (i < 2*n) t2[i-n] = a[i].second;
            else t3[i-2*n] = a[i].second;
        }
        
        gao();

        for (int i = 0; i < n; ++ i)
            printf ("%d\n", t1[i]+1);
        for (int i = 0; i < n; ++ i)
            printf ("%d\n", t2[i]+1);
        for (int i = 0; i < n; ++ i)
            printf ("%d\n", t3[i]+1);
    }
    return 0;
}
