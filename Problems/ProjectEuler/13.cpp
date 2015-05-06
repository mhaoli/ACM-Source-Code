/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 13.cpp
 */
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int64;
vs v;
int main()
{
    int n = 100, m = 50;
    string sss;
    for (int i = 0; i < n; ++ i) cin >> sss, v.pb (sss);
    int tmp = 0;
    vi s;
    for (int i = m-1; i >= 0; -- i){ 
        int sum = tmp;
        for (int j = 0; j < n; ++ j) sum += v[j][i] - '0';
        tmp = sum / 10;
        s.pb (sum%10);
    }
    while (tmp){
        s.pb (tmp%10); tmp /= 10;
    }
    int sz = sz(s);
    for (int i = sz-1; i >= sz-10; -- i) cout << s[i];
    return 0;
}
