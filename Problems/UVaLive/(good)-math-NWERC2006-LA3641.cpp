/*
 * Author:  Plumrain
 * Created Time:  2013-09-07 18:43
 * File Name: math-NWERC2006-LA3641.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define PB push_back

map<int, int> mp;
vector<int> ans;

void init()
{
    string s;
    s.clear();
    cin >> s;
    mp.clear();
    for (int j = 'A'; j <= 'Z'; ++ j)
        mp[j-'A'] = s[j-'A'] - 'A';
}

bool gao()
{
    ans.clear();
    for (int i = 0; i < 26; ++ i){
        if (mp[i] == -1 || mp[i] == i) continue;

        int tmp = mp[i], cnt = 1;
        mp[i] = -1;
        while (mp[tmp] != -1){
            cnt ++;
            int x = tmp;
            tmp = mp[tmp];
            mp[x] = -1;
        }
        if (!(cnt & 1)) ans.PB (cnt);
    }
     
    sort (ans.begin(), ans.end());
    if (ans.size () & 1) return false;
    for (int i = 0; i < ans.size(); i += 2)
        if (ans[i] != ans[i+1]) return false;
    return true;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init ();
        
        if (gao()) printf ("Yes\n");
        else printf ("No\n");
    }
    return 0;
}
