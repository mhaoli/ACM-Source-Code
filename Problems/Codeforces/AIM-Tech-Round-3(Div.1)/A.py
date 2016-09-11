def change (c):
    if c == 'a':
        return 'z'
    else:
        return chr(ord(c)-1)

s = list(input())
L = len(s)
flag = False
for i in range(L-1):
    if s[i] != 'a':
        flag = True
        while i < L:
            if s[i] == 'a':
                break
            s[i] = change(s[i])
            i = i + 1
        break
    
if not flag:
    s[L-1] = change(s[L-1])

print(''.join(s))
