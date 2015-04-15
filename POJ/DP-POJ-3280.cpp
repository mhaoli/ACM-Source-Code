/*
 * Author:  Plumrain
 * Created Time:  2013-11-17 21:44
 * File Name: DP-POJ-3280.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int maxint = 2147483647;

char s[3000];
int d[2005][2005];
map<char, int > mp;

int main()
{
    int n, len;
    while (scanf ("%d%d", &n, &len) != EOF){
        scanf ("%s", s);
        char x;
        int t1, t2;
        mp.clear();
        for (int i = 0; i < n; ++ i){
            x = 'P';
            while (!(x >= 'a' && x <= 'z')) scanf ("%c", &x);
            scanf ("%d%d", &t1, &t2);
            mp[x] = min(t1, t2);
        }
        
        CLR (d);
        for (int i = 0; i < len; ++ i)
            d[i][i] = 0;
        for (int i = len-2; i >= 0; -- i)
            for (int j = i+1; j < len; ++ j){
                if (s[i] == s[j]) d[i][j] = d[i+1][j-1];
                else
                    d[i][j] = min(maxint, min(d[i+1][j] + mp[s[i]], d[i][j-1] + mp[s[j]]));
            }
        printf ("%d\n", d[0][len-1]);
    }
    return 0;
}
