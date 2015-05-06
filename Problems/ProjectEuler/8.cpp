/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 8.cpp
 */
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef vector<string> vs;
string s;
int ok(int x)
{
    int ret = 1;
    for (int i = -4; i <= 0; ++ i)
        ret *= s[i+x] - '0';
    if (x == 4) out (ret);
    return ret;
}
int main()
{
    string t;
    while (cin >> t) s += t;
    int ans = 0;
    for (int i = 4; i < sz(s); ++ i) ans = max(ans, ok(i));
    out (ans);
    return 0;
}
