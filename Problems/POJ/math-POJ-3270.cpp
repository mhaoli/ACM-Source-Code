/*
 * Author:  Plumrain
 * Created Time:  2013-10-01 18:49
 * File Name: math-POJ-3270.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back

const int maxint = 2147483647;
const int N = 10000;

typedef long long int64;

bool fla[N+5];
int pat[N+5];
int64 all_min;
vector<pair<int64, int> > num;

int64 min(int64 a, int64 b)
{
    return a < b ? a : b;
}

int64 gao(int64 n)
{
    CLR (fla);
    int64 ret = 0;
    for (int i = 0; i < n; ++ i) if (!fla[i]){
        int64 mi = maxint, sum = 0;
        int cnt = 0, pos = i;
        while (!fla[pos]){ 
            ++ cnt; sum += num[pos].first;
            mi = min(mi, num[pos].first);
            fla[pos] = 1;
            pos = pat[pos];
        }
        if (cnt >= 2){
            int64 tmp = (int64)(cnt-2) * mi + sum;
            tmp = min(sum + (int64)(cnt+1) * all_min + mi, tmp);
            ret += tmp;
        }
    }
    return ret;
}

bool cmp(pair<int64, int> a, pair<int64, int> b)
{
    return a.first < b.first;
}

int main()
{
    int64 n;
    while (scanf ("%lld", &n) != EOF){
        int64 tmp;
        num.clear();
        for (int i = 0; i < n; ++ i){
            scanf ("%lld", &tmp);
            pair<int64, int> p = make_pair(tmp, i);
            num.PB(p);
        }
         
        sort(num.begin(), num.end(), cmp);
        all_min = num[0].first;
        CLR (pat);
        for (int i = 0; i < n; ++ i)
            pat[i] = num[i].second;

        printf ("%lld\n", gao(n));
    }
    return 0;
}




