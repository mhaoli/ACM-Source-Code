#include<bits/stdc++.h>
const int N = 11111;
char s[N], stk[N];
int ans[N], stk2[N], cnt;
bool ok (char c){
    return c<'a' ? c-'A' == stk[cnt-1]-'a' : c-'a' == stk[cnt-1]-'A';
}
bool solve (char *s){
    cnt = 0;
    int t1 = 0, t2 = 0;
    while (s[0]){
        if (cnt && ok (s[0])){
            s[0]<'a' ? ans[t1++] = stk2[--cnt] : ans[stk2[--cnt]] = t2++;
        } else{
            stk[cnt] = s[0]; stk2[cnt++] = s[0]<'a' ? t1++ : t2++;
        }
        ++ s;
    }
    return !cnt;
}
int main(){
    int n; scanf ("%d", &n); 
    scanf ("%s", s);
    if (solve (s)) for (int i = 0; i < n; ++ i) printf ("%d%c", ans[i]+1, " \n"[i==n-1]);
    else puts ("Impossible");
    return 0;
}
