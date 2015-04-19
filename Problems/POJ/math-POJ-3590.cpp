/*
 * Author:  Plumrain
 * Created Time:  2013-10-21 23:44
 * File Name: math-POJ-3590.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int N = 100;
typedef vector<int> VI;
typedef long long int64;

int64 ans = 0;
int prm[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
VI cur, tmp;

void dp(int n, int sum, int l)
{
    if (l > ans){ 
        ans = l;
        cur = tmp;
        for (int i = 0; i < sum; ++ i)
            cur.PB (1);
    }

    for (int i = n+1; prm[i] <= sum; ++ i){
        int xxx = prm[i];
        while (xxx <= sum){
            tmp.PB (xxx);
            dp(i, sum-xxx, xxx*l);
            tmp.pop_back();
            xxx *= prm[i];
        }
    }
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);

        if (n == 1){
            printf ("1 1\n");
            continue;
        }
        
        cur.clear(); ans = 0;
        for (int i = 0; prm[i] <= n; ++ i){
            int xxx = prm[i];
            while (xxx <= n){
                tmp.clear();
                tmp.PB (xxx);
                dp(i, n-xxx, xxx);
                xxx *= prm[i];     
            }
        }

        int64 mul = 1;
        for (int i = 0; i < cur.size(); ++ i)
            mul *= cur[i];
        printf ("%lld", mul);
        sort(cur.begin(), cur.end());
        int idx = 0;
        for (int i = 0; i < cur.size(); ++ i){
            for (int j = 1; j < cur[i]; ++ j)
                printf (" %d", idx+1+j);
            printf (" %d", idx+1);
            idx += cur[i];
        }
        printf ("\n");
    }
    return 0;
}
