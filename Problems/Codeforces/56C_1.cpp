#include<bits/stdc++.h>
int R, l, ans, cnt;
char str[1111], s[1111];
std::map<std::string, int> has;
void dfs (){
        if (l >= R) return;
        int top = 0;
        while (l < R && isalpha (str[l])) s[top++] = str[l++];
        s[top] = 0;
        std::string tmp = (std::string)s;
        ans += has[tmp];
        has[tmp]++;

        while (l < R && str[l] != '.'){
                ++l;
                dfs ();
        }
        ++l;
        has[tmp]--;
}
int main(){
        scanf ("%s", str);
        R = strlen (str);
        dfs ();
        printf ("%d\n", ans);
        return 0;
}
