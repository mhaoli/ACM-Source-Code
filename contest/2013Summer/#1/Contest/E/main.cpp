//by iforgot
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

int main()
{
    freopen("a.in","r",stdin);
    int ans[15];
    memset(ans,0,sizeof(ans));
    int n,k;
    scanf( "%d%d" , &k , &n );
    out(k);
    out(n);
    int x = 2;
    for(int i = 0 ; i < n ; i ++ ){
        string s;
        cin >> s;
        cout << s << endl;
        int a = s[0] - '0';
        cout << a << endl;
        if( ans[a] == 0 ){
            ans[a] ++;
            x ++;
        }
        else if( ans[a] < k - 1 ){
            ans[a] ++;
        }
        else{
            ans[a] = 0;
        }
        out(ans[a]);
        out(x);
    }
    printf("%d\n" , x);
    return 0;
}
