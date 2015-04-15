#include<bits/stdc++.h>
char str[1111], s[1111];
int stk[1111], stk_top, fa[1111];
std::string name[1111];
int main(){
        scanf ("%s", str);
        int cnt = 0;
        for (int l = 0, r = strlen(str), top = 0; l < r; ++l){
                if (isalpha (str[l])){
                        s[top++] = str[l];
                } else{
                        if (top){
                                s[top] = 0;
                                name[cnt] = (std::string)s;
                                if (stk_top) fa[cnt] = stk[stk_top-1];
                                else fa[cnt] = -1;
                                stk[stk_top++] = cnt++;
                                top = 0;
                        }
                        if (str[l] == '.') stk_top--;
                }
        }
        //for (int i = 0; i < cnt; ++i)
                //std::cout << name[i] << " " << fa[i] << "\n";
        int ans = 0;
        for(int j, i = 0; i < cnt; ++i)
                for (j = fa[i]; j != -1; j = fa[j]) 
                        if (name[i] == name[j]) ++ans;
        printf("%d\n", ans);
        return 0;
}
