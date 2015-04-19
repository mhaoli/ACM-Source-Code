/*
 * Author:  Plumrain
 * Created Time:  2014/6/9 15:00:29
 * File Name: mobius_init.cpp
 * Time: O(n)
 */
#include <cstring>
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
const int maxn = ;
int prm[maxn], mo[maxn];
bool check[maxn];

void mobius_init(int n){
    clr (check, 0); mo[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i, mo[i] = -1;
        for (int j = 0; j < tot; ++ j){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0){
                mo[i*prm[j]] = 0; break;
            }
            else mo[i*prm[j]] = -mo[i];
        }
    }
}
